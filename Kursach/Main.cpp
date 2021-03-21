#include"Provision.h"
#include "Food.h"
#include "Drink.h"
#include "Person.h"
#include "File.h"
#include "Exception.h"
#include "Autorization.h"

#include "Libr.h"
 
int food::id = 1 ;//это счетчики идишника
int drink::id_drink = 1;//тоже самое

//Функция по проверке ввода консоли
void Menu(int& ch) {
	while (1) {
		cout << " \t\t\t\t\t\t  *МЕНЮ ДЕЙСТВИЙ*  " << endl;
		cout << "---------- |1. Вывести заказы|\n---------- |2. Удалить заказ|\n---------- |3. Изменить заказ|\n---------- |4. Добавить новый заказ|\n---------- ";
		cout << "|5. Сортировать блюда по стоимости (возрастание)|\n---------- |6. Сортировать блюда по калориям(убывание)|\n---------- |7. Сортировать напитки по стоимости|\n---------- |0. Выход из программы|" << endl;
		cin >> ch;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32567, '\n');
		}
		else {
			if (ch <= 7 && ch >= 0) {
				break;
			}
		}
	}
}

//Функция для Try catch
template<class T>
void Trycatch(T& tc) {
	/*Эта функция для проверкти на букву и минимальное число*/
	while (1) {
		try {
			cin >> tc;
			if (tc < 0)
				throw InputException("Can't be negative, try again:", tc);
			if (cin.fail())
				throw InputException("Can't be letter, try again:", tc);
		
			break;
		}
		catch (InputException& ex) {
			cout << ex.what();
			cin.clear();
			cin.ignore(32567, '\n');
		}
	}
}

template<class T>
void Trycatch_3(T& tc) {
	/*Эта функция для проверки на букву и определленый диапозов чисел, в нашем случае 0 - 3*/
	while (1) {
		try {
			cin >> tc;
			if (tc < 0)
				throw InputException("Can't be negative, try again:", tc);
			if (cin.fail())
				throw InputException("Can't be letter, try again:", tc);
			if (tc > 3)
				throw InputException("Try to choose from the suggested:", tc);

			break;
		}
		catch(InputException& ex){
			cout << ex.what();
			cin.clear();
			cin.ignore(32567, '\n');

		}
	}
}

template<class T>
void Trycatch_2(T& tc) {
	/*Эта функция для проверки на букву и определленый диапозов чисел, в нашем случае 0 - 2*/
	while (1) {
		try {
			cin >> tc;
			if (tc < 0)
				throw InputException("Can't be negative, try again:", tc);
			if (tc > 2)
				throw InputException("Try to choose from suggested:", tc);
			if (cin.fail())
				throw InputException("Can't be letter, try again:", tc);

			break;
		}
		catch (InputException& ex){
			cout << ex.what();
			cin.clear();
			cin.ignore(32567, '\n');
		}
	}
}

//Функции для сортировок
bool foo1(const food& ob1, const food& ob2)
{
	return ob1 < ob2;
}

bool foo2(const food& ob1, const food& ob2)
{
	return ob1 > ob2;
}

bool foo3(const drink& ob1, const drink ob2) 
{
	return ob1 > ob2;
}

bool foo4(const drink& ob1, const drink& ob2)
{
	return ob1 > ob2;
}

//--------------------------------------------------CRUD относящийся к Food
void add(vector<food>& vect_add) {
	food ob;
	cout << "Название блюда: ";
	cin >> ob.name;

	cout << "Стоимость блюда: ";
	Trycatch(ob.price);

	cout << "Количество калорий: ";
	Trycatch(ob.callories);

	ob.ID = food::id;
	food::id++;

	vect_add.push_back(ob);
}

void update(vector<food>& vect_update) {
	int temp_ID, flag = 0;
	cout << "Введите ID: ";
	Trycatch(temp_ID);


	for (int i = 0; i < vect_update.size(); i++) {
		if (temp_ID == vect_update[i].GetID()) {
			cout << "Что хотите изменить?: " << endl;
			cout << "1.Название блюда\n2.Стоимость блюда\n3.Количество калорий \n";
			cout << "Ваш выбор:";

			int ch;
			Trycatch_3(ch);

			switch (ch)
			{
			case 1 :
				cout << "Введите новое название блюда: ";
				cin >> vect_update[i].name;
				break;
			case 2:
				cout << "Введите новую стоимость блюда: ";
				Trycatch(vect_update[i].price);
				//cin >> vect_update[i].price;
				break;
			case 3:
				cout << "Введите новое количество калорий у блюда: ";
				Trycatch(vect_update[i].callories);
				//cin >> vect_update[i].callories;
				break;
			}
			flag = 1;
			break;
		}
	}
	if (flag == 0) { cout << "NO_update\n"; }
}

void del(vector<food>& vect_del) {
	int temp_ID, flag = 0;
	cout << "Введите ID блюда: ";
	Trycatch(temp_ID);

	for (auto it = vect_del.begin(); it != vect_del.end(); ++it) {
		if (it->GetID() == temp_ID) {
			vect_del.erase(it);
			flag++;
			break;
		}
	}
	if (flag == 0)
		cout << "Блюда с таким ID нету\n";
}

void print_vector(const vector<food>& vect_print)
{
	for (int i = 0; i < vect_print.size(); i++)
	{
		cout << vect_print[i] << endl;
	}
}

//---------------------------------------------------CRUD относящийся Drink
void add(vector<drink>& vect_add) {
	drink ob;
	cout << "Введите название напитка: ";
	cin >> ob.name_of_drink;

	cout << "Введите стоимость напитка: ";
	Trycatch(ob.price_of_drink);

	cout << "Введите объём напитка: ";
	Trycatch(ob.volume);


	ob.ID_drink = drink::id_drink;
	drink::id_drink++;
	vect_add.push_back(ob);
}

