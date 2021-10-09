#include"Header_example_of_using_virtual_functions.h"

//=======================================================================================================================================
// Методы второго производного класса - Parallelepiped
	
	// ctor по умолчанию  
Parallelepiped::Parallelepiped () { 
	// присваиваем нули всем нашим переменным 
		S = x = y = z = 0;
	}
	
	// ctor с параметрами , который принимает , к примеру - 3 параметра 
Parallelepiped::Parallelepiped ( double X , double Y , double Z) {
		S = 0; // поле S ( площадь ) инициализируем как ноль
		x = X;
		y = Y;
		z = Z;
	}
	
	// ctor копирования 
Parallelepiped::Parallelepiped ( const Parallelepiped &anything  ) { 
		S = anything.S;
		x = anything.x;
		y = anything.y;
		z = anything.z;
	}
	
	// перегруженный оператор присваивания =
Parallelepiped & Parallelepiped::operator = (const Parallelepiped &other ) {   
		S = other.S;
		x = other.x;
		y = other.y;
		z = other.z;
		return *this; // возврашаем указатель
	}
	
	// функция изменения / установки данных
void Parallelepiped::Set () {
	// эти переменные будут своеобразным "буфером"
		double X , Y , Z ;
	// тут просто указываем значения , и записываем в наши поля 
		cout << " | Значение x ( Первое ребро параллелепипеда ) -      | - ";
		cin >> X;
		x = X;
		cout << " | Значение y ( Второе ребро параллелепипеда ) -      | - ";
		cin >> Y;
		y = Y;
		cout << " | Значение z ( Третье ребро параллелепипеда ) -      | - ";
		cin >> Z;
		z = Z;
		S = 2*( x*y+y*z+x*z );  // после каждого изменения данных , мы должны пересчитывать площаъ 
	}
	
	// дружественные функции класса Parallelepiped
ostream& operator << ( ostream& os , Parallelepiped & parallelepiped  ) { // вывод в поток 
	os << endl;
	os << " |====================================================|"<< endl;
   	os << " | Значение   x ( Первое ребро параллелепипеда )      | - "<< parallelepiped.x << endl;
   	os << " | Значение   y ( Второе ребро параллелепипеда )      | - "<< parallelepiped.y << endl;
   	os << " | Значение   z ( Третье ребро параллелепипеда )      | - "<< parallelepiped.z << endl;
   	os << " | Площаь Параллелепипеда                             | - "<< parallelepiped.S  <<endl;
   	os << " |====================================================|"   << endl  ;
	return os; 													  
	}
	
istream& operator >> ( istream& is ,  Parallelepiped & parallelepiped ) {   // ввод
	cout << endl;
    cout << "  Введите пожалуйста данные объекта - "<< endl;	  	
  	cout << " |==================================================|"<< endl;
  	cout << " | Значение   x ( Первое ребро параллелепипеда )    | - "; is >> parallelepiped.x;
   	cout << " | Значение   y ( Второе ребро параллелепипеда )    | - "; is >> parallelepiped.y;
   	cout << " | Значение   z ( Третье ребро параллелепипеда )    | - "; is >> parallelepiped.z;
   	cout << " |==================================================|"<< endl << endl;	
    return is; 
	}
	
//=======================================================================================================================================
// Методы третьего производного класса - Tetrahedron	
	
	// ctor по умолчанию
Tetrahedron::Tetrahedron () { 
	// присваиваем нули всем нашим переменным
		S = a = 0;
	}
	
	// ctor с параметрами , который принимает , к примеру - 3 параметра 
Tetrahedron::Tetrahedron ( double A ) {
		S = 0; // поле S ( площадь ) инициализируем как ноль
		a = A;
	}
	
	// ctor копирования 
Tetrahedron::Tetrahedron ( const Tetrahedron &anything  ) { 
		a = anything.a;
		S = anything.S;
	}
	
	// перегруженный оператор присваивания =
Tetrahedron & Tetrahedron::operator = (const Tetrahedron &other ) {   
		a = other.a;
		S = other.S;
		return *this; // возврашаем указатель
	}

	// функция изменения / установки данных	
void Tetrahedron::Set () {
	// эти переменные будут своеобразным "буфером"
		double A;
	// тут просто указываем значения , и записываем в наши поля 
		cout << " | Значение a ( Длина ребра тетраэдра ) -      | - ";
		cin >> A;
		a = A;
		S = sqrt(3) * pow( a , 2 ); // после каждого изменения данных , мы должны пересчитывать площаъ
	}

	// дружественные функции класса Tetrahedron
ostream& operator << ( ostream& os , Tetrahedron & tetrahedron  ) { // вывод в поток 
	os << endl;
	os << " |==============================================|"<< endl;
   	os << " | Значение a ( Длина ребра тетраэдра )         | - "<< tetrahedron.a << endl;
   	os << " | Площаь Тетраэдра                             | - "<< tetrahedron.S  <<endl;
   	os << " |==============================================|"   << endl  ;
	return os; 
	}
	
istream& operator >> ( istream& is ,  Tetrahedron & tetrahedron ) {   // ввод
	cout << endl;
    cout << "  Введите пожалуйста данные объекта - "<< endl;
  	cout << " |============================================|"<< endl;
  	cout << " | Значение a ( Длина ребра тетраэдра )       | - "; is >> tetrahedron.a;
   	cout << " |============================================|"<< endl << endl;	
    return is; 
	}
	
//=======================================================================================================================================
// Методы четвертого производного класса - Sphere
	
	// ctor по умолчанию
Sphere::Sphere () { 
	// присваиваем нули всем нашим переменным
		S = r = 0;
	}
	
	// ctor с параметрами , который принимает , к примеру - 3 параметра 
Sphere::Sphere ( double R ) {
		S = 0; // поле S ( площадь ) инициализируем как ноль
		r = R;
	}
	
	// ctor копирования 
Sphere::Sphere ( const Sphere &anything  ) { 
		r = anything.r;
		S = anything.S;
	}
	
	// перегруженный оператор присваивания =
Sphere & Sphere::operator = (const Sphere &other ) {   
		r = other.r;
		S = other.S;
		return *this; // возврашаем указатель
	}
	
	// функция изменения / установки данных
void Sphere::Set () {
	// эти переменные будут своеобразным "буфером"
		double R;
	// тут просто указываем значения , и записываем в наши поля 
		cout << " | Значение r ( Длина радиуса шара ) -   | - ";
		cin >> R;
		r = R;
		S = 4*PI*pow(r,2); // после каждого изменения данных , мы должны пересчитывать площаъ
	}

	// дружественные функции класса Sphere
ostream& operator << ( ostream& os , Sphere & sphere  ) { // вывод в поток 
	os << endl;
	os << " |==========================================|"<< endl;
   	os << " | Значение r ( Длина радиуса шара ) -      | - "<< sphere.r << endl;
   	os << " | Площаь Шара                              | - "<< sphere.S  <<endl;
   	os << " |==========================================|"   << endl  ;
	return os; 
	}
	
istream& operator >> ( istream& is ,  Sphere & sphere ) {   // ввод
	cout << endl;
    cout << "  Введите пожалуйста данные объекта - "<< endl;
  	cout << " |========================================|"<< endl;
  	cout << " | Значение r ( Длина радиуса шара ) -    | - "; is >> sphere.r;
   	cout << " |========================================|"<< endl << endl;	
    return is; 
	}
