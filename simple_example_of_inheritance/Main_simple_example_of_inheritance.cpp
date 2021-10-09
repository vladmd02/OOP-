#include"functions_simple_example_of_inheritance.cpp"

//=======================================================================================================================================
// ������� ������ ������������ -

int main () {
	setlocale(LC_ALL, "Russian"); 
	
	// ������������� �������� � ������� ������������ � 4 ����������� 
	Preschool_educational_institution a ("one"  , 2 , 200 , 1 , 23 );         // ���� :  string name ; int number_of_students ; int price_per_contract ; bool budget_place ; int groops
	Secondary_educational_institution b ("two"  , 3 , 300 , 0 , 21.1 );       // ���� :  string name ; int number_of_students ; int price_per_contract ; bool budget_place ; float average_score
	Higher_education_institution      c ("three", 4 , 400 , 1 , "address" );  // ���� :  string name ; int number_of_students ; int price_per_contract ; bool budget_place ; string address
	
	// ������������� �������� � ������� ������������ �� ���������
	Preschool_educational_institution d ; 
	Secondary_educational_institution e ; 
	Higher_education_institution      f ;
	
	// ������������� �������� � ������� ������������ �����������
	Preschool_educational_institution g(a); 
	Secondary_educational_institution h(b) ; 
	Higher_education_institution      i(c) ;
	
	// ���� ������ � ������� �������� >> 
	cout << endl << " �������� ���������� ������ ������� ' a ' , ���� - Preschool_educational_institution        : " << endl ;
	cin >> a;
	cout << endl << " �������� ���������� ������ ������� ' b ' , ���� - Secondary_educational_institution        : " << endl ;
	cin >> b;
	cout << endl << " �������� ���������� ������ ������� ' c ' , ���� - Higher_education_institution             : " << endl ;
	cin >> c;
	
	// ����� �������� �� ����� , � ������� ��������� <<
	cout << endl << "����� �������� �� ����� - " << endl;
	cout << endl << " ������ ������� ' a ' , ���� - Preschool_educational_institution        : " << endl ;
	cout << a;
	cout << endl << " ������ ������� ' b ' , ���� - Secondary_educational_institution         : " << endl ;
	cout << b;
	cout << endl << " ������ ������� ' c ' , ���� - Higher_education_institution              : " << endl ;
	cout << c;
	
	// ������ ��������� ������������ 
	cout << endl << "������� ' d ' ��������� ������ ' a ', ���� - Preschool_educational_institution " << endl << endl;
	cout << " ������ a : " << a << endl;
	cout << " ������ d : " << d ;
	cout << endl << "�������� ������������� - "  << endl << endl;
	// ������������
	d = a; 
	// ����� ����� ��������
	cout << " ������ a : " << a << endl;
	cout << " ������ d : " << d ;
	
	// ������� ��������� / ��������� ������
	cout << endl << "������������� ������ ��� ������� ' a ' , ���� - Preschool_educational_institution    : " << endl ;
	a.Set();
	cout << endl << "������������� ������ ��� ������� ' b ' , ���� - Secondary_educational_institution      : " << endl ;
	b.Set();
	cout << endl << "������������� ������ ��� ������� ' � ' , ���� - Higher_education_institution : " << endl;
	c.Set();
	
	// ����� ����� ������������� ������ Set
	cout << endl << "����� �������� �� ����� - " << endl;
	cout << endl << " ������ ������� ' a ' , ���� - Preschool_educational_institution        : " << endl ;
	cout << a;
	cout << endl << " ������ ������� ' b ' , ���� - Secondary_educational_institution         : " << endl ;
	cout << b;
	cout << endl << " ������ ������� ' c ' , ���� - Higher_education_institution              : " << endl ;
	cout << c;
	return 0;
}
