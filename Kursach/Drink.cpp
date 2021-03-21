#include"Drink.h"

//������������ � �����������
drink::drink() {
	volume = 0;
	name_of_drink = "0";
	price_of_drink = 0;
	ID_drink = 0;
}

drink::drink(string name_of_drink, float volume, float price_of_drink, int ID_drink) {
	//��������� �������� ����� ������ "Drink"
	this->volume = volume;
	this->name_of_drink = name_of_drink;
	this->price_of_drink = price_of_drink;
	this->ID_drink = ID_drink;
}

drink::drink(const drink& ob) {
	this->name_of_drink = ob.name_of_drink;
	this->volume = ob.volume;
	this->price_of_drink = ob.price_of_drink;
	this->ID_drink = ob.ID_drink;
}

drink::~drink()
{ }

//���������� ����������
drink& drink::operator = (const drink& ob) {
	this->volume = ob.volume;
	this->name_of_drink = name_of_drink;

	return *this;//������ �� ������
}

bool drink::operator == (const drink& ob) {
	if (this->volume == ob.volume && this->name_of_drink == ob.name_of_drink && this->price_of_drink == price_of_drink)
		return true;
	else
		return false;
}

bool operator < (const drink& ob, const drink& ob2) {
	if (ob.volume < ob2.volume)
		return true;
	else
		return false;
}

bool operator > (const drink& ob, const drink& ob2) {
	if (ob.volume > ob.volume)
		return true;
	else
		return false;
}

ostream& operator << (ostream& out, const drink& ob) {
	out << ob.name_of_drink << "\t\t" << ob.price_of_drink << "\t\t\t" << ob.volume   << "\t\t" << ob.ID_drink;//������ �� �����
	return out;
}

istream& operator >> (istream& in, drink& ob) {
	in >> ob.name_of_drink >> ob.price_of_drink >> ob.volume >> ob.ID_drink;//������ � ����
	return in;
}