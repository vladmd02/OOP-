// Вариант 8
// b)	Создать иерархии наследования: предмет - удочка, телескоп - телескопическая удочка.

#include <iostream>

using std::cin;
using std::cout; 
using std::endl;
using std::ostream;
using std::istream;

// прототипы производных класса 
class Fishing_rod;
class Telescope;
class Telescopic_rod;

//=======================================================================================================================================
// Первый базовый класс - Object

class Object  {
	// в базовом классе object ( предмет ) , нужно указать поля , которые свойствены всем прдметам.
	// напрмимер , кординаты точек ( x , y , z ) , которые описывают положение прдмета в пространстве - 
	// подходят под все категории предметов, поэтому для описания базового класса ( предмет ) , мы будем использовать их.
	int x;
	int y;
	int z;
	
public:
	
	// ctor по умолчанию
	Object () { x = y = z = 0;}
	
	// ctor с параметрами , который принимает , к примеру - 3 параметра 
	Object ( int X , int Y , int Z ) ;
	
	// ctor копирования 
	Object ( const Object &anything  ) ;
	
	// перегруженный оператор присваивания =
	Object & operator = (const Object &other ) ;
	
	// деструткор 
	~Object ()  {}; 
	
	// функция Set - для изменения / установки полей
	void Set  () ;
	
	// операторы равенства / нераенства 
	bool operator == (const Object &other ) { return x == other.x && y == other.y && z == other.z ;}
	bool operator != (const Object &other ) { return !(operator == (other)); }
	
	// дружественые функции класса Object
	friend ostream& operator << ( ostream& os , Object & other );  // вывод в поток <<
	friend istream& operator >> ( istream& is , Object & other );  // ввод в поток  >>
	
	//-------------------------------------------------------------------------------------
	// дружественые функции клсса Fishing_rod
	friend ostream& operator << ( ostream& os , Fishing_rod & Fs_Ro );  // вывод в поток <<
	friend istream& operator >> ( istream& is , Fishing_rod & Fs_Ro );  // ввод в поток  >>
	
	// дружественые функции класса Telescope
	friend ostream& operator << ( ostream& os , Telescope & telescope );  // вывод в поток <<
	friend istream& operator >> ( istream& is , Telescope & telescope );  // ввод в поток  >>
	
	// дружественые функции класса Telescopic_rod
	friend ostream& operator << ( ostream& os , Telescopic_rod & Te_Ro );  // вывод в поток <<
	friend istream& operator >> ( istream& is , Telescopic_rod & Te_Ro );  // ввод в поток  >>
};

//=======================================================================================================================================
// Второй производный  класс - Fishing_rod

class Fishing_rod : virtual public Object {
	float length;
	float weight;
	float price;
	
public:
	// ctor по умолчанию
	Fishing_rod () : Object() { length = weight = price = 0;}
	
	// ctor с параметрами , который принимает , к примеру - 3 параметра 
	Fishing_rod ( int X , int Y , int Z , float Length , float Weight , float Price ) : Object( X , Y , Z) {
		length = Length;
		weight = Weight;
		price  = Price;
	}
	
	// ctor копирования 
	Fishing_rod ( const Fishing_rod &anything  ) : Object ( anything ) { 
		length = anything.length;
		weight = anything.weight;
		price  = anything.price;
	}
	
	// перегруженный оператор присваивания =
	Fishing_rod & operator = (const Fishing_rod &other ) ;
	
	// деструткор 
	~Fishing_rod ()  {}; 
	
	// функция Set - для изменения / установки полей
	void Set  () ;
	
	// операторы равенства / нераенства 
	bool operator == (const Fishing_rod &other ) { return length == other.length && weight == other.weight && price == other.price && Object::operator ==(other);}
	bool operator != (const Fishing_rod &other ) { return !(operator == (other)); }
	
	// дружественые функции 
	friend ostream& operator << ( ostream& os , Fishing_rod & Fs_Ro );  // вывод в поток <<
	friend istream& operator >> ( istream& is , Fishing_rod & Fs_Ro );  // ввод в поток  >>
	
