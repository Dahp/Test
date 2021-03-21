#include "Food.h"

//������������ � ����������
food::food() {
	name = "0";
	callories = 0;
	price = 0;
	ID = 0;
}

food::food(string name, float callories, float price, float proteins, float fats, float carbohydrates, int ID) {
	//��������� �������� ����� ������ Food
	this->name = name;
	this->callories = callories;
	this->price = price;

	//��������� �������� ����� ��������� Nutriens
	this->nutrients.SetProteins(proteins);//� ������ ������ Nutriens. �� �������� ���� proteins
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

//���������� ����������

food& food::operator=(const food& ob) {
	this->ID = ob.ID;
	this->callories = ob.callories;
	this->name = ob.name;
	this->price = ob.price;

	return *this;//��������� ������ �� ������
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
	out << ob.name << "\t\t  " << ob.price << "\t\t\t" << ob.callories << "\t\t" << ob.ID;//������ � ����
	return out;
}

istream& operator >> (istream& in, food& ob) {
	in >> ob.name >> ob.price >> ob.callories >> ob.ID;//������ �� �����
	return in;
}