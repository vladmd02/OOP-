// ������� 8
// b)	������� �������� ������������: ������� - ������, �������� - ��������������� ������.

#include <iostream>

using std::cin;
using std::cout; 
using std::endl;
using std::ostream;
using std::istream;

// ��������� ����������� ������ 
class Fishing_rod;
class Telescope;
class Telescopic_rod;

//=======================================================================================================================================
// ������ ������� ����� - Object

class Object  {
	// � ������� ������ object ( ������� ) , ����� ������� ���� , ������� ���������� ���� ��������.
	// ��������� , ��������� ����� ( x , y , z ) , ������� ��������� ��������� ������� � ������������ - 
	// �������� ��� ��� ��������� ���������, ������� ��� �������� �������� ������ ( ������� ) , �� ����� ������������ ��.
	int x;
	int y;
	int z;
	
public:
	
	// ctor �� ���������
	Object () { x = y = z = 0;}
	
	// ctor � ����������� , ������� ��������� , � ������� - 3 ��������� 
	Object ( int X , int Y , int Z ) ;
	
	// ctor ����������� 
	Object ( const Object &anything  ) ;
	
	// ������������� �������� ������������ =
	Object & operator = (const Object &other ) ;
	
	// ���������� 
	~Object ()  {}; 
	
	// ������� Set - ��� ��������� / ��������� �����
	void Set  () ;
	
	// ��������� ��������� / ���������� 
	bool operator == (const Object &other ) { return x == other.x && y == other.y && z == other.z ;}
	bool operator != (const Object &other ) { return !(operator == (other)); }
	
	// ������������ ������� ������ Object
	friend ostream& operator << ( ostream& os , Object & other );  // ����� � ����� <<
	friend istream& operator >> ( istream& is , Object & other );  // ���� � �����  >>
	
	//-------------------------------------------------------------------------------------
	// ������������ ������� ����� Fishing_rod
	friend ostream& operator << ( ostream& os , Fishing_rod & Fs_Ro );  // ����� � ����� <<
	friend istream& operator >> ( istream& is , Fishing_rod & Fs_Ro );  // ���� � �����  >>
	
	// ������������ ������� ������ Telescope
	friend ostream& operator << ( ostream& os , Telescope & telescope );  // ����� � ����� <<
	friend istream& operator >> ( istream& is , Telescope & telescope );  // ���� � �����  >>
	
	// ������������ ������� ������ Telescopic_rod
	friend ostream& operator << ( ostream& os , Telescopic_rod & Te_Ro );  // ����� � ����� <<
	friend istream& operator >> ( istream& is , Telescopic_rod & Te_Ro );  // ���� � �����  >>
};

//=======================================================================================================================================
// ������ �����������  ����� - Fishing_rod

class Fishing_rod : virtual public Object {
	float length;
	float weight;
	float price;
	
public:
	// ctor �� ���������
	Fishing_rod () : Object() { length = weight = price = 0;}
	
	// ctor � ����������� , ������� ��������� , � ������� - 3 ��������� 
	Fishing_rod ( int X , int Y , int Z , float Length , float Weight , float Price ) : Object( X , Y , Z) {
		length = Length;
		weight = Weight;
		price  = Price;
	}
	
	// ctor ����������� 
	Fishing_rod ( const Fishing_rod &anything  ) : Object ( anything ) { 
		length = anything.length;
		weight = anything.weight;
		price  = anything.price;
	}
	
	// ������������� �������� ������������ =
	Fishing_rod & operator = (const Fishing_rod &other ) ;
	
	// ���������� 
	~Fishing_rod ()  {}; 
	
	// ������� Set - ��� ��������� / ��������� �����
	void Set  () ;
	
	// ��������� ��������� / ���������� 
	bool operator == (const Fishing_rod &other ) { return length == other.length && weight == other.weight && price == other.price && Object::operator ==(other);}
	bool operator != (const Fishing_rod &other ) { return !(operator == (other)); }
	
	// ������������ ������� 
	friend ostream& operator << ( ostream& os , Fishing_rod & Fs_Ro );  // ����� � ����� <<
	friend istream& operator >> ( istream& is , Fishing_rod & Fs_Ro );  // ���� � �����  >>
	
