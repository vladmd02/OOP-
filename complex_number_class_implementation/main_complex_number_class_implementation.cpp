#include"functions_complex.cpp" 

int main () {
	setlocale(LC_ALL, "Russian"); 
	cout << "\t\t ������ ������������� ������ : " << endl; 
	cout << "1) �������� �������� - " << endl;
	Complex value1 (2,  1 );
    Complex value2 (1, -1 );
    
    cout << " - value1 ( 2, 1 ) " << value1 ;
	cout << " - value2 ( 1,-1 ) " << value2 << endl;
	
	cout << "2) C���� �������� - " << endl;
	cout << " - �������� : " << value1 + value2 << endl;
 	cout << "   �������� �������� , ������� ����� �������� � ����� double - " << endl;
	double a = 1.2424;
	cout << " - �������� : " << value1 + a << endl;
	
	cout << "3) �������� �������� - " << endl;
	cout << " - �������� : " << value1 - value2 << endl;
 	cout << "   �������� ��������� , ������� ����� �������� � ����� double - " << endl;
	double b = 2.23;
	cout << " - �������� : " << value1 - b << endl;
	
 	cout << "4) ������������ �������� - " << endl;
    cout << " - �������� : " << value1 * value2 << endl;
	cout << "5) ������� �������� - " << endl;
    cout << " - �������� : "<< value1 / value2 << endl; 
 	
 	cout << "6) ��������� �������� ������� value1 , ������� value2 "<< endl;
 	cout << "  �� - " << endl;
 	cout << " - value1 ( 2, 1 ) " <<  value1 ;
	cout << " - value2 ( 1,-1 ) " <<  value2 << endl;
    value2 = value1;
    cout << "  ����� - " << endl;
    cout << " - value1 ( 2, 1 ) " <<  value1 ;
	cout << " - value2 ( 2, 1 ) " <<  value2 << endl;
	
	cout << "7) ��������� ������� value1 � value2 �� ���������� "<< endl; 
	bool equal = value1 == value2;
	cout << " - �������� : " << equal << endl << endl;
	
	cout << "8) ���������� ��������� ( ������ value1 ) "<< endl; 
	cout << " - �������� : " << ++value1 << endl ;

	cout << "9) ����������� ��������� ( ������ value1 ) - ��� ������ � ������� ��� �������� �� ������ ���������� , \n ��� ��� �������� '<<' - ����� ��'����� ��������� "<< endl; 
	cout << " - �������� : " << value1++ << endl;
	cout << "�� ���� �� ������� �� ����� ������ ( value1 ) ��� ��� - ������ , ��� �������� ��������� ����� " << endl;
	cout  << " - �������� : " << value1 ;
	
	return 0;
}
