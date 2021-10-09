// ������� 8 :
//�) ������� ����� String - ������, ��������� ������������ ������.
// ���������� ������������: �� ���������, ����� � � ���������� - ���������� �� ������ ���� char. 
// ���������� ������� ������������ ����� ������ ������, ���������, ������ ���������, ���������� �������� � ��.
#include <iostream>
#include <string.h>
using std::cout; 
using std::endl;
using std::ostream;

class MyString {
	
	char *str; // ��� ��������� , ��� ��� ������������ ������ ������ �� �� ����� , ������������� ����� ����� ������� � � ������������ ������ 
	int length; // ������� ���������� ��� �������� ����� ������ , ����� �� ������ ����� length , � �� ������ �� ������� ������ ��� �������� ���� ��������� 
	
public:

	// ������������ / ����������� 
	MyString() ; // ctor �� ��������� , �������� , ����� ��� �������� ������� �� ����� ����������� ��� ��������
	MyString ( const char *str ) ;  // �tor , ��� ������ , ������� , ��� ���������� �������� ���������� ��������� �� ������ , ������� �� ����� ������� 
	MyString ( const MyString &other  ) ;  // ctor ����������� 
   	MyString ( MyString &&other  ) ; // ctor ����������� 
	~MyString() { delete [] str; }  // ���������� 
	
	// ��������� / ������ ������
	MyString & operator = (const MyString &other ) ; //  �������� ������������ ��� MyString  - ��� ����� �� ���� ����� , ��� � � ������������ ����������� 
	MyString & operator = ( const char *s ) ; // �������� ������������ , ������� �������� �� �������� � ����� �
	MyString operator + ( const MyString &other ) ; // ������������ �������� + , ��� ������������ ����� 
	int Mylength () { return length; } // ����� , ������� ���������� ����� ������ 
	
	// ��������� ��������� - ���������� . �� � �� ���� �������� �� header , ��� ��� ��� ������ ���� ������.
	bool operator == (const MyString &other ) { return (strcmp(other.str , str) == 0); } // �������� ==
	bool operator != (const MyString &other ) { return !( operator ==(other)); }  // ���������� �������������� ��������� ��������� =
	
	// ��������� �������������� 
	char & operator [] (int index) { return str[index]; } // �������� [] , ����� �� ����� �������� �������� ������� �� ������ � �������
	const char & operator [] ( int index ) const {return str [index] ;} // ��� ���� ����� , ������ �������� � const 
	
	// ������������� ������� ������ / ������ 
	friend bool operator < ( const MyString & st1 , const MyString & st2 );
	friend bool operator > ( const MyString & st1 , const MyString & st2 );
	
	// ������������� ������� 
	friend void KMP(MyString X, MyString Y); // ����� ��������� 
	friend ostream& operator << ( ostream& os , const MyString & mystring ); // �������� << 
};

