#include"functions_example_of_using_virtual_functions.cpp"

//=======================================================================================================================================
// ������� ������ ��������������� ����������� ������� -

int main () {
	setlocale(LC_ALL, "Russian"); 

	// ������������� �������� � ������� ������������ � 4 ����������� 
	Parallelepiped 		a ( 1.1  , 1.1 , 1.1 );  // ���� :  double x , double y , double z
	Tetrahedron 		b ( 2.2 );        		 // ���� :  double a 
	Sphere  			c ( 3.3 );   			 // ���� :  double r
	
	// ������������� �������� � ������� ������������ �� ���������
	Parallelepiped 		d ; 
	Tetrahedron 		e ; 
	Sphere 				f ;
	
	// ������������� �������� � ������� ������������ �����������
	Parallelepiped 		g (a); 
	Tetrahedron 		h (b) ; 
	Sphere		    	i (c) ;
	
	// ���� ������ � ������� �������� >> 
	cout << endl << " �������� ���������� ������ ������� ' a ' , ���� - Parallelepiped    : " << endl ;
	cin >> a;
	cout << endl << " �������� ���������� ������ ������� ' b ' , ���� - Tetrahedron       : " << endl ;
	cin >> b;
	cout << endl << " �������� ���������� ������ ������� ' c ' , ���� - Sphere    		  : " << endl ;
	cin >> c;
	
	// ���������� ������� ������� 
	cout << endl << " ������� ������� ' a ' , ���� - Parallelepiped    : " << endl ;
	a.Square();
	cout << endl << " ������� ������� ' b ' , ���� - Tetrahedron      : " << endl ;
	b.Square();
	cout << endl << " ������� ������� ' � ' , ���� - Sphere : " << endl;
	c.Square();
	
	// ����� �������� �� ����� , � ������� ��������� <<
	cout << endl << "����� �������� �� ����� - " << endl;
	cout << endl << " ������ ������� ' a ' , ���� - Parallelepiped      : " << endl ;
	cout << a;
	cout << endl << " ������ ������� ' b ' , ���� - Tetrahedron         : " << endl ;
	cout << b;
	cout << endl << " ������ ������� ' c ' , ���� - Sphere    			: " << endl ;
	cout << c;
	
	// ������ ��������� ������������ 
	cout << endl << "������� d ��������� ������ a , ���� - Parallelepiped " << endl << endl;
	cout << " ������ a : " << a << endl;
	cout << " ������ d : " << d ;
	cout << endl << "�������� ������������� - "  << endl << endl;
	// ������������
	d = a; 
	// ����� ����� ��������
	cout << " ������ a : " << a << endl;
	cout << " ������ d : " << d ;
	
	// ������� ��������� / ��������� ������
	cout << endl << "������������� ������ ��� ������� ' a ' , ���� - Parallelepiped    : " << endl ;
	a.Set();
	cout << endl << "������������� ������ ��� ������� ' b ' , ���� - Tetrahedron      : " << endl ;
	b.Set();
	cout << endl << "������������� ������ ��� ������� ' � ' , ���� - Sphere : " << endl;
	c.Set();
	
	// ����� ����� ������������� ������ Set
	cout << endl << "����� �������� �� ����� - " << endl;
	cout << endl << " ������ ������� ' a ' , ���� - Parallelepiped       : " << endl ;
	cout << a;
	cout << endl << " ������ ������� ' b ' , ���� - Tetrahedron         : " << endl ;
	cout << b;
	cout << endl << " ������ ������� ' c ' , ���� - Sphere    : " << endl ;
	cout << c;	

	// ����� ��������� =
	cout << endl << " �������� �� ��������� / �����������  - " << endl;
	cout << " �������� �������� == ��� ��������� �������� ' c ' � ' i ' , ������ Sphere "<< endl;
	bool equal = c == i;
	cout << " - ��������� : " << equal << endl;

	return 0;
}
