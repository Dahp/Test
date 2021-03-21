#include "Food.h"

//Конструкторы и деструктор
food::food() {
	name = "0";
	callories = 0;
	price = 0;
	ID = 0;
}

food::food(string name, float callories, float price, float proteins, float fats, float carbohydrates, int ID) {
	//Установка значений полей класса Food
	this->name = name;
	this->callories = callories;
	this->price = price;

	//Установка значений полей подкласса Nutriens
	this->nutrients.SetProteins(proteins);//в объект класса Nutriens. мы передаем поле proteins
	this->nutrients.SetFats(fats);
	this->nutrients.SetCarbohydrates(carbohydrates);

	this->ID = id;
	id++;
}

food::food(const food& ob) {
	this->ID = ob.ID;
	this->callories = ob.callories;
	this->name = ob.name;
	this->price = ob.price;
}

food::~food()
{ }

//Перегрузки операторов

food& food::operator=(const food& ob) {
	this->ID = ob.ID;
	this->callories = ob.callories;
	this->name = ob.name;
	this->price = ob.price;

	return *this;//возвращаю ссылку на объект
}

bool food::operator == (const food& ob) {
	if (this->callories == ob.callories && this->name == ob.name && this->price == ob.price)
		return true;
	else 
		return false; 
}

bool operator < (const food& ob, const food& ob2) {
	if (ob.price < ob2.price)
		return true;
	else
		return false;
}

bool operator > (const food& ob, const food& ob2) {
	if (ob.callories > ob2.callories)
		return true;
	else
		return false;
}

ostream& operator << (ostream& out, const food& ob){
	out << ob.name << "\t\t  " << ob.price << "\t\t\t" << ob.callories << "\t\t" << ob.ID;//запись в файл
	return out;
}

istream& operator >> (istream& in, food& ob) {
	in >> ob.name >> ob.price >> ob.callories >> ob.ID;//чтение из файла
	return in;
}