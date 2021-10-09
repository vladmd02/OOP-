#include"Functions_diamond_inheritance_example.cpp"

//=======================================================================================================================================
// ������� ������ ������ ������������ ������������ -

int main () {
	setlocale(LC_ALL, "Russian"); 

	// ������������� �������� � ������� ������������ , ������� ��������� n-�� ����������� ���������� 
	Object 			z ( 0, 0, 0);								 // ���� : 	int x , int y , int z.
	Fishing_rod 	a ( 1, 1, 1 ,1.1 , 1.1 , 1.1 );              // ���� : 	int x , int y , int z , float length ,	float weight,	float price.
	Telescope 		b ( 2, 2, 2, 2.2 );        				     // ���� : 	int x , int y , int z , float diameter.
	Telescopic_rod  c ( 3, 3, 3, 3.3 , 3.3 , 3.3 , 3.3 , 3.3 );  // ���� : 	int x , int y , int z , float length ,	float weight ,	float price ,   float diameter ,   float strength.
	
	// ������������� �������� � ������� ������������ �� ���������
	Object 			w ;
	Fishing_rod 	d ; 
	Telescope 		e ; 
	Telescopic_rod 	f ;
	
	// ������������� �������� � ������� ������������ �����������
	Object 			x (z);
	Fishing_rod 	g (a); 
	Telescope 		h (b) ; 
	Telescopic_rod  i (c) ;
	
	// ���� ������ � ������� �������� >> 
	cout << endl << " �������� ���������� ������ ������� ' z ' , ���� - Object       : " << endl ;
	cin >> z;
	cout << endl << " �������� ���������� ������ ������� ' a ' , ���� - Fishing_rod       : " << endl ;
	cin >> a;
	cout << endl << " �������� ���������� ������ ������� ' b ' , ���� - Telescope         : " << endl ;
	cin >> b;
	cout << endl << " �������� ���������� ������ ������� ' c ' , ���� - Telescopic_rod    : " << endl ;
	cin >> c;
	
	// ����� �������� �� ����� , � ������� ��������� <<
	cout << endl << "����� �������� �� ����� - " << endl;
	cout << endl << " ������ ������� ' z ' , ���� - Object       : " << endl ;
	cout << z;
	cout << endl << " ������ ������� ' a ' , ���� - Fishing_rod       : " << endl ;
	cout << a;
	cout << endl << " ������ ������� ' b ' , ���� - Telescope         : " << endl ;
	cout << b;
	cout << endl << " ������ ������� ' c ' , ���� - Telescopic_rod    : " << endl ;
	cout << c;
	
	// ������ ��������� ������������ 
	cout << endl << "������� d ��������� ������ a , ���� - Fishing_rod " << endl << endl;
	cout << " ������ a : " << a << endl;
	cout << " ������ d : " << d ;
	cout << endl << "�������� ������������� - "  << endl << endl;
	// ������������
	d = a; 
	// ����� ����� ��������
	cout << " ������ a : " << a << endl;
	cout << " ������ d : " << d ;
	
	// ������� ��������� / ��������� ������
	cout << endl << "������������� ������ ��� ������� ' z ' , ���� - Object    : " << endl ;
	z.Set();
	cout << endl << "������������� ������ ��� ������� ' a ' , ���� - Fishing_rod    : " << endl ;
	a.Set();
	cout << endl << "������������� ������ ��� ������� ' b ' , ���� - Telescope      : " << endl ;
	b.Set();
	cout << endl << "������������� ������ ��� ������� ' � ' , ���� - Telescopic_rod : " << endl;
	c.Set();
	
	// ����� ����� ������������� ������ Set
	cout << endl << "����� �������� �� ����� - " << endl;
	cout << endl << " ������ ������� ' z ' , ���� - Object            : " << endl ;
	cout << z;
	cout << endl << " ������ ������� ' a ' , ���� - Fishing_rod       : " << endl ;
	cout << a;
	cout << endl << " ������ ������� ' b ' , ���� - Telescope         : " << endl ;
	cout << b;
	cout << endl << " ������ ������� ' c ' , ���� - Telescopic_rod    : " << endl ;
	cout << c;	

	// ����� ��������� =
	cout << endl << " �������� �� ��������� / �����������  - " << endl;
	cout << " �������� �������� == ��� ��������� �������� ' c ' � ' i ' , ������ Telescopic_rod "<< endl;
	bool equal = c == i;
	cout << " - ��������� : " << equal << endl;
	
	return 0;
}

