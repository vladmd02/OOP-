//������� 8
//�) ������� �������� �������:
// ������� ��������� - ����������� ������� ����� � ���������� �.�., ������� �.�. � ������ �.�. - ����������� ������.
// �������������� ����/����� � �����, ����������� �����������, �������� ������������ ����� ��������������� ������� �������� ������.

#include <iostream>

using std::cin;
using std::cout; 
using std::endl;
using std::string;
using std::ostream;
using std::istream;

//=======================================================================================================================================
// ����������� ������� ����� - Educational_Institution

class Educational_Institution { // ������� ��������� (����������� ������� �����)
	string name; 			    // �������� 
	int number_of_students;     // ����������� ��������� / ��������
	int price_per_contract;     // ���� �� �������� ��������
	bool budget_place;          // � ��� ���������� ���������� - ���� �� ����������� �������� �� ������� ( 1 , 0 )
	
public:
	// ctor �� ���������
	Educational_Institution () ;
	
	// ����������� � ����������� , ������� ��������� , � ������� - 4 ��������� 
	Educational_Institution (string Name , int Number_of_students , int Price_per_contract , int Budget_place ) ;
	
	// ctor ����������� . �������� �� , ��� � ����� ������ ��� ���������� , �� � ��� ��������� �� ��� ������������� ��� ����������� 
	Educational_Institution (const Educational_Institution &anything ) ; 
	
	// ���������� 
	 ~Educational_Institution () {}; 
	 
	 // ������������ �������� = ( ���� ����� �� ����������� )
	Educational_Institution & operator = (const Educational_Institution &other );  
	
	// � �� ����� ������� Changer , ��� ��� � ������ ������ , �� ����� �� �������� ������ , ������������� - ���� ������� Set � �hanger - ����� ��������� ����������. 
	// ������� Set ���������� ��� ��� ��������� �������� �������� , ��� � ��� �� ���������.
	void Set  () ;
	
	// ��������� ��������� / ���������� 
	bool operator == (const Educational_Institution &other ) { return name == other.name && number_of_students == other.number_of_students && price_per_contract == other.price_per_contract && budget_place == other.budget_place ;}
	bool operator != (const Educational_Institution &other ) { return !(operator == (other));}
	
	// ��� �� ��� ������� , ����� �������� ����� ����������� ������ , ������� ������� ��� ����� ����������� :
	// ����� �������� - ����� ������� Print_private_field � Enter_private_field, ������� ������ / ������� �� ����� �������� ������ private ���� , ������ ��������� ��� ������� �������.
	// ��� ����� ������� - ��� ���� - groops , average_score � address.
	// ������������ , � ����� ������� , ��� ����� ���������� �� ������� 	
	virtual void Print_private_field () =  0; 
	virtual void Enter_private_field () =  0; 

	// ������������ ������� 
	friend ostream& operator << ( ostream& os , Educational_Institution & Ed_In );  // ����� � ����� <<
	friend istream& operator >> ( istream& is , Educational_Institution & Ed_In );  // ���� � �����  >>
};
	
//=======================================================================================================================================
// ����������� ����� - Preschool_educational_institution	

class Preschool_educational_institution : public Educational_Institution {  // ���������� �.�. ( ����������� ����� )
	int groops;// � ���� ����� , ��� ������� ����� �������� �������������� ���� - ����������� �����
public:
	// ctor �� ���������
	Preschool_educational_institution () : Educational_Institution () { // ��� �� ���� , �������� ����������� �������� ������ , �� ��������� ���� ����� � �� ������ ,��� ��� ���������� ��� ��� ������ �������.
		groops = 0; // ���� groops �������������� �����
	}
	
	// ctor � ����������� 
	Preschool_educational_institution ( string name , int number_of_students , int price_per_contract , int budget_place, int Groops ) 
	: Educational_Institution ( name , number_of_students , price_per_contract , budget_place ) { // �������� ���������� � ����������� �������� ������ Educational_Institution , � �������� ��� 4 ���������
		groops = Groops; // ����������� �������� ���� groops
	}
	
	// ctor ����������� 
	Preschool_educational_institution ( const Preschool_educational_institution &anything ) : Educational_Institution ( anything ) { // ����� ����� ������������ ����������� ��������� ������ Educational_Institution
 		groops = anything.groops; // ����������� �������� �� ������� anything - ������ �������� ������� 
	}
	// ������������ �������� =
	Preschool_educational_institution & operator = (const Preschool_educational_institution &other ) ;
	
