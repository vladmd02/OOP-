#include"header_complex.h"

Complex& Complex::operator = (const Complex &other) { // �������� ������������ 
		re = other.re;
		im = other.im;
		return *this;
	}
	
Complex& Complex::operator ++ () { // ���������� ���������
		re++;
		im++;
		return *this;
	}

Complex& Complex::operator ++ (int value ) { // ����������� ��������� ()
		Complex result(*this);
		re++;
		im++;
		return result;
	}
 
ostream& operator << ( ostream& os , const 	Complex& complex ) { // �����
	if(complex.im < 0) 
        os << complex.re << "+i(" << complex.im << ")\n"; 
    else 
        os << complex.re << "+i" << complex.im << "\n"; 
	return os; 
	}
	
istream& operator >> ( istream& is , Complex& complex) {   // ����
    cout << "������� �������������� ����� ������������ ����� ";
    is >> complex.re; 
    cout << "������� ������ ����� ������������ ����� "; 
    is >> complex.im;
    return is; 
	}

Complex operator + ( const Complex &current , const Complex &other ) { // �������� �������� 
	Complex result;
	result.re = current.re + other.re;
	result.im = current.im + other.im;
	return result; 
	}
	
Complex operator + ( const Complex &current , const double  &other ) { // �������� �������� , ������� �������� �� ��������� ����� double 
	Complex result;
	result.re = current.re + other;
	result.im = current.im + other;
	return result; 
}

Complex operator - ( const Complex &current, const Complex &other ) { //  ���������
	Complex result;
	result.re = current.re - other.re;
	result.im = current.im - other.im;
	return result;
	}

Complex operator - ( const Complex &current , const double  &other ) { // �������� ��������� , ������� �������� �� ��������� ����� double 
	Complex result;
	result.re = current.re - other;
	result.im = current.im - other;
	return result; 
}

Complex operator * ( const Complex &current, const Complex &other ) { //  ���������
	Complex result;
	double i, j; 
	 
    i = current.re * other.re - current.im * other.im; 
    j = current.re * other.im + other.re * current.im; 
    result.re = i; 
    result.im = j; 
	return result;
	}

Complex operator / ( const Complex &current, const Complex &other ) {  //  ������� 
	Complex result;

	double i, j, k; 
    k = current.re * current.re + other.im * other.im; 
    i = (current.re * other.re + current.im * other.im) / k; 
    j = (other.re * current.im - current.re * other.im) / k; 
    result.re = i; 
    result.im = j; 
	return result;
	}
