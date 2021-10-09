#include"functions_string_class_implementation.cpp" 

int main() {
	setlocale(LC_ALL, "Russian");
	
	cout << " \t\t Что умеет этот класс ? : " << endl << endl;
	
	cout << " 1) Создание объектов - " << endl;
	MyString str ("First object");
	MyString str2("Second object");
	MyString str3("object");
	MyString str4; // так же можем создать просто пустой объект , как в std::string
	
	cout << " - MyString str  ( 'First object'  )  :   "<< str << endl;
	cout << " - MyString str2 ( 'Second object' )  :   "<< str2 << endl;
	cout << " - MyString str3 ( 'object'        )  :   "<< str3 << endl << endl;
	
	cout << " 2) Определение размера строк - " << endl;
	cout << " - MyString str  ( 'First object'  )  :   "<< str.Mylength() << endl;
	cout << " - MyString str2 ( 'Second object' )  :   "<< str2.Mylength() << endl;
	cout << " - MyString str3 ( 'object'        )  :   "<< str3.Mylength() << endl << endl;
	
	cout << " 3) Конкатенация строк str , str2 и str3 - " << endl;
	MyString result = str + str2 + str3;
	cout << " - Результат : ( 'MyString result' )  :   " << result << endl << endl ;
	
	cout << " 4) Поиск объекта str3 ( 'object' ) в объекте str ( 'First object' ) - " << endl;
	cout << " - Результат : " ;
	KMP(str, str3 );
	cout << endl ;

	cout << " 5) Проверка на равенство :   " << endl ;
	bool equal = str == str2; // так же можем проверить на неравенство с помощью оператора !=
	cout << " - Результат : " << equal << endl << endl ;
	
	cout << " 6) Пример работы оператора индексирования - " << endl;
	cout << " - Нулевой элемент объекта str ( 'First object' )  = " <<" [ " << str [0] << " ] " << endl;
	cout << " - Нулевой элемент объекта str2( 'Second object' ) = " <<" [ " << str2[0] << " ] "<< endl;
	cout << " - Нулевой элемент объекта str3( 'object       ' ) = " <<" [ " << str3[0] << " ] "<< endl << endl;
	
	cout << " 7) Пример работы оператора индексирования ( const )- " << endl;
	const MyString str5 ("hello");
	cout << " - Нулевой элемент объекта const str5 ('hello')    = " <<" [ " << str5[0] << " ] " << endl << endl;
	
	cout << " 8) Изменения значения символа по индексу"<< endl;
	cout << " -  Измененим в объекте str ( 'First object' ) первую букву на [ A ] " << endl;
	str[0] = 'A';
	cout << " -  Рузультат :   " << str << endl<< endl;
	
	cout << " 9) Пример работы оператора присваивания " << endl;
	cout << " Присвоим объекту str , значения объекта str2 " << endl;
	cout << " - MyString str  ( 'Airst object'  )  :   "<< str  << endl;
	cout << " - MyString str2 ( 'Second object' )  :   "<< str2 << endl << endl;
	str = str2;
	cout << " - Рузультат :   " << endl;
	cout << " - MyString str  ( 'Second object' )  :   " << str  << endl;
	cout << " - MyString str2 ( 'Second object' )  :   " << str2 << endl;
	
	return 0;
}
