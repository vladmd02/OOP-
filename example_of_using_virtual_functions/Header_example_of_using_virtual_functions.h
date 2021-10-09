// Вариант 8
// Создать абстрактный базовый класс Figure с виртуальной функцией - площадь поверхности. 
// Создать производные классы параллелепипед, тетраэдр, шар в которых данная функция переопределена.
// Площадь поверхности параллелепипеда:  S = 2*( x*y+y*z+x*z )
// Площадь поверхности тетраэдра:  		 S = sqrt(3) * pow( a , 2 ); 
// Площадь поверхности шара: 			 S = 4*PI*pow(r,2);

#include <iostream>
#include <math.h>
#define PI 3.14

using std::cin;
using std::cout; 
using std::endl;
using std::ostream;
using std::istream;

using namespace std;

//=======================================================================================================================================
// Первый абстрактный базовый класс - Figure

class Figure {

public:
	//виртуальная функция - площадь поверхности
	virtual void Square() = 0; 
	
};

//=======================================================================================================================================
// Второй производный класс - Parallelepiped

class Parallelepiped : public Figure {
	double S; // площадь
	double x; // длина первого ребра параллелепипеда
	double y; // длина втрого ребра
	double z; // длина третьего ребра 
	
public:

	// переопределеный метод для класса Parallelepiped :
	void Square() override {
		S = 2*( x*y+y*z+x*z ); // формула : площадь прямоугольного параллелепипеда равна двойной сумме площадей трёх граней параллелепипеда 
		cout << " | Площаь Параллелепипеда                              | - "<< S  <<endl;
	}
	
	// ctor по умолчанию  
	Parallelepiped () ;
	
	// ctor с параметрами , который принимает , 3 параметра 
	Parallelepiped ( double X , double Y , double Z) ;
	
	// ctor копирования 
	Parallelepiped ( const Parallelepiped &anything  ) ;
	
	// перегруженный оператор присваивания =
	Parallelepiped & operator = (const Parallelepiped &other ) ;
	
	// деструткор 
	~Parallelepiped () {}; 
	
	// функция изменения / установки данных
	void Set () ;
	
	// операторы равенства / нераенства 
	bool operator == (const Parallelepiped &other ) { return S == other.S;} // сравниваем значение площадей двух объектов . Если их площади равны , то сами объекты тоже равны   
 	bool operator != (const Parallelepiped &other ) { return !(operator == (other)); }
	
	// дружественые функции 
	friend ostream& operator << ( ostream& os , Parallelepiped & parallelepiped );  // вывод в поток <<
	friend istream& operator >> ( istream& is , Parallelepiped & parallelepiped );  // ввод в поток  >>
	
};

//=======================================================================================================================================
// Третий производный класс - Tetrahedron

class Tetrahedron : public Figure {
	double S; // площадь
	double a; // величина ребра тетраэдра.
	
public:
	
	// переопределеный метод для класса Tetrahedron :
	void Square() override {
		S = sqrt(3) * pow( a , 2 ); // формула : Площадь тетраэдра рассчитывается как корень квадратный из произведения квадрата длины ребра на 3.
		cout << " | Площаь тетраэдра                                    | - "<< S  <<endl;
	}

	// ctor по умолчанию
	Tetrahedron () ;
	
	// ctor с параметрами , который принимает , 1 параметр
	Tetrahedron ( double A ) ;
	
	// ctor копирования 
	Tetrahedron ( const Tetrahedron &anything  ) ;
	
	// перегруженный оператор присваивания =
	Tetrahedron & operator = (const Tetrahedron &other ) ;
	
	// деструткор 
	~Tetrahedron () {}; 
	
	// функция изменения / установки данных
	void Set () ;
	
	// операторы равенства / нераенства 
	bool operator == (const Tetrahedron &other ) { return S == other.S ;} // сравниваем значение площадей двух объектов . Если их площади равны , то сами объекты тоже равны
	bool operator != (const Tetrahedron &other ) { return !(operator == (other)); }
	
	// дружественые функции 
	friend ostream& operator << ( ostream& os , Tetrahedron & tetrahedron );  // вывод в поток <<
	friend istream& operator >> ( istream& is , Tetrahedron & tetrahedron );  // ввод в поток  >>
};

//=======================================================================================================================================
// Четвертый производный класс - Sphere

class Sphere : public Figure {
	double S; // площадь
	double r; // длина радиуса шара 
	
public:	

	// переопределеный метод для класса Sphere :
	void Square() override {
		S = 4*PI*pow(r,2); // формула : Площадь поверхности шара равна четырем его радиусам в квадрате умноженным на число PI .
		cout << " | Площаь шара                                         | - "<< S  <<endl;
	}
	
	// ctor по умолчанию
	Sphere () ;
	
	// ctor с параметрами , который принимает , к примеру - 3 параметра 
	Sphere ( double R ) ;
	
	// ctor копирования 
	Sphere ( const Sphere &anything  ) ;
	
	// перегруженный оператор присваивания =
	Sphere & operator = (const Sphere &other ) ;
	
	// деструткор 
	~Sphere () {}; 
	
	// функция изменения / установки данных
	void Set () ;
	
	// операторы равенства / нераенства 
	bool operator == (const Sphere &other ) { return S == other.S ;}
	bool operator != (const Sphere &other ) { return !(operator == (other)); }
	
	// дружественые функции 
	friend ostream& operator << ( ostream& os , Sphere & sphere );  // вывод в поток <<
	friend istream& operator >> ( istream& is , Sphere & sphere );  // ввод в поток  >>
	
};

