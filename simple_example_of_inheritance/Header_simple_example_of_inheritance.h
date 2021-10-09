//Вариант 8
//а) Создать иерархию классов:
// учебное заведение - абстрактный базовый класс и дошкольное у.з., среднее у.з. и высшее у.з. - производные классы.
// Переопределить ввод/вывод в поток, конструктор копирования, оператор присваивания через соответствующие функции базового класса.

#include <iostream>

using std::cin;
using std::cout; 
using std::endl;
using std::string;
using std::ostream;
using std::istream;

//=======================================================================================================================================
// Абстрактный базовый класс - Educational_Institution

class Educational_Institution { // учебное заведение (абстрактный базовый класс)
	string name; 			    // название 
	int number_of_students;     // колличество студентов / учеников
	int price_per_contract;     // цена за контракт обучения
	bool budget_place;          // а эта переменная показывает - есть ли возможность обучения на бюджете ( 1 , 0 )
	
public:
	// ctor по умолчанию
	Educational_Institution () ;
	
	// констурктор с параметрами , который принимает , к примеру - 4 параметра 
	Educational_Institution (string Name , int Number_of_students , int Price_per_contract , int Budget_place ) ;
	
	// ctor копирования . Учитывая то , что в нашем классе нет указателей , то у нас впринципе не был необходимости его перегружать 
	Educational_Institution (const Educational_Institution &anything ) ; 
	
	// деструткор 
	 ~Educational_Institution () {}; 
	 
	 // перегруженый оператор = ( тоже могли не перегружать )
	Educational_Institution & operator = (const Educational_Institution &other );  
	
	// Я не писал функцию Changer , так как в данном случае , мы нигде не выделяем память , соответсвенно - тело функции Set и Сhanger - будет полностью одинаковым. 
	// функция Set применятся как для установки значений объектов , так и для их изменения.
	void Set  () ;
	
	// операторы равенства / нераенства 
	bool operator == (const Educational_Institution &other ) { return name == other.name && number_of_students == other.number_of_students && price_per_contract == other.price_per_contract && budget_place == other.budget_place ;}
	bool operator != (const Educational_Institution &other ) { return !(operator == (other));}
	
	// так же для примера , можно добавить чисто виртуальные методы , которые сделают наш класс абстрактным :
	// Этими методами - будут функция Print_private_field и Enter_private_field, которые вводят / выводят на экран значение одного private поля , котрое уникально для каждого потомка.
	// для наших классов - эти поля - groops , average_score и address.
	// соответсвнно , в кадом потомке , она будет определена по разному 	
	virtual void Print_private_field () =  0; 
	virtual void Enter_private_field () =  0; 

	// дружественые функции 
	friend ostream& operator << ( ostream& os , Educational_Institution & Ed_In );  // вывод в поток <<
	friend istream& operator >> ( istream& is , Educational_Institution & Ed_In );  // ввод в поток  >>
};
	
//=======================================================================================================================================
// Производный класс - Preschool_educational_institution	

class Preschool_educational_institution : public Educational_Institution {  // дошкольное у.з. ( производный класс )
	int groops;// в этом клссе , для примера можно добавить дополнительное поле - колличество групп
public:
	// ctor по умолчанию
	Preschool_educational_institution () : Educational_Institution () { // тут мы явно , вызываем конструктор базового класса , но вприницпе моги этого и не делать ,так как компилятор сам его неявно вызовет.
		groops = 0; // поле groops инициализируем нулем
	}
	
	// ctor с параметрами 
	Preschool_educational_institution ( string name , int number_of_students , int price_per_contract , int budget_place, int Groops ) 
	: Educational_Institution ( name , number_of_students , price_per_contract , budget_place ) { // вызываем контруктор с параметрами базового класса Educational_Institution , и передаем ему 4 параметра
		groops = Groops; // присваиваем значение полю groops
	}
	
	// ctor копирования 
	Preschool_educational_institution ( const Preschool_educational_institution &anything ) : Educational_Institution ( anything ) { // явный вызов конструктора копирования баззового класса Educational_Institution
 		groops = anything.groops; // присваиваем значение из объекта anything - нашему текущему объекту 
	}
	// перегруженый оператор =
	Preschool_educational_institution & operator = (const Preschool_educational_institution &other ) ;
	
