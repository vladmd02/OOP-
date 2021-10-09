#include"functions_complex.cpp" 

int main () {
	setlocale(LC_ALL, "Russian"); 
	cout << "\t\t Пример использования класса : " << endl; 
	cout << "1) Создание объектов - " << endl;
	Complex value1 (2,  1 );
    Complex value2 (1, -1 );
    
    cout << " - value1 ( 2, 1 ) " << value1 ;
	cout << " - value2 ( 1,-1 ) " << value2 << endl;
	
	cout << "2) Cумма объектов - " << endl;
	cout << " - Резульат : " << value1 + value2 << endl;
 	cout << "   Оператор сложения , который может работать с типом double - " << endl;
	double a = 1.2424;
	cout << " - Резульат : " << value1 + a << endl;
	
	cout << "3) Разность объектов - " << endl;
	cout << " - Резульат : " << value1 - value2 << endl;
 	cout << "   Оператор вычетания , который может работать с типом double - " << endl;
	double b = 2.23;
	cout << " - Резульат : " << value1 - b << endl;
	
 	cout << "4) Произведение объектов - " << endl;
    cout << " - Резульат : " << value1 * value2 << endl;
	cout << "5) Деление объектов - " << endl;
    cout << " - Резульат : "<< value1 / value2 << endl; 
 	
 	cout << "6) Присвоить значение объекта value1 , объекту value2 "<< endl;
 	cout << "  До - " << endl;
 	cout << " - value1 ( 2, 1 ) " <<  value1 ;
	cout << " - value2 ( 1,-1 ) " <<  value2 << endl;
    value2 = value1;
    cout << "  После - " << endl;
    cout << " - value1 ( 2, 1 ) " <<  value1 ;
	cout << " - value2 ( 2, 1 ) " <<  value2 << endl;
	
	cout << "7) Проверить объекты value1 и value2 на равенстсво "<< endl; 
	bool equal = value1 == value2;
	cout << " - Резульат : " << equal << endl << endl;
	
	cout << "8) Префиксный инкримент ( объект value1 ) "<< endl; 
	cout << " - Резульат : " << ++value1 << endl ;

	cout << "9) Постифксный инкримент ( объект value1 ) - при выводе в консоль его значение не должно измениться , \n так как оператор '<<' - имеет бо'льший приоритет "<< endl; 
	cout << " - Резульат : " << value1++ << endl;
	cout << "Но если мы выведем на экран объект ( value1 ) ещё раз - увидим , что оператор отработал верно " << endl;
	cout  << " - Резульат : " << value1 ;
	
	return 0;
}
