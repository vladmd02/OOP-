#include"functions_simple_example_of_inheritance.cpp"

//=======================================================================================================================================
// Простой пример наследования -

int main () {
	setlocale(LC_ALL, "Russian"); 
	
	// инициализация объектов с помощью конструктора с 4 параметрами 
	Preschool_educational_institution a ("one"  , 2 , 200 , 1 , 23 );         // Поля :  string name ; int number_of_students ; int price_per_contract ; bool budget_place ; int groops
	Secondary_educational_institution b ("two"  , 3 , 300 , 0 , 21.1 );       // Поля :  string name ; int number_of_students ; int price_per_contract ; bool budget_place ; float average_score
	Higher_education_institution      c ("three", 4 , 400 , 1 , "address" );  // Поля :  string name ; int number_of_students ; int price_per_contract ; bool budget_place ; string address
	
	// инициализация объектов с помощью конструктора по умолчанию
	Preschool_educational_institution d ; 
	Secondary_educational_institution e ; 
	Higher_education_institution      f ;
	
	// инициализация объектов с помощью конструктора копирования
	Preschool_educational_institution g(a); 
	Secondary_educational_institution h(b) ; 
	Higher_education_institution      i(c) ;
	
	// ввод данных с помощью оператор >> 
	cout << endl << " Ввведите пожалуйста данные объекта ' a ' , типа - Preschool_educational_institution        : " << endl ;
	cin >> a;
	cout << endl << " Ввведите пожалуйста данные объекта ' b ' , типа - Secondary_educational_institution        : " << endl ;
	cin >> b;
	cout << endl << " Ввведите пожалуйста данные объекта ' c ' , типа - Higher_education_institution             : " << endl ;
	cin >> c;
	
	// Вывод объектов на экран , с помощью операторв <<
	cout << endl << "Вывод объектов на экран - " << endl;
	cout << endl << " Данные объекта ' a ' , типа - Preschool_educational_institution        : " << endl ;
	cout << a;
	cout << endl << " Данные объекта ' b ' , типа - Secondary_educational_institution         : " << endl ;
	cout << b;
	cout << endl << " Данные объекта ' c ' , типа - Higher_education_institution              : " << endl ;
	cout << c;
	
	// Работа оператора присваивания 
	cout << endl << "Объекту ' d ' присвоить объект ' a ', типа - Preschool_educational_institution " << endl << endl;
	cout << " Объект a : " << a << endl;
	cout << " Объект d : " << d ;
	cout << endl << "Резульат присваиваания - "  << endl << endl;
	// Присваивание
	d = a; 
	// Вывод новых значений
	cout << " Объект a : " << a << endl;
	cout << " Объект d : " << d ;
	
	// Функция установки / изменения данных
	cout << endl << "Устанавливаем данные для объекта ' a ' , типа - Preschool_educational_institution    : " << endl ;
	a.Set();
	cout << endl << "Устанавливаем данные для объекта ' b ' , типа - Secondary_educational_institution      : " << endl ;
	b.Set();
	cout << endl << "Устанавливаем данные для объекта ' с ' , типа - Higher_education_institution : " << endl;
	c.Set();
	
	// Вывод после использования метода Set
	cout << endl << "Вывод объектов на экран - " << endl;
	cout << endl << " Данные объекта ' a ' , типа - Preschool_educational_institution        : " << endl ;
	cout << a;
	cout << endl << " Данные объекта ' b ' , типа - Secondary_educational_institution         : " << endl ;
	cout << b;
	cout << endl << " Данные объекта ' c ' , типа - Higher_education_institution              : " << endl ;
	cout << c;
	return 0;
}
