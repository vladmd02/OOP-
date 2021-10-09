#include"Header_diamond_inheritance_example.h"

//=======================================================================================================================================
// Методы первого базового класса - Object

// ctor с параметрами , который принимает , к примеру - 3 параметра 
Object::Object ( int X , int Y , int Z ) {
		x = X;
		y = Y;
		z = Z;
	}
	
// ctor копирования 
Object::Object ( const Object &anything  ) { 
		x = anything.x;
		y = anything.y;
		z = anything.z;
	}
	
// перегруженный оператор присваивания =
Object & Object::operator = (const Object &other ) {   
		x = other.x;
		y = other.y;
		z = other.z;
		return *this; // возврашаем указатель
	}

// функция Set - для изменения / установки полей
void Object::Set  () {
		 // эти переменные будут своеобразным "буфером"
		int X , Y , Z;
		// тут просто указываем значения , и записываем в наши поля 
		cout << " | Коардината x                       | - ";
		cin >> X;
		x = X;
		cout << " | Коардината y                       | - ";
		cin >> Y;
		y = Y;
		cout << " | Коардината z                       | - ";
		cin >> Z;
		z = Z;
	}
	
// дружественные функции класса Object
ostream& operator << ( ostream& os , Object & object ) { // вывод в поток 
	os << endl;
	os << " |==================================|"<< endl;
   	os << " | Коардината x                     | - "<< object.x << endl;
   	os << " | Коардината y                     | - "<< object.y << endl;
   	os << " | Коардината z                     | - "<< object.z  <<endl;
   	os << " |==================================|"   << endl  ;
	return os; 
	}
	
istream& operator >> ( istream& is ,  Object & object ) {   // ввод
	cout << endl;
    cout << "  Введите пожалуйста данные объекта - "<< endl;
  	cout << " |==================================|"<< endl;
  	cout << " | Коардината x                     | - "; is >> object.x;
   	cout << " | Коардината y                     | - "; is >> object.y ;
   	cout << " | Коардината z                     | - "; is >> object.z ; 
   	cout << " |==================================|"<< endl << endl;	
    return is; 
	}
	
//=======================================================================================================================================
// Методы второго производного класса - Fishing_rod
	
// перегруженный оператор присваивания =
Fishing_rod & Fishing_rod::operator = (const Fishing_rod &other ) {   
		Object::operator= (other); 
		length = other.length;
		weight = other.weight;
		price  = other.price;
		return *this; // возврашаем указатель
	}

// функция Set - для изменения / установки полей
void Fishing_rod::Set  () {
		 // эти переменные будут своеобразным "буфером"
		float Length , Weight , Price;
		// тут просто указываем значения , и записываем в наши поля 
		//Object::Set(); 
		cout << " | Длина удочки                       | - ";
		cin >> Length;
		length = Length;
		cout << " | Вес                                | - ";
		cin >> Weight;
		weight = Weight;
		cout << " | Цена                               | - ";
		cin >> Price;
		price = Price;
	}

// дружественные функции класса Fishing_rod
ostream& operator << ( ostream& os , Fishing_rod & Fs_Ro ) { // вывод в поток 
	os << endl;
	os << " |==================================|"<< endl;
	os << " | Корадината x                     | - "<< Fs_Ro.x << endl;
   	os << " | Корадината y                     | - "<< Fs_Ro.y << endl;
	os << " | Корадината z                     | - "<< Fs_Ro.z << endl;
   	os << " | Длина удочки                     | - "<< Fs_Ro.length << endl;
   	os << " | Вес                              | - "<< Fs_Ro.weight << endl;
   	os << " | Цена                             | - "<< Fs_Ro.price  <<endl;
   	os << " |==================================|"    << endl  ;
	return os; 
	}
	
istream& operator >> ( istream& is ,  Fishing_rod & Fs_Ro ) {   // ввод
	cout << endl;
    cout << "  Введите пожалуйста данные объекта - "<< endl;
  	cout << " |==================================|"<< endl;
  	cout << " | Корадината x                     | - "; is >> Fs_Ro.x ;
   	cout << " | Корадината y                     | - "; is >> Fs_Ro.y ;
	cout << " | Корадината z                     | - "; is >> Fs_Ro.z ;
  	cout << " | Длина удочки                     | - "; is >> Fs_Ro.length;
   	cout << " | Вес                              | - "; is >> Fs_Ro.weight ;
   	cout << " | Цена                             | - "; is >> Fs_Ro.price ; 
   	cout << " |==================================|"<< endl << endl;	
    return is; 
	}
	