	// деструктор
	~Preschool_educational_institution () {}; // после вызова деструткора потомка , автомаически вызовется деструктор нашего базового класса Educational_Institution
	
	// Функция установки полей объекта 
	void Set () ;
	
	// Опеределяем поведение виртуальной функции Print_private_field
	void Print_private_field () override {
		cout << " | Колличество групп -              | - " << groops <<endl;
	}
	
	// Опеределяем поведение виртуальной функции Enter_private_field
	void Enter_private_field () override {
		cout << " | Колличество групп -              | - "; cin >> groops; 
	}
};

//=======================================================================================================================================
// Производный класс - Secondary_educational_institution
	
//тут всё тоже самое , что и в первом производном классе 
class Secondary_educational_institution : public Educational_Institution { // среднее у.з. ( производный класс )
	float average_score; // доп. поле - средний бал
	
public:	
	// ctor по умолчанию
	Secondary_educational_institution () : Educational_Institution () { // тут мы явно , вызываем конструктор базового класса , но вприницпе моги этого и не делать ,так как компилятор сам его неявно вызовет
		average_score = 0; // поле groops инициализируем нулем
	}
	
	// ctor с параметрами 
	Secondary_educational_institution (  string name , int number_of_students , int price_per_contract , int budget_place ,float Average_score) 
	: Educational_Institution ( name , number_of_students , price_per_contract , budget_place ) { // вызываем контруктор с параметрами баззового класса Educational_Institution
		average_score = Average_score;
	}
	
	// ctor копирования 
	Secondary_educational_institution ( const Secondary_educational_institution &anything ) : Educational_Institution ( anything ) { // явный вызов конструктора копирования баззового класса Educational_Institution
 		average_score = anything.average_score;
	}
	
	// перегруженый оператор =
	Secondary_educational_institution & operator = (const Secondary_educational_institution &other ) ; 
	
	// деструктор
	~Secondary_educational_institution () {} ; // после вызова деструткора потомка , автомаически вызовется деструткор нашего базового класса Educational_Institution
	
	// Функция установки полей объекта 
	void Set ()  ;

	// Опеределяем поведение виртуальной функции Print_private_field
	void Print_private_field () override {
		cout << " | Средний бал -                    | - " << average_score <<endl;
	}
	
	// Опеределяем поведение виртуальной функции Enter_private_field
	void Enter_private_field () override {
		cout << " | Средний бал                      | - "; cin >> average_score;
	}
};

//=======================================================================================================================================
// Производный класса - Higher_education_institution

class Higher_education_institution : public Educational_Institution { // высшее у.з. ( производный класс )
	string address; // доп. поле - адресс
	
public:
	// ctor по умолчанию
	Higher_education_institution () : Educational_Institution () { // тут мы явно , вызываем конструктор базового класса , но вприницпе моги этого и не делать ,так как компилятор сам его неявно вызовет
		address = "indefined"; // поле address инициализируем значением - "не опеределён"
	}
	
	// ctor с параметрами 
	Higher_education_institution (string name , int number_of_students , int price_per_contract , int budget_place ,  string Address  ) 
	: Educational_Institution ( name , number_of_students , price_per_contract , budget_place ) { // вызываем контруктор с параметрами баззового класса Educational_Institution
		address = Address;
	}
	
	// ctor копирования 
	Higher_education_institution ( const Higher_education_institution &anything ) : Educational_Institution ( anything ) { // явный вызов конструктора копирования баззового класса Educational_Institution
 		address = anything.address;
	}
	
	// перегруженый оператор =
	Higher_education_institution & operator = (const Higher_education_institution &other ) ; 
	
	// деструктор
	~Higher_education_institution () {}; // после вызова деструткора потомка , автомаически вызовется деструткор нашего базового класса Educational_Institution
	
	// Функция установки полей объекта 
	void Set () ;
	
	// Опеределяем поведение виртуальной функции Print_private_field
	void Print_private_field () override {
		cout << " | Адресс -                         | - " << address <<endl;
	}
	
	// Опеределяем поведение виртуальной функции Enter_private_field
	void Enter_private_field () override {
		cout << " | Адресс -                         | - "; cin >> address;
	}	
};
	
