#include"Functions_diamond_inheritance_example.cpp"

//=======================================================================================================================================
// Простой пример работы ромбовидного наследования -

int main () {
	setlocale(LC_ALL, "Russian"); 

	// инициализация объектов с помощью конструктора , который принимает n-ое колличесвто параметров 
	Object 			z ( 0, 0, 0);								 // Поля : 	int x , int y , int z.
	Fishing_rod 	a ( 1, 1, 1 ,1.1 , 1.1 , 1.1 );              // Поля : 	int x , int y , int z , float length ,	float weight,	float price.
	Telescope 		b ( 2, 2, 2, 2.2 );        				     // Поля : 	int x , int y , int z , float diameter.
	Telescopic_rod  c ( 3, 3, 3, 3.3 , 3.3 , 3.3 , 3.3 , 3.3 );  // Поля : 	int x , int y , int z , float length ,	float weight ,	float price ,   float diameter ,   float strength.
	
	// инициализация объектов с помощью конструктора по умолчанию
	Object 			w ;
	Fishing_rod 	d ; 
	Telescope 		e ; 
	Telescopic_rod 	f ;
	
	// инициализация объектов с помощью конструктора копирования
	Object 			x (z);
	Fishing_rod 	g (a); 
	Telescope 		h (b) ; 
	Telescopic_rod  i (c) ;
	
	// ввод данных с помощью оператор >> 
	cout << endl << " Ввведите пожалуйста данные объекта ' z ' , типа - Object       : " << endl ;
	cin >> z;
	cout << endl << " Ввведите пожалуйста данные объекта ' a ' , типа - Fishing_rod       : " << endl ;
	cin >> a;
	cout << endl << " Ввведите пожалуйста данные объекта ' b ' , типа - Telescope         : " << endl ;
	cin >> b;
	cout << endl << " Ввведите пожалуйста данные объекта ' c ' , типа - Telescopic_rod    : " << endl ;
	cin >> c;
	
	// Вывод объектов на экран , с помощью операторв <<
	cout << endl << "Вывод объектов на экран - " << endl;
	cout << endl << " Данные объекта ' z ' , типа - Object       : " << endl ;
	cout << z;
	cout << endl << " Данные объекта ' a ' , типа - Fishing_rod       : " << endl ;
	cout << a;
	cout << endl << " Данные объекта ' b ' , типа - Telescope         : " << endl ;
	cout << b;
	cout << endl << " Данные объекта ' c ' , типа - Telescopic_rod    : " << endl ;
	cout << c;
	
	// Работа оператора присваивания 
	cout << endl << "Объекту d присвоить объект a , типа - Fishing_rod " << endl << endl;
	cout << " Объект a : " << a << endl;
	cout << " Объект d : " << d ;
	cout << endl << "Резульат присваиваания - "  << endl << endl;
	// Присваивание
	d = a; 
	// Вывод новых значений
	cout << " Объект a : " << a << endl;
	cout << " Объект d : " << d ;
	
	// Функция установки / изменения данных
	cout << endl << "Устанавливаем данные для объекта ' z ' , типа - Object    : " << endl ;
	z.Set();
	cout << endl << "Устанавливаем данные для объекта ' a ' , типа - Fishing_rod    : " << endl ;
	a.Set();
	cout << endl << "Устанавливаем данные для объекта ' b ' , типа - Telescope      : " << endl ;
	b.Set();
	cout << endl << "Устанавливаем данные для объекта ' с ' , типа - Telescopic_rod : " << endl;
	c.Set();
	
	// Вывод после использования метода Set
	cout << endl << "Вывод объектов на экран - " << endl;
	cout << endl << " Данные объекта ' z ' , типа - Object            : " << endl ;
	cout << z;
	cout << endl << " Данные объекта ' a ' , типа - Fishing_rod       : " << endl ;
	cout << a;
	cout << endl << " Данные объекта ' b ' , типа - Telescope         : " << endl ;
	cout << b;
	cout << endl << " Данные объекта ' c ' , типа - Telescopic_rod    : " << endl ;
	cout << c;	

	// Вызов оператора =
	cout << endl << " Проверка на равенство / неравенство  - " << endl;
	cout << " Вызываем оператор == для сравнения объектов ' c ' и ' i ' , класса Telescopic_rod "<< endl;
	bool equal = c == i;
	cout << " - Результат : " << equal << endl;
	
	return 0;
}

