// ������� 8
// ������� ����������� ������� ����� Figure � ����������� �������� - ������� �����������. 
// ������� ����������� ������ ��������������, ��������, ��� � ������� ������ ������� ��������������.
// ������� ����������� ���������������:  S = 2*( x*y+y*z+x*z )
// ������� ����������� ���������:  		 S = sqrt(3) * pow( a , 2 ); 
// ������� ����������� ����: 			 S = 4*PI*pow(r,2);

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
// ������ ����������� ������� ����� - Figure

class Figure {

public:
	//����������� ������� - ������� �����������
	virtual void Square() = 0; 
	
};

//=======================================================================================================================================
// ������ ����������� ����� - Parallelepiped

class Parallelepiped : public Figure {
	double S; // �������
	double x; // ����� ������� ����� ���������������
	double y; // ����� ������ �����
	double z; // ����� �������� ����� 
	
public:

	// ��������������� ����� ��� ������ Parallelepiped :
	void Square() override {
		S = 2*( x*y+y*z+x*z ); // ������� : ������� �������������� ��������������� ����� ������� ����� �������� ��� ������ ��������������� 
		cout << " | ������ ���������������                              | - "<< S  <<endl;
	}
	
	// ctor �� ���������  
	Parallelepiped () ;
	
	// ctor � ����������� , ������� ��������� , 3 ��������� 
	Parallelepiped ( double X , double Y , double Z) ;
	
	// ctor ����������� 
	Parallelepiped ( const Parallelepiped &anything  ) ;
	
	// ������������� �������� ������������ =
	Parallelepiped & operator = (const Parallelepiped &other ) ;
	
	// ���������� 
	~Parallelepiped () {}; 
	
	// ������� ��������� / ��������� ������
	void Set () ;
	
	// ��������� ��������� / ���������� 
	bool operator == (const Parallelepiped &other ) { return S == other.S;} // ���������� �������� �������� ���� �������� . ���� �� ������� ����� , �� ���� ������� ���� �����   
 	bool operator != (const Parallelepiped &other ) { return !(operator == (other)); }
	
	// ������������ ������� 
	friend ostream& operator << ( ostream& os , Parallelepiped & parallelepiped );  // ����� � ����� <<
	friend istream& operator >> ( istream& is , Parallelepiped & parallelepiped );  // ���� � �����  >>
	
};

//=======================================================================================================================================
// ������ ����������� ����� - Tetrahedron

class Tetrahedron : public Figure {
	double S; // �������
	double a; // �������� ����� ���������.
	
public:
	
	// ��������������� ����� ��� ������ Tetrahedron :
	void Square() override {
		S = sqrt(3) * pow( a , 2 ); // ������� : ������� ��������� �������������� ��� ������ ���������� �� ������������ �������� ����� ����� �� 3.
		cout << " | ������ ���������                                    | - "<< S  <<endl;
	}

	// ctor �� ���������
	Tetrahedron () ;
	
	// ctor � ����������� , ������� ��������� , 1 ��������
	Tetrahedron ( double A ) ;
	
	// ctor ����������� 
	Tetrahedron ( const Tetrahedron &anything  ) ;
	
	// ������������� �������� ������������ =
	Tetrahedron & operator = (const Tetrahedron &other ) ;
	
	// ���������� 
	~Tetrahedron () {}; 
	
	// ������� ��������� / ��������� ������
	void Set () ;
	
	// ��������� ��������� / ���������� 
	bool operator == (const Tetrahedron &other ) { return S == other.S ;} // ���������� �������� �������� ���� �������� . ���� �� ������� ����� , �� ���� ������� ���� �����
	bool operator != (const Tetrahedron &other ) { return !(operator == (other)); }
	
	// ������������ ������� 
	friend ostream& operator << ( ostream& os , Tetrahedron & tetrahedron );  // ����� � ����� <<
	friend istream& operator >> ( istream& is , Tetrahedron & tetrahedron );  // ���� � �����  >>
};

//=======================================================================================================================================
// ��������� ����������� ����� - Sphere

class Sphere : public Figure {
	double S; // �������
	double r; // ����� ������� ���� 
	
public:	

	// ��������������� ����� ��� ������ Sphere :
	void Square() override {
		S = 4*PI*pow(r,2); // ������� : ������� ����������� ���� ����� ������� ��� �������� � �������� ���������� �� ����� PI .
		cout << " | ������ ����                                         | - "<< S  <<endl;
	}
	
	// ctor �� ���������
	Sphere () ;
	
	// ctor � ����������� , ������� ��������� , � ������� - 3 ��������� 
	Sphere ( double R ) ;
	
	// ctor ����������� 
	Sphere ( const Sphere &anything  ) ;
	
	// ������������� �������� ������������ =
	Sphere & operator = (const Sphere &other ) ;
	
	// ���������� 
	~Sphere () {}; 
	
	// ������� ��������� / ��������� ������
	void Set () ;
	
	// ��������� ��������� / ���������� 
	bool operator == (const Sphere &other ) { return S == other.S ;}
	bool operator != (const Sphere &other ) { return !(operator == (other)); }
	
	// ������������ ������� 
	friend ostream& operator << ( ostream& os , Sphere & sphere );  // ����� � ����� <<
	friend istream& operator >> ( istream& is , Sphere & sphere );  // ���� � �����  >>
	
};

