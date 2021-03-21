#pragma once
#include "Libr.h"
//Описание класса от которого будет наследоваться еще два класса "Drink" и "Food"

class provision 
{
public:
	//Геттеры и сеттеры класса "Food"
	string GetName() const { return name; }
	void SetName(string name) { this->name = name; }

	float GetCallories() const { return callories; }
	void SetCallories(float callories) { this->callories = callories; }

	float GetPrice() const { return price; }
	void SetPrice(float price) { this->price = price; }

	int GetID() const { return ID; }

	//Геттеры и сеттеры класса "Drink"
	float GetVolume()const { return volume; }
	void SetVolume(float volume) { this->volume = volume; }

	string GetName_of_drink()const { return name_of_drink; }
	void SetName_of_drink(string name_of_drink) { this->name_of_drink = name_of_drink; }

	int GetID_drink() const { return ID_drink; }

	
	//Чисто виртуальный метод
	virtual void pack() = 0;//равно 0 так как это синтаксис виртуального метода

protected://тоже самое что и private, только используется при наследовании
	//Поля класса "Food"
	string name;
	float callories;
	float price;
	int ID;
	static int id;

	//Поля класса "Drink"
	string name_of_drink;
	float volume;
	float price_of_drink;
	int ID_drink;
	static int id_drink;
};