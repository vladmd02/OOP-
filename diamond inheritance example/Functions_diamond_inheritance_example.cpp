#include"Header_diamond_inheritance_example.h"

//=======================================================================================================================================
// ������ ������� �������� ������ - Object

// ctor � ����������� , ������� ��������� , � ������� - 3 ��������� 
Object::Object ( int X , int Y , int Z ) {
		x = X;
		y = Y;
		z = Z;
	}
	
// ctor ����������� 
Object::Object ( const Object &anything  ) { 
		x = anything.x;
		y = anything.y;
		z = anything.z;
	}
	
// ������������� �������� ������������ =
Object & Object::operator = (const Object &other ) {   
		x = other.x;
		y = other.y;
		z = other.z;
		return *this; // ���������� ���������
	}

// ������� Set - ��� ��������� / ��������� �����
void Object::Set  () {
		 // ��� ���������� ����� ������������ "�������"
		int X , Y , Z;
		// ��� ������ ��������� �������� , � ���������� � ���� ���� 
		cout << " | ���������� x                       | - ";
		cin >> X;
		x = X;
		cout << " | ���������� y                       | - ";
		cin >> Y;
		y = Y;
		cout << " | ���������� z                       | - ";
		cin >> Z;
		z = Z;
	}
	
// ������������� ������� ������ Object
ostream& operator << ( ostream& os , Object & object ) { // ����� � ����� 
	os << endl;
	os << " |==================================|"<< endl;
   	os << " | ���������� x                     | - "<< object.x << endl;
   	os << " | ���������� y                     | - "<< object.y << endl;
   	os << " | ���������� z                     | - "<< object.z  <<endl;
   	os << " |==================================|"   << endl  ;
	return os; 
	}
	
istream& operator >> ( istream& is ,  Object & object ) {   // ����
	cout << endl;
    cout << "  ������� ���������� ������ ������� - "<< endl;
  	cout << " |==================================|"<< endl;
  	cout << " | ���������� x                     | - "; is >> object.x;
   	cout << " | ���������� y                     | - "; is >> object.y ;
   	cout << " | ���������� z                     | - "; is >> object.z ; 
   	cout << " |==================================|"<< endl << endl;	
    return is; 
	}
	
//=======================================================================================================================================
// ������ ������� ������������ ������ - Fishing_rod
	
// ������������� �������� ������������ =
Fishing_rod & Fishing_rod::operator = (const Fishing_rod &other ) {   
		Object::operator= (other); 
		length = other.length;
		weight = other.weight;
		price  = other.price;
		return *this; // ���������� ���������
	}

// ������� Set - ��� ��������� / ��������� �����
void Fishing_rod::Set  () {
		 // ��� ���������� ����� ������������ "�������"
		float Length , Weight , Price;
		// ��� ������ ��������� �������� , � ���������� � ���� ���� 
		//Object::Set(); 
		cout << " | ����� ������                       | - ";
		cin >> Length;
		length = Length;
		cout << " | ���                                | - ";
		cin >> Weight;
		weight = Weight;
		cout << " | ����                               | - ";
		cin >> Price;
		price = Price;
	}

// ������������� ������� ������ Fishing_rod
ostream& operator << ( ostream& os , Fishing_rod & Fs_Ro ) { // ����� � ����� 
	os << endl;
	os << " |==================================|"<< endl;
	os << " | ���������� x                     | - "<< Fs_Ro.x << endl;
   	os << " | ���������� y                     | - "<< Fs_Ro.y << endl;
	os << " | ���������� z                     | - "<< Fs_Ro.z << endl;
   	os << " | ����� ������                     | - "<< Fs_Ro.length << endl;
   	os << " | ���                              | - "<< Fs_Ro.weight << endl;
   	os << " | ����                             | - "<< Fs_Ro.price  <<endl;
   	os << " |==================================|"    << endl  ;
	return os; 
	}
	
istream& operator >> ( istream& is ,  Fishing_rod & Fs_Ro ) {   // ����
	cout << endl;
    cout << "  ������� ���������� ������ ������� - "<< endl;
  	cout << " |==================================|"<< endl;
  	cout << " | ���������� x                     | - "; is >> Fs_Ro.x ;
   	cout << " | ���������� y                     | - "; is >> Fs_Ro.y ;
	cout << " | ���������� z                     | - "; is >> Fs_Ro.z ;
  	cout << " | ����� ������                     | - "; is >> Fs_Ro.length;
   	cout << " | ���                              | - "; is >> Fs_Ro.weight ;
   	cout << " | ����                             | - "; is >> Fs_Ro.price ; 
   	cout << " |==================================|"<< endl << endl;	
    return is; 
	}
	
