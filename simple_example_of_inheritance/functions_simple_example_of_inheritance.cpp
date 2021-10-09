#include"Header_simple_example_of_inheritance.h"

//=======================================================================================================================================
// Методы абстрактного базового класса - Educational_Institution

	// ctor по умолчанию
Educational_Institution::Educational_Institution () { 
		name = "Not definitely"; // задаем начальные значения полей 
		number_of_students = price_per_contract = budget_place = 0;
	}
	
	// констурктор с параметрами , который принимает , к примеру - 4 параметра 
Educational_Institution::Educational_Institution (string Name , int Number_of_students , int Price_per_contract , int Budget_place ) {
		name = Name;
		number_of_students = Number_of_students;
		price_per_contract = Price_per_contract;
		budget_place = Budget_place;
	}
	
	// ctor копирования . Учитывая то , что в нашем классе нет указателей , то у нас впринципе не был необходимости его перегружать 
Educational_Institution::Educational_Institution (const Educational_Institution &anything ) { 
		name = anything.name;
		number_of_students = anything.number_of_students;
		price_per_contract = anything.price_per_contract;
		budget_place = anything.budget_place;
	}
	
	// перегруженый оператор = ( тоже могли не перегружать )	 
Educational_Institution & Educational_Institution::operator = (const Educational_Institution &other ) { 
		name = other.name;
		number_of_students = other.number_of_students;
		price_per_contract = other.price_per_contract;
		budget_place = other.budget_place;
		return *this; // возврашаем разыменованный указатель на сам объект
	}
	
	// Я не писал функцию Changer , так как в данном случае , мы нигде не выделяем память , соответсвенно - тело функции Set и Сhanger - будет полностью одинаковым. 
	// функция Set применятся как для установки значений объектов , так и для их изменения.
void Educational_Institution::Set  () {
		string Name; // эти переменные будут своеобразным "буфером"
		int Number_of_students , Price_per_contract; 
		bool Budget_place; 
		
		// тут просто указываем значения , и записываем в наши поля 
		cout << endl;
//		cout << " Установите / Измените данные объекта :" << endl;
		cout << " | Название учебного заведения      | - ";
		cin >> Name;
		name = Name;
		cout << " | Колличество студентов            | - ";
		cin >> Number_of_students;
		number_of_students = Number_of_students;
		cout << " | Цена за контракт                 | - ";
		cin >> Price_per_contract;
		price_per_contract = Price_per_contract;
		cout << " | Возможность обучения на бюджете  | - "; 
		cin >> Budget_place;
		budget_place = Budget_place;
	}
//=======================================================================================================================================
// Дружественные функции - ввода / вывода

ostream& operator << ( std::ostream& os , Educational_Institution & Ed_In ) { // вывод в поток 
	os << endl;
	os << " |==================================|"<< endl;
   	os << " | Название учебного заведения      | - "<< Ed_In.name << endl;
   	os << " | Колличество студентов            | - "<< Ed_In.number_of_students << endl;
   	os << " | Цена за контракт                 | - "<< Ed_In.price_per_contract <<endl;
   	os << " | Возможность обучения на бюджете  | - "<< Ed_In.budget_place << endl;
   	Ed_In.Print_private_field(); // приницп подстановки . ( ссылка на базовый класс может ссылаться на любых своих потомков )
   	os << " |==================================|"    << endl  ;
	return os; 
	}
	
istream& operator >> ( std::istream& is ,  Educational_Institution & Ed_In ) {   // ввод
	cout << endl;
    cout << " Введите пожалуйста данные объекта - "<< endl;
  	cout << " |==================================|"<< endl;
  	cout << " | Название учебного заведения      | - "; is >> Ed_In.name;
   	cout << " | Колличество студентов            | - "; is >> Ed_In.number_of_students ;
   	cout << " | Цена за контракт                 | - "; is >> Ed_In.price_per_contract ;
   	cout << " | Возможность обучения на бюджете  | - "; is >> Ed_In.budget_place; 
   	Ed_In.Enter_private_field(); 
   	cout << " |==================================|"<< endl << endl;	
    return is; 
	}
	
//=======================================================================================================================================
// Методы производного класса - Preschool_educational_institution	

// перегруженый оператор =
Preschool_educational_institution & Preschool_educational_institution::operator = (const Preschool_educational_institution &other ) { 
		Educational_Institution::operator= (other); // явно вызываем оператор присваивания базового класса , чтобы выполнить присваивание , для полей базового класса , с модификатором private 
		groops = other.groops; // а далее просто присвиваем значение объекта other - нашему текущему объекту
		return *this; 
	}
	
	// Функция установки полей объекта 
void Preschool_educational_institution::Set () { 
		Educational_Institution::Set(); // тут мы явно вызываем метод базового класса , чтобы установить значения для полей , котрые находятся в private секции базового класса Educational_Institution
		int Groops; // а уже после того , когда мы установили поля для базового класса - можем установить поле groops (производного класса)
		Enter_private_field(); // метод , который устанавливает значение поля groops
	}
	
//=======================================================================================================================================
// Методы производного класса - Secondary_educational_institution	

	// перегруженый оператор =
Secondary_educational_institution & Secondary_educational_institution::operator = (const Secondary_educational_institution &other ) { 
		Educational_Institution::operator= (other); // вызываем оператор присваивания базового класса , чтобы выполнить присваивание , для полей базового класса , с модификатором private 
		average_score = other.average_score; // а далее просто присвиваем поле groops 
		return *this; 
	}
		
	// Функция установки полей объекта 
void Secondary_educational_institution::Set () {
		Educational_Institution::Set(); // вот тут мы явно вызываем метод базового класса , чтобы установить значения для полей , котрые находятся в private секции базового класса Educational_Institution
		float Average_score; // а уже после того , как мы установили поля для базового класса - можем установить поле average_score (производного класса)
		Enter_private_field(); // метод , который устанавливает значения поля average_score
	}
	
//=======================================================================================================================================
// Методы производного класса - Higher_education_institution

	// перегруженый оператор =
Higher_education_institution & Higher_education_institution::operator = (const Higher_education_institution &other ) { 
		Educational_Institution::operator= (other); // вызываем оператор присваивания базового класса , чтобы выполнить присваивание , для полей базового класса , с модификатором private 
		address = other.address; // а далее просто присвиваем поле address 
		return *this; 
	}
		
	// Функция установки полей объекта 
void Higher_education_institution::Set () { 
		Educational_Institution::Set(); // вот тут мы явно вызываем метод базового класса , чтобы установить значения для полей , котрые находятся в private секции базового класса Educational_Institution
		string Address; // а уже после того , как мы установили поля для базового класса - можем установить поле groops (производного класса)
		Enter_private_field();
	}	

