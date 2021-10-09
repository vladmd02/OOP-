#include"header_string_class_implementation.h"
	
MyString::MyString() { // ctor по умолчанию , например , чтобы при создании объекта не сразу присваивать ему значение
		//length = 4;
		length = 0;
		str = new char[1];
		str[0] = '\0';
	}

MyString::MyString (  const char *st ) { // сtor , при вызове , котрого , нам необходимо передать параметром указатель на строку , которую он будет хранить 
		length = strlen(st); 
		str = new char [length + 1]; // с помощью поля класса , создаем новую строку 
		strcpy(str , st);
	}
	
MyString::MyString ( const MyString &other  ) { // ctor копирования 
   	
	length = other.length;
	str = new char[ length+1 ]; // выделяем новую область памяти , чтобы не произошло удаление уже удаленной памяти 
	strcpy(str , other.str);
	}
	
MyString::MyString ( MyString &&other  ) { // сtor перемещения - этот конструтор нужен нам для того , чтобы возвращать значения конкатенации , без перезаписи и выделения памяти 
		length = other.length; // текущему объекту присваиваем значение длины объекта other 
		str = other.str; // теперь текущий объект и объект other указывают на одну и ту же область памяти 
		other.str = nullptr; // присваем указателю объекта other - nullptr , чтобы оператор delete[] - не мог стереть из него данные 
	}	// в результате , после конкатенации мы получаем наш объект , без повтороного выделния памяти , и лишнего копированрия , а просто с помощью переноса значений из одного объекта в другой 
	
//присвоить строку С объекту String
MyString & MyString :: operator= ( const char * s ) {
	delete [] str ;
	length = strlen ( s ) ;
	str = new char [ length + 1 ] ;
	strcpy ( str , s ) ;
	return * this ; 
}

MyString & MyString::operator = (const MyString &other ) { //  оператор присваивания - тут почти всё тоже самое , что и в конструкторе копирования 
	if(this == &other)
		return *this;
	delete [] str;
	length = other.length; 
	str = new char[length + 1]; 
	strcpy(str , other.str);
	return *this; // возврашаем разименовый указатель на сам объект
	} 

ostream& operator << ( ostream& os , const MyString & mystring ) { // функция принимает объекты класса и ostream и iostream , так как ссылка на базовый класс , может хранить адресса своих наследников 
	os << mystring.str ;	
	return os; 
	}
	
MyString MyString::operator + ( const MyString &other ) { // { // перегруженый оператор + , для конкатенации строк 
		MyString newStr; // новый объект , который вернёт наша функция , как результат работы метода 
		
		int thisLength = this->length;
		int otherLength = other.length;
		newStr.length = thisLength + otherLength; // вычесляем длину новой строки
		newStr.str = new char [ thisLength + otherLength + 1 ]; // выделяем память по новую строку
		
		int i = 0; // тут нам нужно вынести итератор вне цикла , чтобы при записи второго слова в нашу строку - произошло добавление , а не перезапись слова 
		for ( ; i< thisLength ; i++ ) {
			newStr.str[i] = str[i]; // записываем первое слово 
		}
		for (int j = 0 ; j<otherLength ; j++ , i++ ) {
			newStr.str[i] = other.str[j]; // а тут второе  
		}
		newStr.str[thisLength + otherLength] = '\0'; // если я не закроб строку , то происходит выход за границы :(
		
		return newStr; // возврашаем наш новый объект
	}	
	
void KMP(MyString X, MyString Y) //  для поиска подстроки 
{
    int m = X.length;
    int n = Y.length;
	// если Y пустая строка 
    if (n == 0)
    {
        cout << "Образец начинается с нулевого символа строки";
        return;
    }
 
    // если длина X меньше длины Y
    if (m < n)
    {
        cout << "Образец не найден ";
        return;
    }
    // next[i] хранит индекс следующего наилучшего совпадения 
    int next[n + 1];
    
    for (int i = 0; i < n + 1; i++) {
        next[i] = 0;
    }
 
    for (int i = 1; i < n; i++)
    {
        int j = next[i + 1];
 
        while (j > 0 && Y[j] != Y[i]) {
            j = next[j];
        }
 
        if (j > 0 || Y[j] == Y[i]) {
            next[i + 1] = j + 1;
        }
    }
 
    for (int i = 0, j = 0; i < m; i++)
    {
        if (X[i] == Y[j])
        {
            if (++j == n) {
                cout << "Образец начинается с " << i - j + 1 << " символа строки" << endl;
            }
        }
        else if (j > 0)
        {
            j = next[j];
            i--;    
        }
    }
}

bool operator < ( const MyString & st1 , const MyString & st2 ) { return (strcmp ( st1.str , st2.str ) < 0) ;} 
bool operator > ( const MyString & st1 , const MyString & st2 ) { return st2.str < st1.str;  } /*return st2.str < this->str ;*/
