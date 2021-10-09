// Вариант 8 :
//а) Создать класс String - строка, используя динамическую память.
// Определить конструкторы: по умолчанию, копий и с параметром - указателем на строку типа char. 
// Определить функции присваивания одной строки другой, сравнения, поиска подстроки, количества символов и др.
#include <iostream>
#include <string.h>
using std::cout; 
using std::endl;
using std::ostream;

class MyString {
	
	char *str; // тут указтаель , так как фиксированый размер строки мы не знаем , соответсвенно нужно будет харнить её в динамической памяти 
	int length; // объявим переменную для хранения длины строки , чтобы не писать метод length , и не бежать по массиву заново для подсчета всех элементов 
	
public:

	// конструкторы / деструкторы 
	MyString() ; // ctor по умолчанию , например , чтобы при создании объекта не сразу присваивать ему значение
	MyString ( const char *str ) ;  // сtor , при вызове , котрого , нам необходимо передать параметром указатель на строку , которую он будет хранить 
	MyString ( const MyString &other  ) ;  // ctor копирования 
   	MyString ( MyString &&other  ) ; // ctor перемещения 
	~MyString() { delete [] str; }  // деструктор 
	
	// операторы / методы класса
	MyString & operator = (const MyString &other ) ; //  оператор присваивания для MyString  - тут почти всё тоже самое , что и в конструкторе копирования 
	MyString & operator = ( const char *s ) ; // оператор присваивания , который работает со строками в стиле С
	MyString operator + ( const MyString &other ) ; // перегруженый оператор + , для конкатенации строк 
	int Mylength () { return length; } // метод , который возвращает длину строки 
	
	// операторы равенства - нервенства . Их я не стал выносить из header , так как там только одна строка.
	bool operator == (const MyString &other ) { return (strcmp(other.str , str) == 0); } // оператор ==
	bool operator != (const MyString &other ) { return !( operator ==(other)); }  // возвращаем инвертированый результат оператора =
	
	// операторы индексирования 
	char & operator [] (int index) { return str[index]; } // оператор [] , чтобы мы могли получать значения символа по индеку в массиве
	const char & operator [] ( int index ) const {return str [index] ;} // тут тоже самое , только работает с const 
	
	// дружественные функции больше / меньше 
	friend bool operator < ( const MyString & st1 , const MyString & st2 );
	friend bool operator > ( const MyString & st1 , const MyString & st2 );
	
	// дружественные функции 
	friend void KMP(MyString X, MyString Y); // поиск подстроки 
	friend ostream& operator << ( ostream& os , const MyString & mystring ); // оператор << 
};

