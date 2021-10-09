#include"Header_simple_example_of_inheritance.h"

//=======================================================================================================================================
// ������ ������������ �������� ������ - Educational_Institution

	// ctor �� ���������
Educational_Institution::Educational_Institution () { 
		name = "Not definitely"; // ������ ��������� �������� ����� 
		number_of_students = price_per_contract = budget_place = 0;
	}
	
	// ����������� � ����������� , ������� ��������� , � ������� - 4 ��������� 
Educational_Institution::Educational_Institution (string Name , int Number_of_students , int Price_per_contract , int Budget_place ) {
		name = Name;
		number_of_students = Number_of_students;
		price_per_contract = Price_per_contract;
		budget_place = Budget_place;
	}
	
	// ctor ����������� . �������� �� , ��� � ����� ������ ��� ���������� , �� � ��� ��������� �� ��� ������������� ��� ����������� 
Educational_Institution::Educational_Institution (const Educational_Institution &anything ) { 
		name = anything.name;
		number_of_students = anything.number_of_students;
		price_per_contract = anything.price_per_contract;
		budget_place = anything.budget_place;
	}
	
	// ������������ �������� = ( ���� ����� �� ����������� )	 
Educational_Institution & Educational_Institution::operator = (const Educational_Institution &other ) { 
		name = other.name;
		number_of_students = other.number_of_students;
		price_per_contract = other.price_per_contract;
		budget_place = other.budget_place;
		return *this; // ���������� �������������� ��������� �� ��� ������
	}
	
	// � �� ����� ������� Changer , ��� ��� � ������ ������ , �� ����� �� �������� ������ , ������������� - ���� ������� Set � �hanger - ����� ��������� ����������. 
	// ������� Set ���������� ��� ��� ��������� �������� �������� , ��� � ��� �� ���������.
void Educational_Institution::Set  () {
		string Name; // ��� ���������� ����� ������������ "�������"
		int Number_of_students , Price_per_contract; 
		bool Budget_place; 
		
		// ��� ������ ��������� �������� , � ���������� � ���� ���� 
		cout << endl;
//		cout << " ���������� / �������� ������ ������� :" << endl;
		cout << " | �������� �������� ���������      | - ";
		cin >> Name;
		name = Name;
		cout << " | ����������� ���������            | - ";
		cin >> Number_of_students;
		number_of_students = Number_of_students;
		cout << " | ���� �� ��������                 | - ";
		cin >> Price_per_contract;
		price_per_contract = Price_per_contract;
		cout << " | ����������� �������� �� �������  | - "; 
		cin >> Budget_place;
		budget_place = Budget_place;
	}
//=======================================================================================================================================
// ������������� ������� - ����� / ������

ostream& operator << ( std::ostream& os , Educational_Institution & Ed_In ) { // ����� � ����� 
	os << endl;
	os << " |==================================|"<< endl;
   	os << " | �������� �������� ���������      | - "<< Ed_In.name << endl;
   	os << " | ����������� ���������            | - "<< Ed_In.number_of_students << endl;
   	os << " | ���� �� ��������                 | - "<< Ed_In.price_per_contract <<endl;
   	os << " | ����������� �������� �� �������  | - "<< Ed_In.budget_place << endl;
   	Ed_In.Print_private_field(); // ������� ����������� . ( ������ �� ������� ����� ����� ��������� �� ����� ����� �������� )
   	os << " |==================================|"    << endl  ;
	return os; 
	}
	
istream& operator >> ( std::istream& is ,  Educational_Institution & Ed_In ) {   // ����
	cout << endl;
    cout << " ������� ���������� ������ ������� - "<< endl;
  	cout << " |==================================|"<< endl;
  	cout << " | �������� �������� ���������      | - "; is >> Ed_In.name;
   	cout << " | ����������� ���������            | - "; is >> Ed_In.number_of_students ;
   	cout << " | ���� �� ��������                 | - "; is >> Ed_In.price_per_contract ;
   	cout << " | ����������� �������� �� �������  | - "; is >> Ed_In.budget_place; 
   	Ed_In.Enter_private_field(); 
   	cout << " |==================================|"<< endl << endl;	
    return is; 
	}
	
//=======================================================================================================================================
// ������ ������������ ������ - Preschool_educational_institution	

// ������������ �������� =
Preschool_educational_institution & Preschool_educational_institution::operator = (const Preschool_educational_institution &other ) { 
		Educational_Institution::operator= (other); // ���� �������� �������� ������������ �������� ������ , ����� ��������� ������������ , ��� ����� �������� ������ , � ������������� private 
		groops = other.groops; // � ����� ������ ���������� �������� ������� other - ������ �������� �������
		return *this; 
	}
	
	// ������� ��������� ����� ������� 
void Preschool_educational_institution::Set () { 
		Educational_Institution::Set(); // ��� �� ���� �������� ����� �������� ������ , ����� ���������� �������� ��� ����� , ������ ��������� � private ������ �������� ������ Educational_Institution
		int Groops; // � ��� ����� ���� , ����� �� ���������� ���� ��� �������� ������ - ����� ���������� ���� groops (������������ ������)
		Enter_private_field(); // ����� , ������� ������������� �������� ���� groops
	}
	
//=======================================================================================================================================
// ������ ������������ ������ - Secondary_educational_institution	

	// ������������ �������� =
Secondary_educational_institution & Secondary_educational_institution::operator = (const Secondary_educational_institution &other ) { 
		Educational_Institution::operator= (other); // �������� �������� ������������ �������� ������ , ����� ��������� ������������ , ��� ����� �������� ������ , � ������������� private 
		average_score = other.average_score; // � ����� ������ ���������� ���� groops 
		return *this; 
	}
		
	// ������� ��������� ����� ������� 
void Secondary_educational_institution::Set () {
		Educational_Institution::Set(); // ��� ��� �� ���� �������� ����� �������� ������ , ����� ���������� �������� ��� ����� , ������ ��������� � private ������ �������� ������ Educational_Institution
		float Average_score; // � ��� ����� ���� , ��� �� ���������� ���� ��� �������� ������ - ����� ���������� ���� average_score (������������ ������)
		Enter_private_field(); // ����� , ������� ������������� �������� ���� average_score
	}
	
//=======================================================================================================================================
// ������ ������������ ������ - Higher_education_institution

	// ������������ �������� =
Higher_education_institution & Higher_education_institution::operator = (const Higher_education_institution &other ) { 
		Educational_Institution::operator= (other); // �������� �������� ������������ �������� ������ , ����� ��������� ������������ , ��� ����� �������� ������ , � ������������� private 
		address = other.address; // � ����� ������ ���������� ���� address 
		return *this; 
	}
		
	// ������� ��������� ����� ������� 
void Higher_education_institution::Set () { 
		Educational_Institution::Set(); // ��� ��� �� ���� �������� ����� �������� ������ , ����� ���������� �������� ��� ����� , ������ ��������� � private ������ �������� ������ Educational_Institution
		string Address; // � ��� ����� ���� , ��� �� ���������� ���� ��� �������� ������ - ����� ���������� ���� groops (������������ ������)
		Enter_private_field();
	}	