	// дружественые функции 
	friend ostream& operator << ( ostream& os , Telescopic_rod & Te_Ro );  // вывод в поток <<
	friend istream& operator >> ( istream& is , Telescopic_rod & Te_Ro );  // ввод в поток  >>
};
	
//=======================================================================================================================================
// Третий производный  класс - Telescope
	
class Telescope : virtual public Object {
	float diameter; 
	
public:
	// ctor по умолчанию
	Telescope () : Object() { diameter = 0; }
	
	// ctor с параметрами , который принимает , единственный параметр Diameter
	Telescope ( int X , int Y , int Z , float Diameter ) : Object( X , Y , Z) { diameter = Diameter; }
	
	// ctor копирования 
	Telescope ( const Telescope &anything  ) : Object ( anything ) { diameter = anything.diameter;}
	
	// перегруженный оператор присваивания =
	Telescope & operator = (const Telescope &other ) ;
	
	// деструткор 
	~Telescope ()  {}; 
	
	// функция Set - для изменения / установки полей
	void Set  () ;
	
	// операторы равенства / нераенства 
	bool operator == (const Telescope &other ) { return diameter == other.diameter && Object::operator ==(other); }
	bool operator != (const Telescope &other ) { return !(operator == (other));}
	
	// дружественые функции 
	friend ostream& operator << ( ostream& os , Telescope & telescope );  // вывод в поток <<
	friend istream& operator >> ( istream& is , Telescope & telescope );  // ввод в поток  >>
	
	// дружественые функции 
	friend ostream& operator << ( ostream& os , Telescopic_rod & Te_Ro );  // вывод в поток <<
	friend istream& operator >> ( istream& is , Telescopic_rod & Te_Ro );  // ввод в поток  >>
};

//=======================================================================================================================================
// 	Четвертый производный  класс - Telescopic_rod

class Telescopic_rod : public Fishing_rod , public Telescope {
	float strength;
	
public:
	// ctor по умолчанию
	Telescopic_rod () : Object() , Fishing_rod() , Telescope() { // вызываем конструкторы наших базовых классов 
		strength = 0; // инициализируем поле нулём
	}
	
	// ctor с параметрами , который принимает параметры , и передает их в конструкторы базовых классов 
	Telescopic_rod (int X , int Y , int Z , float Length , float Weight , float Price , float Diameter , float Strength ) : Object( X , Y , Z ) , Fishing_rod( X , Y ,Z ,Length, Weight , Price  ) , Telescope( X , Y , Z , Diameter ) { 
		strength  = Strength;
	}
	
	// ctor копирования , который принимает объект производного класса ( Telescopic_rod ) , и передает его в конструкторы базовых классов ( приницп подставновки )
	Telescopic_rod ( const Telescopic_rod &anything  ) : Object ( anything ) , Fishing_rod( anything ) , Telescope( anything )  { 
		strength = anything.strength;
	}
	
	// перегруженный оператор присваивания =
	Telescopic_rod & operator = (const Telescopic_rod &other ) ;
	
	// деструткор 
	~Telescopic_rod ()  {}; // при выходе из области видимости , вызовутся деструкторы наших базовых классов , в порядке обратном конструированию 
	
	// функция Set - для изменения / установки полей
	void Set  () ;
	
	// операторы равенства / нераенства 
	bool operator == (const Telescopic_rod &other ) { return strength == other.strength && Object::operator ==(other) && Fishing_rod::operator ==(other) && Telescope::operator ==(other) ;}
	bool operator != (const Telescopic_rod &other ) { return !(operator == (other)); } 
	
	// дружественые функции 
	friend ostream& operator << ( ostream& os , Telescopic_rod & Te_Ro );  // вывод в поток <<
	friend istream& operator >> ( istream& is , Telescopic_rod & Te_Ro );  // ввод в поток  >>

};