//=======================================================================================================================================
// ������ �������� ������������ ������ - Telescope

// ������������� �������� ������������ =
Telescope & Telescope::operator = (const Telescope &other ) {   
		Object::operator= (other); 
		diameter = other.diameter;
		return *this; // ���������� ���������
	}

// ������� Set - ��� ��������� / ��������� �����
void Telescope::Set () {
		 // ��� ���������� ����� ������������ "�������"
		float Diameter;
		// ��� ������ ��������� �������� , � ���������� � ���� ���� 
	    //	Object::Set(); 
		cout << " | �������                            | - ";
		cin >> Diameter;
		diameter = Diameter;
	}

// ������������� ������� ������ Telescope
ostream& operator << ( ostream& os , Telescope & telescope ) { // ����� � ����� 
	os << endl;
	os << " |==================================|"   << endl;
	os << " | ���������� x                     | - "<< telescope.x << endl;
   	os << " | ���������� y                     | - "<< telescope.y << endl;
	os << " | ���������� z                     | - "<< telescope.z << endl;
   	os << " | �������                          | - "<< telescope.diameter << endl;
   	os << " |==================================|"   << endl  ;
	return os; 
	}
	
istream& operator >> ( istream& is ,  Telescope & telescope ) {   // ����
	cout << endl;
    cout << "  ������� ���������� ������ ������� - "<< endl;
  	cout << " |==================================|"<< endl;
  	cout << " | ���������� x                     | - "; is >> telescope.x ;
   	cout << " | ���������� y                     | - "; is >> telescope.y ;
	cout << " | ���������� z                     | - "; is >> telescope.z ;
  	cout << " | �������                          | - "; is >> telescope.diameter;
   	cout << " |==================================|"<< endl << endl;	
    return is; 
	}

//=======================================================================================================================================
// ������ ���������� ������������ ������ - Telescopic_rod

// ������������� �������� ������������ =
Telescopic_rod & Telescopic_rod::operator = (const Telescopic_rod &other ) {   
	// ��� ������� �� ����� ������� ������� , ���� ��������� , ����� ��������� ������������ 
		Object::operator= (other); 
		Fishing_rod::operator= (other); 
		Telescope::operator= (other); 
		strength  = other.strength;
		return *this; // ���������� ���������
	}

// ������� Set - ��� ��������� / ��������� �����
void Telescopic_rod::Set  () {
		 // ��� ���������� ����� ������������ "�������"
		float Strength;
		// ��� ������ ��������� �������� , � ���������� � ���� ����
		// ���� �������� ����� set , � ����� ������� ������� 
		Object::Set();
		Fishing_rod::Set(); 
		Telescope::Set(); 
		cout << " | ��������� ������                   | - ";
		cin >> Strength;
		strength = Strength;
	}	

// ������������� ������� ������ Telescopic_rod
ostream& operator << ( ostream& os , Telescopic_rod & Te_Ro ) { // ����� � ����� 
	os << endl;
	os << " |==================================|"<< endl;
	os << " | ���������� x                     | - "<< Te_Ro.x << endl;
   	os << " | ���������� y                     | - "<< Te_Ro.y << endl;
	os << " | ���������� z                     | - "<< Te_Ro.z << endl;
   	os << " | ����� ������                     | - "<< Te_Ro.length << endl;
   	os << " | ���                              | - "<< Te_Ro.weight << endl;
   	os << " | ����                             | - "<< Te_Ro.price  <<endl;
   	os << " | �������                          | - "<< Te_Ro.diameter << endl;
   	os << " | ��������� ������                 | - "<< Te_Ro.strength << endl;
   	os << " |==================================|"   << endl  ;
	return os; 
	}
	
istream& operator >> ( istream& is ,  Telescopic_rod & Te_Ro ) {   // ����
	cout << endl;
    cout << " ������� ���������� ������ ������� - "<< endl;
  	cout << " |==================================|"<< endl;
  	cout << " | ���������� x                     | - "; is >> Te_Ro.x ;
   	cout << " | ���������� y                     | - "; is >> Te_Ro.y ;
	cout << " | ���������� z                     | - "; is >> Te_Ro.z ;
  	cout << " | ����� ������                     | - "; is >> Te_Ro.length;
   	cout << " | ���                              | - "; is >> Te_Ro.weight ;
   	cout << " | ����                             | - "; is >> Te_Ro.price ;
   	cout << " | �������                          | - "; is >> Te_Ro.diameter ;
  	cout << " | ��������� ������                 | - "; is >> Te_Ro.strength; 
   	cout << " |==================================|"<< endl << endl;	
    return is; 
	}
