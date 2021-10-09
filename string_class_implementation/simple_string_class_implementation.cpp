#include"functions_string_class_implementation.cpp" 

int main() {
	setlocale(LC_ALL, "Russian");
	
	cout << " \t\t ��� ����� ���� ����� ? : " << endl << endl;
	
	cout << " 1) �������� �������� - " << endl;
	MyString str ("First object");
	MyString str2("Second object");
	MyString str3("object");
	MyString str4; // ��� �� ����� ������� ������ ������ ������ , ��� � std::string
	
	cout << " - MyString str  ( 'First object'  )  :   "<< str << endl;
	cout << " - MyString str2 ( 'Second object' )  :   "<< str2 << endl;
	cout << " - MyString str3 ( 'object'        )  :   "<< str3 << endl << endl;
	
	cout << " 2) ����������� ������� ����� - " << endl;
	cout << " - MyString str  ( 'First object'  )  :   "<< str.Mylength() << endl;
	cout << " - MyString str2 ( 'Second object' )  :   "<< str2.Mylength() << endl;
	cout << " - MyString str3 ( 'object'        )  :   "<< str3.Mylength() << endl << endl;
	
	cout << " 3) ������������ ����� str , str2 � str3 - " << endl;
	MyString result = str + str2 + str3;
	cout << " - ��������� : ( 'MyString result' )  :   " << result << endl << endl ;
	
	cout << " 4) ����� ������� str3 ( 'object' ) � ������� str ( 'First object' ) - " << endl;
	cout << " - ��������� : " ;
	KMP(str, str3 );
	cout << endl ;

	cout << " 5) �������� �� ��������� :   " << endl ;
	bool equal = str == str2; // ��� �� ����� ��������� �� ����������� � ������� ��������� !=
	cout << " - ��������� : " << equal << endl << endl ;
	
	cout << " 6) ������ ������ ��������� �������������� - " << endl;
	cout << " - ������� ������� ������� str ( 'First object' )  = " <<" [ " << str [0] << " ] " << endl;
	cout << " - ������� ������� ������� str2( 'Second object' ) = " <<" [ " << str2[0] << " ] "<< endl;
	cout << " - ������� ������� ������� str3( 'object       ' ) = " <<" [ " << str3[0] << " ] "<< endl << endl;
	
	cout << " 7) ������ ������ ��������� �������������� ( const )- " << endl;
	const MyString str5 ("hello");
	cout << " - ������� ������� ������� const str5 ('hello')    = " <<" [ " << str5[0] << " ] " << endl << endl;
	
	cout << " 8) ��������� �������� ������� �� �������"<< endl;
	cout << " -  ��������� � ������� str ( 'First object' ) ������ ����� �� [ A ] " << endl;
	str[0] = 'A';
	cout << " -  ��������� :   " << str << endl<< endl;
	
	cout << " 9) ������ ������ ��������� ������������ " << endl;
	cout << " �������� ������� str , �������� ������� str2 " << endl;
	cout << " - MyString str  ( 'Airst object'  )  :   "<< str  << endl;
	cout << " - MyString str2 ( 'Second object' )  :   "<< str2 << endl << endl;
	str = str2;
	cout << " - ��������� :   " << endl;
	cout << " - MyString str  ( 'Second object' )  :   " << str  << endl;
	cout << " - MyString str2 ( 'Second object' )  :   " << str2 << endl;
	
	return 0;
}
