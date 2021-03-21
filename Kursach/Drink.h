
#pragma once
#include "Libr.h"
#include "Provision.h"//абстрактный класс от которого наследуетс€ этот

// ласс который будет наследоватьс€

class drink:public provision//public ... - систаксис наследовани€
{

public:
	// онструкторы и деструкторы
	drink();// онструктор по умолчанию
	drink(string name_of_drink, float volume, float price_of_drink, int ID_drink);// онструктор с параметрами
	drink(const drink& ob);// онструктор копировани€
	~drink();

	//ѕерегрузки операторов
	drink& operator = (const drink& ob);//перегрузка оператора присваивани€
	bool operator == (const drink& ob);//перегрузка оператора сравнени€
	friend bool operator < (const drink& ob, const drink& ob2);
	friend bool operator > (const drink& ob, const drink& ob2);
	friend ostream& operator << (ostream& out, const drink& ob);//перегрузка оператора потока вывода
	friend istream& operator >> (istream& in, drink& ob);//перегрузка оператора потока ввода

	//CRUD
	friend void add(vector<drink>& vect_add);
	friend void print_vector(const vector<drink>& vect_print);
	friend void update(vector<drink>& update);
	friend void del(vector<drink>& vect_del);

	//ћетод, наследованный от Provision (тот самый чисто виртульный метод)
	void pack() {
		cout << "Ќапиток запакован! ”ра!\n";
	}
};