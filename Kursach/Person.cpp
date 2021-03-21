#include "Person.h"
//Конструкторы и деструкторы

person::person() {
	full_name_of_the_payer = "0";
	addres = "0";
	type_of_delivery = "0";
}

person::person(string full_name_of_the_payer, string addres, string type_of_delivery) {
	//Установка значений полей класса Person
	this->full_name_of_the_payer = full_name_of_the_payer;
	this->addres = addres;
	this->type_of_delivery = type_of_delivery;
}

person::person(const person& ob) {
	this->full_name_of_the_payer = ob.full_name_of_the_payer;
	this->addres = ob.addres;
	this->type_of_delivery = type_of_delivery;
}

person::~person()
{ }