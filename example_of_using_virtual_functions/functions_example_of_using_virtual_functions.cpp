#include"Header_example_of_using_virtual_functions.h"

//=======================================================================================================================================
// ������ ������� ������������ ������ - Parallelepiped
	
	// ctor �� ���������  
Parallelepiped::Parallelepiped () { 
	// ����������� ���� ���� ����� ���������� 
		S = x = y = z = 0;
	}
	
	// ctor � ����������� , ������� ��������� , � ������� - 3 ��������� 
Parallelepiped::Parallelepiped ( double X , double Y , double Z) {
		S = 0; // ���� S ( ������� ) �������������� ��� ����
		x = X;
		y = Y;
		z = Z;
	}
	
	// ctor ����������� 
Parallelepiped::Parallelepiped ( const Parallelepiped &anything  ) { 
		S = anything.S;
		x = anything.x;
		y = anything.y;
		z = anything.z;
	}
	
	// ������������� �������� ������������ =
Parallelepiped & Parallelepiped::operator = (const Parallelepiped &other ) {   
		S = other.S;
		x = other.x;
		y = other.y;
		z = other.z;
		return *this; // ���������� ���������
	}
	
	// ������� ��������� / ��������� ������
void Parallelepiped::Set () {
	// ��� ���������� ����� ������������ "�������"
		double X , Y , Z ;
	// ��� ������ ��������� �������� , � ���������� � ���� ���� 
		cout << " | �������� x ( ������ ����� ��������������� ) -      | - ";
		cin >> X;
		x = X;
		cout << " | �������� y ( ������ ����� ��������������� ) -      | - ";
		cin >> Y;
		y = Y;
		cout << " | �������� z ( ������ ����� ��������������� ) -      | - ";
		cin >> Z;
		z = Z;
		S = 2*( x*y+y*z+x*z );  // ����� ������� ��������� ������ , �� ������ ������������� ������ 
	}
	
	// ������������� ������� ������ Parallelepiped
ostream& operator << ( ostream& os , Parallelepiped & parallelepiped  ) { // ����� � ����� 
	os << endl;
	os << " |====================================================|"<< endl;
   	os << " | ��������   x ( ������ ����� ��������������� )      | - "<< parallelepiped.x << endl;
   	os << " | ��������   y ( ������ ����� ��������������� )      | - "<< parallelepiped.y << endl;
   	os << " | ��������   z ( ������ ����� ��������������� )      | - "<< parallelepiped.z << endl;
   	os << " | ������ ���������������                             | - "<< parallelepiped.S  <<endl;
   	os << " |====================================================|"   << endl  ;
	return os; 													  
	}
	
istream& operator >> ( istream& is ,  Parallelepiped & parallelepiped ) {   // ����
	cout << endl;
    cout << "  ������� ���������� ������ ������� - "<< endl;	  	
  	cout << " |==================================================|"<< endl;
  	cout << " | ��������   x ( ������ ����� ��������������� )    | - "; is >> parallelepiped.x;
   	cout << " | ��������   y ( ������ ����� ��������������� )    | - "; is >> parallelepiped.y;
   	cout << " | ��������   z ( ������ ����� ��������������� )    | - "; is >> parallelepiped.z;
   	cout << " |==================================================|"<< endl << endl;	
    return is; 
	}
	
//=======================================================================================================================================
// ������ �������� ������������ ������ - Tetrahedron	
	
	// ctor �� ���������
Tetrahedron::Tetrahedron () { 
	// ����������� ���� ���� ����� ����������
		S = a = 0;
	}
	
	// ctor � ����������� , ������� ��������� , � ������� - 3 ��������� 
Tetrahedron::Tetrahedron ( double A ) {
		S = 0; // ���� S ( ������� ) �������������� ��� ����
		a = A;
	}
	
	// ctor ����������� 
Tetrahedron::Tetrahedron ( const Tetrahedron &anything  ) { 
		a = anything.a;
		S = anything.S;
	}
	
	// ������������� �������� ������������ =
Tetrahedron & Tetrahedron::operator = (const Tetrahedron &other ) {   
		a = other.a;
		S = other.S;
		return *this; // ���������� ���������
	}

	// ������� ��������� / ��������� ������	
void Tetrahedron::Set () {
	// ��� ���������� ����� ������������ "�������"
		double A;
	// ��� ������ ��������� �������� , � ���������� � ���� ���� 
		cout << " | �������� a ( ����� ����� ��������� ) -      | - ";
		cin >> A;
		a = A;
		S = sqrt(3) * pow( a , 2 ); // ����� ������� ��������� ������ , �� ������ ������������� ������
	}

	// ������������� ������� ������ Tetrahedron
ostream& operator << ( ostream& os , Tetrahedron & tetrahedron  ) { // ����� � ����� 
	os << endl;
	os << " |==============================================|"<< endl;
   	os << " | �������� a ( ����� ����� ��������� )         | - "<< tetrahedron.a << endl;
   	os << " | ������ ���������                             | - "<< tetrahedron.S  <<endl;
   	os << " |==============================================|"   << endl  ;
	return os; 
	}
	
istream& operator >> ( istream& is ,  Tetrahedron & tetrahedron ) {   // ����
	cout << endl;
    cout << "  ������� ���������� ������ ������� - "<< endl;
  	cout << " |============================================|"<< endl;
  	cout << " | �������� a ( ����� ����� ��������� )       | - "; is >> tetrahedron.a;
   	cout << " |============================================|"<< endl << endl;	
    return is; 
	}
	
//=======================================================================================================================================
// ������ ���������� ������������ ������ - Sphere
	
	// ctor �� ���������
Sphere::Sphere () { 
	// ����������� ���� ���� ����� ����������
		S = r = 0;
	}
	
	// ctor � ����������� , ������� ��������� , � ������� - 3 ��������� 
Sphere::Sphere ( double R ) {
		S = 0; // ���� S ( ������� ) �������������� ��� ����
		r = R;
	}
	
	// ctor ����������� 
Sphere::Sphere ( const Sphere &anything  ) { 
		r = anything.r;
		S = anything.S;
	}
	
	// ������������� �������� ������������ =
Sphere & Sphere::operator = (const Sphere &other ) {   
		r = other.r;
		S = other.S;
		return *this; // ���������� ���������
	}
	
	// ������� ��������� / ��������� ������
void Sphere::Set () {
	// ��� ���������� ����� ������������ "�������"
		double R;
	// ��� ������ ��������� �������� , � ���������� � ���� ���� 
		cout << " | �������� r ( ����� ������� ���� ) -   | - ";
		cin >> R;
		r = R;
		S = 4*PI*pow(r,2); // ����� ������� ��������� ������ , �� ������ ������������� ������
	}

	// ������������� ������� ������ Sphere
ostream& operator << ( ostream& os , Sphere & sphere  ) { // ����� � ����� 
	os << endl;
	os << " |==========================================|"<< endl;
   	os << " | �������� r ( ����� ������� ���� ) -      | - "<< sphere.r << endl;
   	os << " | ������ ����                              | - "<< sphere.S  <<endl;
   	os << " |==========================================|"   << endl  ;
	return os; 
	}
	
istream& operator >> ( istream& is ,  Sphere & sphere ) {   // ����
	cout << endl;
    cout << "  ������� ���������� ������ ������� - "<< endl;
  	cout << " |========================================|"<< endl;
  	cout << " | �������� r ( ����� ������� ���� ) -    | - "; is >> sphere.r;
   	cout << " |========================================|"<< endl << endl;	
    return is; 
	}
