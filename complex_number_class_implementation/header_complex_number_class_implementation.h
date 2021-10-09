//Вариант 8:
//а) Определить класс Complex - комплексные числа.
// Определить все односимвольные операторы как дружественные операторы, а двухсимвольные как методы класса. 
// Исключение - оператор присваивания, который может быть только методом класса и операторы вводы/вывода в поток.
// Сложение и вычитание должно производиться как с комплексными числами, так и со встроенным double.

// По условию :
// i++ ; ++i ; == ; != 		- эти двухсимволные операторы должны быть методами класса
// +  ; - ; * ; / 			- а односимвольные операторы дружественными функциями  
// = 						- оператор присваивания как метод класса 
// << 						- оператор вывода в поток - как дружественная функция 

#include <iostream>
using std::cout; 
using std::endl;
using std::ostream;
using std::istream;

class Complex {
	double re , im; // объявляем мнимую (im) и действительную часть (re) 
public:
	Complex () { re = im = 0; }; // ctor по умолчанию
	Complex ( double r , double i) { re = r; im = i;} // ctor с параметрами
	Complex ( const Complex &other ) { re = other.re; im = other.im; } // ctor копирования
	~Complex () {} // деструктор 
	
	// методы класса
	Complex & operator = (const Complex &other) ; // оператор присваивания 
	Complex &operator ++ () ; // префиксный инкримент
	Complex &operator ++ ( int value ) ;  // постфиксный инкримент 
    
	// операторы равенства / неравенства :
	bool operator == (const Complex &other ) { return re == other.re && im == other.im; } 
	bool operator != (const Complex &other ) { return !( operator == (other)); }
	
	// дружественые функци :
	friend ostream& operator << ( ostream& os , const Complex & complex );	 // вывод из потока 
	friend istream& operator >> ( istream& is , Complex& complex );   	 	 // ввод в поток 
	
	// простейщие арифметические операции :
	friend Complex operator + ( const Complex &current , const Complex &other ); // оператор сложения 
	friend Complex operator + ( const Complex &current , const double  &other ); // оператор сложения , который работает со встроеным типом double 
	friend Complex operator - ( const Complex &current , const Complex &other ); // вычитание
	friend Complex operator - ( const Complex &current , const double  &other ); // оператор вычетания , который работает со встроеным типом double 
	friend Complex operator * ( const Complex &current , const Complex &other ); // умножение 
	friend Complex operator / ( const Complex &current , const Complex &other ); //  деление 
}; 

