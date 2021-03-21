
#pragma once
#include "Libr.h"
#include "Provision.h"//����������� ����� �� �������� ����������� ����

//����� ������� ����� �������������

class drink:public provision//public ... - ��������� ������������
{

public:
	//������������ � �����������
	drink();//����������� �� ���������
	drink(string name_of_drink, float volume, float price_of_drink, int ID_drink);//����������� � �����������
	drink(const drink& ob);//����������� �����������
	~drink();

	//���������� ����������
	drink& operator = (const drink& ob);//���������� ��������� ������������
	bool operator == (const drink& ob);//���������� ��������� ���������
	friend bool operator < (const drink& ob, const drink& ob2);
	friend bool operator > (const drink& ob, const drink& ob2);
	friend ostream& operator << (ostream& out, const drink& ob);//���������� ��������� ������ ������
	friend istream& operator >> (istream& in, drink& ob);//���������� ��������� ������ �����

	//CRUD
	friend void add(vector<drink>& vect_add);
	friend void print_vector(const vector<drink>& vect_print);
	friend void update(vector<drink>& update);
	friend void del(vector<drink>& vect_del);

	//�����, ������������� �� Provision (��� ����� ����� ���������� �����)
	void pack() {
		cout << "������� ���������! ���!\n";
	}
};