#include"header_string_class_implementation.h"
	
MyString::MyString() { // ctor �� ��������� , �������� , ����� ��� �������� ������� �� ����� ����������� ��� ��������
		//length = 4;
		length = 0;
		str = new char[1];
		str[0] = '\0';
	}

MyString::MyString (  const char *st ) { // �tor , ��� ������ , ������� , ��� ���������� �������� ���������� ��������� �� ������ , ������� �� ����� ������� 
		length = strlen(st); 
		str = new char [length + 1]; // � ������� ���� ������ , ������� ����� ������ 
		strcpy(str , st);
	}
	
MyString::MyString ( const MyString &other  ) { // ctor ����������� 
   	
	length = other.length;
	str = new char[ length+1 ]; // �������� ����� ������� ������ , ����� �� ��������� �������� ��� ��������� ������ 
	strcpy(str , other.str);
	}
	
MyString::MyString ( MyString &&other  ) { // �tor ����������� - ���� ���������� ����� ��� ��� ���� , ����� ���������� �������� ������������ , ��� ���������� � ��������� ������ 
		length = other.length; // �������� ������� ����������� �������� ����� ������� other 
		str = other.str; // ������ ������� ������ � ������ other ��������� �� ���� � �� �� ������� ������ 
		other.str = nullptr; // �������� ��������� ������� other - nullptr , ����� �������� delete[] - �� ��� ������� �� ���� ������ 
	}	// � ���������� , ����� ������������ �� �������� ��� ������ , ��� ����������� �������� ������ , � ������� ������������ , � ������ � ������� �������� �������� �� ������ ������� � ������ 
	
//��������� ������ � ������� String
MyString & MyString :: operator= ( const char * s ) {
	delete [] str ;
	length = strlen ( s ) ;
	str = new char [ length + 1 ] ;
	strcpy ( str , s ) ;
	return * this ; 
}

MyString & MyString::operator = (const MyString &other ) { //  �������� ������������ - ��� ����� �� ���� ����� , ��� � � ������������ ����������� 
	if(this == &other)
		return *this;
	delete [] str;
	length = other.length; 
	str = new char[length + 1]; 
	strcpy(str , other.str);
	return *this; // ���������� ����������� ��������� �� ��� ������
	} 

ostream& operator << ( ostream& os , const MyString & mystring ) { // ������� ��������� ������� ������ � ostream � iostream , ��� ��� ������ �� ������� ����� , ����� ������� ������� ����� ����������� 
	os << mystring.str ;	
	return os; 
	}
	
MyString MyString::operator + ( const MyString &other ) { // { // ������������ �������� + , ��� ������������ ����� 
		MyString newStr; // ����� ������ , ������� ����� ���� ������� , ��� ��������� ������ ������ 
		
		int thisLength = this->length;
		int otherLength = other.length;
		newStr.length = thisLength + otherLength; // ��������� ����� ����� ������
		newStr.str = new char [ thisLength + otherLength + 1 ]; // �������� ������ �� ����� ������
		
		int i = 0; // ��� ��� ����� ������� �������� ��� ����� , ����� ��� ������ ������� ����� � ���� ������ - ��������� ���������� , � �� ���������� ����� 
		for ( ; i< thisLength ; i++ ) {
			newStr.str[i] = str[i]; // ���������� ������ ����� 
		}
		for (int j = 0 ; j<otherLength ; j++ , i++ ) {
			newStr.str[i] = other.str[j]; // � ��� ������  
		}
		newStr.str[thisLength + otherLength] = '\0'; // ���� � �� ������ ������ , �� ���������� ����� �� ������� :(
		
		return newStr; // ���������� ��� ����� ������
	}	
	
void KMP(MyString X, MyString Y) //  ��� ������ ��������� 
{
    int m = X.length;
    int n = Y.length;
	// ���� Y ������ ������ 
    if (n == 0)
    {
        cout << "������� ���������� � �������� ������� ������";
        return;
    }
 
    // ���� ����� X ������ ����� Y
    if (m < n)
    {
        cout << "������� �� ������ ";
        return;
    }
    // next[i] ������ ������ ���������� ���������� ���������� 
    int next[n + 1];
    
    for (int i = 0; i < n + 1; i++) {
        next[i] = 0;
    }
 
    for (int i = 1; i < n; i++)
    {
        int j = next[i + 1];
 
        while (j > 0 && Y[j] != Y[i]) {
            j = next[j];
        }
 
        if (j > 0 || Y[j] == Y[i]) {
            next[i + 1] = j + 1;
        }
    }
 
    for (int i = 0, j = 0; i < m; i++)
    {
        if (X[i] == Y[j])
        {
            if (++j == n) {
                cout << "������� ���������� � " << i - j + 1 << " ������� ������" << endl;
            }
        }
        else if (j > 0)
        {
            j = next[j];
            i--;    
        }
    }
}

bool operator < ( const MyString & st1 , const MyString & st2 ) { return (strcmp ( st1.str , st2.str ) < 0) ;} 
bool operator > ( const MyString & st1 , const MyString & st2 ) { return st2.str < st1.str;  } /*return st2.str < this->str ;*/