	// ����������
	~Preschool_educational_institution () {}; // ����� ������ ����������� ������� , ������������ ��������� ���������� ������ �������� ������ Educational_Institution
	
	// ������� ��������� ����� ������� 
	void Set () ;
	
	// ����������� ��������� ����������� ������� Print_private_field
	void Print_private_field () override {
		cout << " | ����������� ����� -              | - " << groops <<endl;
	}
	
	// ����������� ��������� ����������� ������� Enter_private_field
	void Enter_private_field () override {
		cout << " | ����������� ����� -              | - "; cin >> groops; 
	}
};

//=======================================================================================================================================
// ����������� ����� - Secondary_educational_institution
	
//��� �� ���� ����� , ��� � � ������ ����������� ������ 
class Secondary_educational_institution : public Educational_Institution { // ������� �.�. ( ����������� ����� )
	float average_score; // ���. ���� - ������� ���
	
public:	
	// ctor �� ���������
	Secondary_educational_institution () : Educational_Institution () { // ��� �� ���� , �������� ����������� �������� ������ , �� ��������� ���� ����� � �� ������ ,��� ��� ���������� ��� ��� ������ �������
		average_score = 0; // ���� groops �������������� �����
	}
	
	// ctor � ����������� 
	Secondary_educational_institution (  string name , int number_of_students , int price_per_contract , int budget_place ,float Average_score) 
	: Educational_Institution ( name , number_of_students , price_per_contract , budget_place ) { // �������� ���������� � ����������� ��������� ������ Educational_Institution
		average_score = Average_score;
	}
	
	// ctor ����������� 
	Secondary_educational_institution ( const Secondary_educational_institution &anything ) : Educational_Institution ( anything ) { // ����� ����� ������������ ����������� ��������� ������ Educational_Institution
 		average_score = anything.average_score;
	}
	
	// ������������ �������� =
	Secondary_educational_institution & operator = (const Secondary_educational_institution &other ) ; 
	
	// ����������
	~Secondary_educational_institution () {} ; // ����� ������ ����������� ������� , ������������ ��������� ���������� ������ �������� ������ Educational_Institution
	
	// ������� ��������� ����� ������� 
	void Set ()  ;

	// ����������� ��������� ����������� ������� Print_private_field
	void Print_private_field () override {
		cout << " | ������� ��� -                    | - " << average_score <<endl;
	}
	
	// ����������� ��������� ����������� ������� Enter_private_field
	void Enter_private_field () override {
		cout << " | ������� ���                      | - "; cin >> average_score;
	}
};

//=======================================================================================================================================
// ����������� ������ - Higher_education_institution

class Higher_education_institution : public Educational_Institution { // ������ �.�. ( ����������� ����� )
	string address; // ���. ���� - ������
	
public:
	// ctor �� ���������
	Higher_education_institution () : Educational_Institution () { // ��� �� ���� , �������� ����������� �������� ������ , �� ��������� ���� ����� � �� ������ ,��� ��� ���������� ��� ��� ������ �������
		address = "indefined"; // ���� address �������������� ��������� - "�� ���������"
	}
	
	// ctor � ����������� 
	Higher_education_institution (string name , int number_of_students , int price_per_contract , int budget_place ,  string Address  ) 
	: Educational_Institution ( name , number_of_students , price_per_contract , budget_place ) { // �������� ���������� � ����������� ��������� ������ Educational_Institution
		address = Address;
	}
	
	// ctor ����������� 
	Higher_education_institution ( const Higher_education_institution &anything ) : Educational_Institution ( anything ) { // ����� ����� ������������ ����������� ��������� ������ Educational_Institution
 		address = anything.address;
	}
	
	// ������������ �������� =
	Higher_education_institution & operator = (const Higher_education_institution &other ) ; 
	
	// ����������
	~Higher_education_institution () {}; // ����� ������ ����������� ������� , ������������ ��������� ���������� ������ �������� ������ Educational_Institution
	
	// ������� ��������� ����� ������� 
	void Set () ;
	
	// ����������� ��������� ����������� ������� Print_private_field
	void Print_private_field () override {
		cout << " | ������ -                         | - " << address <<endl;
	}
	
	// ����������� ��������� ����������� ������� Enter_private_field
	void Enter_private_field () override {
		cout << " | ������ -                         | - "; cin >> address;
	}	
};
	