	// ������������ ������� 
	friend ostream& operator << ( ostream& os , Telescopic_rod & Te_Ro );  // ����� � ����� <<
	friend istream& operator >> ( istream& is , Telescopic_rod & Te_Ro );  // ���� � �����  >>
};
	
//=======================================================================================================================================
// ������ �����������  ����� - Telescope
	
class Telescope : virtual public Object {
	float diameter; 
	
public:
	// ctor �� ���������
	Telescope () : Object() { diameter = 0; }
	
	// ctor � ����������� , ������� ��������� , ������������ �������� Diameter
	Telescope ( int X , int Y , int Z , float Diameter ) : Object( X , Y , Z) { diameter = Diameter; }
	
	// ctor ����������� 
	Telescope ( const Telescope &anything  ) : Object ( anything ) { diameter = anything.diameter;}
	
	// ������������� �������� ������������ =
	Telescope & operator = (const Telescope &other ) ;
	
	// ���������� 
	~Telescope ()  {}; 
	
	// ������� Set - ��� ��������� / ��������� �����
	void Set  () ;
	
	// ��������� ��������� / ���������� 
	bool operator == (const Telescope &other ) { return diameter == other.diameter && Object::operator ==(other); }
	bool operator != (const Telescope &other ) { return !(operator == (other));}
	
	// ������������ ������� 
	friend ostream& operator << ( ostream& os , Telescope & telescope );  // ����� � ����� <<
	friend istream& operator >> ( istream& is , Telescope & telescope );  // ���� � �����  >>
	
	// ������������ ������� 
	friend ostream& operator << ( ostream& os , Telescopic_rod & Te_Ro );  // ����� � ����� <<
	friend istream& operator >> ( istream& is , Telescopic_rod & Te_Ro );  // ���� � �����  >>
};

//=======================================================================================================================================
// 	��������� �����������  ����� - Telescopic_rod

class Telescopic_rod : public Fishing_rod , public Telescope {
	float strength;
	
public:
	// ctor �� ���������
	Telescopic_rod () : Object() , Fishing_rod() , Telescope() { // �������� ������������ ����� ������� ������� 
		strength = 0; // �������������� ���� ����
	}
	
	// ctor � ����������� , ������� ��������� ��������� , � �������� �� � ������������ ������� ������� 
	Telescopic_rod (int X , int Y , int Z , float Length , float Weight , float Price , float Diameter , float Strength ) : Object( X , Y , Z ) , Fishing_rod( X , Y ,Z ,Length, Weight , Price  ) , Telescope( X , Y , Z , Diameter ) { 
		strength  = Strength;
	}
	
	// ctor ����������� , ������� ��������� ������ ������������ ������ ( Telescopic_rod ) , � �������� ��� � ������������ ������� ������� ( ������� ������������ )
	Telescopic_rod ( const Telescopic_rod &anything  ) : Object ( anything ) , Fishing_rod( anything ) , Telescope( anything )  { 
		strength = anything.strength;
	}
	
	// ������������� �������� ������������ =
	Telescopic_rod & operator = (const Telescopic_rod &other ) ;
	
	// ���������� 
	~Telescopic_rod ()  {}; // ��� ������ �� ������� ��������� , ��������� ����������� ����� ������� ������� , � ������� �������� ��������������� 
	
	// ������� Set - ��� ��������� / ��������� �����
	void Set  () ;
	
	// ��������� ��������� / ���������� 
	bool operator == (const Telescopic_rod &other ) { return strength == other.strength && Object::operator ==(other) && Fishing_rod::operator ==(other) && Telescope::operator ==(other) ;}
	bool operator != (const Telescopic_rod &other ) { return !(operator == (other)); } 
	
	// ������������ ������� 
	friend ostream& operator << ( ostream& os , Telescopic_rod & Te_Ro );  // ����� � ����� <<
	friend istream& operator >> ( istream& is , Telescopic_rod & Te_Ro );  // ���� � �����  >>

};