void update(vector<drink>& vect_update) {
	int temp_ID_drink, flag = 0;
	cout << "Введите ID: ";
	Trycatch(temp_ID_drink);

	for (int i = 0; i < vect_update.size(); i++) {
		if (temp_ID_drink == vect_update[i].GetID_drink()) {
			cout << "Что хотите изменить?: " << endl;
			cout << "1.Название напитка\n2.Стоимость напитка\n3.Обём напитка \n";
			cout << "Ваш выбор:";
			int ch;
			Trycatch_3(ch);

			switch (ch) {
			case 1:
				cout << "EВведите новое название напитка: ";
				cin >> vect_update[i].name_of_drink;
				break;
			case 2:
				cout << "Введите новую стоимость напитка: ";
				Trycatch(vect_update[i].price_of_drink);
				break;
			case 3:
				cout << "Введите новый объём напитка: ";
				Trycatch(vect_update[i].volume);
				//cin >> vect_update[i].volume;
				break;
			
			}

		}
	}
}

void del(vector<drink>& vect_del) {
	int temp_ID_drink, flag2 = 0;
	cout << "Введите ID напитка: ";
	Trycatch(temp_ID_drink);

	for (auto it = vect_del.begin(); it != vect_del.end(); ++it) {
		if (it->GetID_drink() == temp_ID_drink) {
			vect_del.erase(it);//erase - это удаление по индексу
			flag2++;
			break;
		}
	}
	if (flag2 == 0)
		cout << "Напитка с таким ID нету\n";
}

void print_vector(const vector<drink>& vect_print) {
	for (int i = 0; i < vect_print.size(); i++) 
	{
		cout << vect_print[i] << "\t" << endl;
	}
}

//---------------------------------Меню

void Print_menu(vector<food>& ob_food, vector<drink>& ob_drink) {
	cout << "*************************************************************************************" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "|                    *Список Блюд*                      |" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "| Имя |     Стоимость, $        |  Кол-во калорий   |   ID" << endl;
	cout << "----------------------------------------------------------------" << endl;
	print_vector(ob_food);
	cout << "----------------------------------------------------------------" << endl;
	cout << "******************************************************************************" << endl << endl;

	cout << "**************************************************************************************" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "|                    *Список Напитков*                      |" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "| Имя |     Стоимость, $        |  Объем, мл   |   ID" << endl;
	cout << "----------------------------------------------------------------" << endl;
	print_vector(ob_drink);
	cout << "----------------------------------------------------------------" << endl;
	cout << "********************************************************************************" << endl << endl;
}

void print_food(vector<food>& ob_food) {
	cout << "*************************************************************************************" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "|                    *Список Блюд*                      |" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "| Имя |     Стоимость, $        |  Кол-во калорий   |   ID" << endl;
	cout << "----------------------------------------------------------------" << endl;
	print_vector(ob_food);
	cout << "----------------------------------------------------------------" << endl;
	cout << "******************************************************************************" << endl << endl;

}

void print_drink(vector<drink>& ob_drink) {
	cout << "**************************************************************************************" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "|                    *Список Напитков*                      |" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "| Имя |     Стоимость, $        |  Объем, мл   |   ID" << endl;
	cout << "----------------------------------------------------------------" << endl;
	print_vector(ob_drink);
	cout << "----------------------------------------------------------------" << endl;
	cout << "********************************************************************************" << endl << endl;
}


//-----------------------------------------------------------------------------------Int main()-----------------------------------------------------------
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//autorization ob;

	//ob.Autorization();
	//


	//Объекты классов
	vector<food> ob_food;
	vector<drink> ob_drink;

	File<food> filefood("food.txt");//Объект класса File, тут он открывается
	filefood.get(ob_food);//Записываю информацию из файлы

	File<drink> filedrink("drink.txt");
	filedrink.get(ob_drink);



	int ch;
	do
	{
		Print_menu(ob_food, ob_drink);
		Menu(ch);
		switch (ch)
		{
		case 1:
			system("CLS");
			Print_menu(ob_food, ob_drink);
			break;
		case 2:
			system("CLS");
			Print_menu(ob_food, ob_drink);
			del(ob_food);
			del(ob_drink);
			break;
		case 3:
			system("CLS");
			int key;
			Print_menu(ob_food, ob_drink);
			cout << "Что хотите изменить?\t1.Еда\t2.Напиток\n Ваш выбор: ";
			Trycatch_2(key);
			switch (key) {
			case 1:
				system("CLS");
				print_food(ob_food);
				update(ob_food);
				break;
			case 2:
				system("CLS");
				print_drink(ob_drink);
				update(ob_drink);
				break;
			}
			break;
		case 4:
			system("CLS");
			add(ob_food);
			add(ob_drink);
			break;
		case 5:
			system("CLS");
			sort(ob_food.begin(), ob_food.end(), foo1);//по возрастанию стоимости
			break;
		case 6:
			system("CLS");
			sort(ob_food.begin(), ob_food.end(), foo2);//по убыванию каллорий
			break;
		case 7:
			system("CLS");
			int IncDec;
			cout << "1.- По возрастанию\n2.- По убыванию\n Ваш выбор: ";
			Trycatch_2(IncDec);
			switch (IncDec) {
			case 1:
				sort(ob_drink.begin(), ob_drink.end(), foo3);
				break;
			case 2:
				sort(ob_drink.begin(), ob_drink.end(), foo4);
				break;
			}
			break;

		case 0:
			break;
		}
	} while (ch != 0);

	filefood.save(ob_food);//сохранение изменений в файле, запись в файл
	filedrink.save(ob_drink);
}