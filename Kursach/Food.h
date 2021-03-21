#pragma once
#include "Libr.h"
#include "Provision.h"//абстрактный класс, от которого наследуется этот
#include "Nutrients.h"//подкласс класса Food


class food:public provision
{
private:
	Nutrients nutrients;//объект класса Nutrients


public:
	//Конструкторы\деструкторы
	food();//Конструктор по умолчанию
	food(string name, float callories, float price, float proteins, float fats, float carbohydrates, int ID);//конструктор с параметрами
	food(const food& ob);//констурктор копирования
	~food();

	//Геттеры сеттеры наследуются от Provision
	//Поля тоже наследуются от Provision

	//Перегрузки операторов
	food& operator = (const food& ob);//перегрузка оператора присваивания
	bool operator == (const food& ob);//перегрузка оператора сравнения
	friend bool operator < (const food& ob, const food& ob2);//перегрузка оператора меньше 
	friend bool operator > (const food& ob, const food& ob2);//перегрузка оператора больша
	friend ostream& operator << (ostream& out, const food& ob);//перегрузка оператора вывода(передача потока/какой объект вывожу)
	friend istream& operator >> (istream& in, food& ob);//перегрузка оператора ввода

	//CRUD
	friend void add(vector<food>& vect_add);
	friend void print_vector(const vector<food>& vect_print);
	friend void update(vector<food>& vect_update);
	friend void del(vector<food>& vect_del);	

	//Метод, наследованный от Provision (тот самый чисто виртульный метод)
	void pack() {
		cout << "Ням-ням запаковано! Ура-Ура!\n";
	}

};