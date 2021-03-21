#pragma once
#include "Libr.h"

//Отдельный класс описывающий все что касается клиента

class person
{
private:
	string full_name_of_the_payer;
	string addres;
	string type_of_delivery;

public:
	//Конструкторы и деструкторы
	person();//конструктор по умолчанию
	person(string full_name_of_payer, string addres, string type_of_delivery);//конструктор с параметрами
	person(const person& ob);//конструктор копирования
	~person();
	//Геттеры и Сетторы
	string GetAddres() const { return addres; }
	string GetType_of_delivery()const { return type_of_delivery; }
	string GetFull_name_of_payer()const { return full_name_of_the_payer; }

	void SetAddres(string addres) { this->addres = addres; }
	void SetType_of_delivery(string type_of_delivery) { this->type_of_delivery = type_of_delivery; }
	void SetFull_name_of_payer(string full_name_of_payer) { this->full_name_of_the_payer = full_name_of_payer; }

	//Перегрузки операторов

	//CRUD
};