//=======================================================================================================================================
// Методы третьего производного класса - Telescope

// перегруженный оператор присваивания =
Telescope & Telescope::operator = (const Telescope &other ) {   
		Object::operator= (other); 
		diameter = other.diameter;
		return *this; // возврашаем указатель
	}

// функция Set - для изменения / установки полей
void Telescope::Set () {
		 // эта переменная будут своеобразным "буфером"
		float Diameter;
		// тут просто указываем значение , и записываем в наше поле 
	    //	Object::Set(); 
		cout << " | Диаметр                            | - ";
		cin >> Diameter;
		diameter = Diameter;
	}

// дружественные функции класса Telescope
ostream& operator << ( ostream& os , Telescope & telescope ) { // вывод в поток 
	os << endl;
	os << " |==================================|"   << endl;
	os << " | Корадината x                     | - "<< telescope.x << endl;
   	os << " | Корадината y                     | - "<< telescope.y << endl;
	os << " | Корадината z                     | - "<< telescope.z << endl;
   	os << " | Диаметр                          | - "<< telescope.diameter << endl;
   	os << " |==================================|"   << endl  ;
	return os; 
	}
	
istream& operator >> ( istream& is ,  Telescope & telescope ) {   // ввод
	cout << endl;
    cout << "  Введите пожалуйста данные объекта - "<< endl;
  	cout << " |==================================|"<< endl;
  	cout << " | Корадината x                     | - "; is >> telescope.x ;
   	cout << " | Корадината y                     | - "; is >> telescope.y ;
	cout << " | Корадината z                     | - "; is >> telescope.z ;
  	cout << " | Диаметр                          | - "; is >> telescope.diameter;
   	cout << " |==================================|"<< endl << endl;	
    return is; 
	}

//=======================================================================================================================================
// Методы четвертого производного класса - Telescopic_rod

// перегруженный оператор присваивания =
Telescopic_rod & Telescopic_rod::operator = (const Telescopic_rod &other ) {   
	// для каждого из наших базовых классов , явно указываем , вызов оператора присваивания 
		Object::operator= (other); 
		Fishing_rod::operator= (other); 
		Telescope::operator= (other); 
		strength  = other.strength;
		return *this; // возврашаем указатель
	}

// функция Set - для изменения / установки полей
void Telescopic_rod::Set  () {
		 // эти переменные будут своеобразным "буфером"
		float Strength;
		// тут просто указываем значения , и записываем в наши поля
		// явно вызываем метод set , у нащих базовых классов 
		Object::Set();
		Fishing_rod::Set(); 
		Telescope::Set(); 
		cout << " | Прочность удочки                   | - ";
		cin >> Strength;
		strength = Strength;
	}	

// дружественные функции класса Telescopic_rod
ostream& operator << ( ostream& os , Telescopic_rod & Te_Ro ) { // вывод в поток 
	os << endl;
	os << " |==================================|"<< endl;
	os << " | Корадината x                     | - "<< Te_Ro.x << endl;
   	os << " | Корадината y                     | - "<< Te_Ro.y << endl;
	os << " | Корадината z                     | - "<< Te_Ro.z << endl;
   	os << " | Длина удочки                     | - "<< Te_Ro.length << endl;
   	os << " | Вес                              | - "<< Te_Ro.weight << endl;
   	os << " | Цена                             | - "<< Te_Ro.price  <<endl;
   	os << " | Диаметр                          | - "<< Te_Ro.diameter << endl;
   	os << " | Прочность удочки                 | - "<< Te_Ro.strength << endl;
   	os << " |==================================|"   << endl  ;
	return os; 
	}
	
istream& operator >> ( istream& is ,  Telescopic_rod & Te_Ro ) {   // ввод
	cout << endl;
    cout << " Введите пожалуйста данные объекта - "<< endl;
  	cout << " |==================================|"<< endl;
  	cout << " | Корадината x                     | - "; is >> Te_Ro.x ;
   	cout << " | Корадината y                     | - "; is >> Te_Ro.y ;
	cout << " | Корадината z                     | - "; is >> Te_Ro.z ;
  	cout << " | Длина удочки                     | - "; is >> Te_Ro.length;
   	cout << " | Вес                              | - "; is >> Te_Ro.weight ;
   	cout << " | Цена                             | - "; is >> Te_Ro.price ;
   	cout << " | Диаметр                          | - "; is >> Te_Ro.diameter ;
  	cout << " | Прочность удочки                 | - "; is >> Te_Ro.strength; 
   	cout << " |==================================|"<< endl << endl;	
    return is; 
	}
