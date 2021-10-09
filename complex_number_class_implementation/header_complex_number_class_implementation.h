//������� 8:
//�) ���������� ����� Complex - ����������� �����.
// ���������� ��� �������������� ��������� ��� ������������� ���������, � �������������� ��� ������ ������. 
// ���������� - �������� ������������, ������� ����� ���� ������ ������� ������ � ��������� �����/������ � �����.
// �������� � ��������� ������ ������������� ��� � ������������ �������, ��� � �� ���������� double.

// �� ������� :
// i++ ; ++i ; == ; != 		- ��� ������������� ��������� ������ ���� �������� ������
// +  ; - ; * ; / 			- � �������������� ��������� �������������� ���������  
// = 						- �������� ������������ ��� ����� ������ 
// << 						- �������� ������ � ����� - ��� ������������� ������� 

#include <iostream>
using std::cout; 
using std::endl;
using std::ostream;
using std::istream;

class Complex {
	double re , im; // ��������� ������ (im) � �������������� ����� (re) 
public:
	Complex () { re = im = 0; }; // ctor �� ���������
	Complex ( double r , double i) { re = r; im = i;} // ctor � �����������
	Complex ( const Complex &other ) { re = other.re; im = other.im; } // ctor �����������
	~Complex () {} // ���������� 
	
	// ������ ������
	Complex & operator = (const Complex &other) ; // �������� ������������ 
	Complex &operator ++ () ; // ���������� ���������
	Complex &operator ++ ( int value ) ;  // ����������� ��������� 
    
	// ��������� ��������� / ����������� :
	bool operator == (const Complex &other ) { return re == other.re && im == other.im; } 
	bool operator != (const Complex &other ) { return !( operator == (other)); }
	
	// ������������ ������ :
	friend ostream& operator << ( ostream& os , const Complex & complex );	 // ����� �� ������ 
	friend istream& operator >> ( istream& is , Complex& complex );   	 	 // ���� � ����� 
	
	// ���������� �������������� �������� :
	friend Complex operator + ( const Complex &current , const Complex &other ); // �������� �������� 
	friend Complex operator + ( const Complex &current , const double  &other ); // �������� �������� , ������� �������� �� ��������� ����� double 
	friend Complex operator - ( const Complex &current , const Complex &other ); // ���������
	friend Complex operator - ( const Complex &current , const double  &other ); // �������� ��������� , ������� �������� �� ��������� ����� double 
	friend Complex operator * ( const Complex &current , const Complex &other ); // ��������� 
	friend Complex operator / ( const Complex &current , const Complex &other ); //  ������� 
}; 

