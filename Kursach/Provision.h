#pragma once
#include "Libr.h"
//�������� ������ �� �������� ����� ������������� ��� ��� ������ "Drink" � "Food"

class provision 
{
public:
	//������� � ������� ������ "Food"
	string GetName() const { return name; }
	void SetName(string name) { this->name = name; }

	float GetCallories() const { return callories; }
	void SetCallories(float callories) { this->callories = callories; }

	float GetPrice() const { return price; }
	void SetPrice(float price) { this->price = price; }

	int GetID() const { return ID; }

	//������� � ������� ������ "Drink"
	float GetVolume()const { return volume; }
	void SetVolume(float volume) { this->volume = volume; }

	string GetName_of_drink()const { return name_of_drink; }
	void SetName_of_drink(string name_of_drink) { this->name_of_drink = name_of_drink; }

	int GetID_drink() const { return ID_drink; }

	
	//����� ����������� �����
	virtual void pack() = 0;//����� 0 ��� ��� ��� ��������� ������������ ������

protected://���� ����� ��� � private, ������ ������������ ��� ������������
	//���� ������ "Food"
	string name;
	float callories;
	float price;
	int ID;
	static int id;

	//���� ������ "Drink"
	string name_of_drink;
	float volume;
	float price_of_drink;
	int ID_drink;
	static int id_drink;
};