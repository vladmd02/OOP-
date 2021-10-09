#include"header_complex.h"

Complex& Complex::operator = (const Complex &other) { // оператор присваивания 
		re = other.re;
		im = other.im;
		return *this;
	}
	
Complex& Complex::operator ++ () { // префиксный инкримент
		re++;
		im++;
		return *this;
	}

Complex& Complex::operator ++ (int value ) { // постфиксный инкримент ()
		Complex result(*this);
		re++;
		im++;
		return result;
	}
 
ostream& operator << ( ostream& os , const 	Complex& complex ) { // вывод
	if(complex.im < 0) 
        os << complex.re << "+i(" << complex.im << ")\n"; 
    else 
        os << complex.re << "+i" << complex.im << "\n"; 
	return os; 
	}
	
istream& operator >> ( istream& is , Complex& complex) {   // ввод
    cout << "Введите действительную часть комплексного числа ";
    is >> complex.re; 
    cout << "Введите мнимую часть комплексного числа "; 
    is >> complex.im;
    return is; 
	}

Complex operator + ( const Complex &current , const Complex &other ) { // оператор сложения 
	Complex result;
	result.re = current.re + other.re;
	result.im = current.im + other.im;
	return result; 
	}
	
Complex operator + ( const Complex &current , const double  &other ) { // оператор сложения , который работает со встроеным типом double 
	Complex result;
	result.re = current.re + other;
	result.im = current.im + other;
	return result; 
}

Complex operator - ( const Complex &current, const Complex &other ) { //  вычитание
	Complex result;
	result.re = current.re - other.re;
	result.im = current.im - other.im;
	return result;
	}

Complex operator - ( const Complex &current , const double  &other ) { // оператор вычетания , который работает со встроеным типом double 
	Complex result;
	result.re = current.re - other;
	result.im = current.im - other;
	return result; 
}

Complex operator * ( const Complex &current, const Complex &other ) { //  умножение
	Complex result;
	double i, j; 
	 
    i = current.re * other.re - current.im * other.im; 
    j = current.re * other.im + other.re * current.im; 
    result.re = i; 
    result.im = j; 
	return result;
	}

Complex operator / ( const Complex &current, const Complex &other ) {  //  деление 
	Complex result;

	double i, j, k; 
    k = current.re * current.re + other.im * other.im; 
    i = (current.re * other.re + current.im * other.im) / k; 
    j = (other.re * current.im - current.re * other.im) / k; 
    result.re = i; 
    result.im = j; 
	return result;
	}
