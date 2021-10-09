#include"functions_example_of_using_virtual_functions.cpp"

//=======================================================================================================================================
// Простой пример переопределения виртуальных функций -

int main () {
	setlocale(LC_ALL, "Russian"); 

	// инициализация объектов с помощью конструктора с 4 параметрами 
	Parallelepiped 		a ( 1.1  , 1.1 , 1.1 );  // Поля :  double x , double y , double z
	Tetrahedron 		b ( 2.2 );        		 // Поля :  double a 
	Sphere  			c ( 3.3 );   			 // Поля :  double r
	
	// инициализация объектов с помощью конструктора по умолчанию
	Parallelepiped 		d ; 
	Tetrahedron 		e ; 
	Sphere 				f ;
	
	// инициализация объектов с помощью конструктора копирования
	Parallelepiped 		g (a); 
	Tetrahedron 		h (b) ; 
	Sphere		    	i (c) ;
	
	// ввод данных с помощью оператор >> 
	cout << endl << " Ввведите пожалуйста данные объекта ' a ' , типа - Parallelepiped    : " << endl ;
	cin >> a;
	cout << endl << " Ввведите пожалуйста данные объекта ' b ' , типа - Tetrahedron       : " << endl ;
	cin >> b;
	cout << endl << " Ввведите пожалуйста данные объекта ' c ' , типа - Sphere    		  : " << endl ;
	cin >> c;
	
	// Нахождение площади оъектов 
	cout << endl << " Площадь объекта ' a ' , типа - Parallelepiped    : " << endl ;
	a.Square();
	cout << endl << " Площадь объекта ' b ' , типа - Tetrahedron      : " << endl ;
	b.Square();
	cout << endl << " Площадь объекта ' с ' , типа - Sphere : " << endl;
	c.Square();
	
	// Вывод объектов на экран , с помощью операторв <<
	cout << endl << "Вывод объектов на экран - " << endl;
	cout << endl << " Данные объекта ' a ' , типа - Parallelepiped      : " << endl ;
	cout << a;
	cout << endl << " Данные объекта ' b ' , типа - Tetrahedron         : " << endl ;
	cout << b;
	cout << endl << " Данные объекта ' c ' , типа - Sphere    			: " << endl ;
	cout << c;
	
	// Работа оператора присваивания 
	cout << endl << "Объекту d присвоить объект a , типа - Parallelepiped " << endl << endl;
	cout << " Объект a : " << a << endl;
	cout << " Объект d : " << d ;
	cout << endl << "Резульат присваиваания - "  << endl << endl;
	// Присваивание
	d = a; 
	// Вывод новых значений
	cout << " Объект a : " << a << endl;
	cout << " Объект d : " << d ;
	
	// Функция установки / изменения данных
	cout << endl << "Устанавливаем данные для объекта ' a ' , типа - Parallelepiped    : " << endl ;
	a.Set();
	cout << endl << "Устанавливаем данные для объекта ' b ' , типа - Tetrahedron      : " << endl ;
	b.Set();
	cout << endl << "Устанавливаем данные для объекта ' с ' , типа - Sphere : " << endl;
	c.Set();
	
	// Вывод после использования метода Set
	cout << endl << "Вывод объектов на экран - " << endl;
	cout << endl << " Данные объекта ' a ' , типа - Parallelepiped       : " << endl ;
	cout << a;
	cout << endl << " Данные объекта ' b ' , типа - Tetrahedron         : " << endl ;
	cout << b;
	cout << endl << " Данные объекта ' c ' , типа - Sphere    : " << endl ;
	cout << c;	

	// Вызов оператора =
	cout << endl << " Проверка на равенство / неравенство  - " << endl;
	cout << " Вызываем оператор == для сравнения объектов ' c ' и ' i ' , класса Sphere "<< endl;
	bool equal = c == i;
	cout << " - Результат : " << equal << endl;

	return 0;
}
