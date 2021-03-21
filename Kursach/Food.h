#pragma once
#include "Libr.h"
#include "Provision.h"//����������� �����, �� �������� ����������� ����
#include "Nutrients.h"//�������� ������ Food


class food:public provision
{
private:
	Nutrients nutrients;//������ ������ Nutrients


public:
	//������������\�����������
	food();//����������� �� ���������
	food(string name, float callories, float price, float proteins, float fats, float carbohydrates, int ID);//����������� � �����������
	food(const food& ob);//����������� �����������
	~food();

	//������� ������� ����������� �� Provision
	//���� ���� ����������� �� Provision

	//���������� ����������
	food& operator = (const food& ob);//���������� ��������� ������������
	bool operator == (const food& ob);//���������� ��������� ���������
	friend bool operator < (const food& ob, const food& ob2);//���������� ��������� ������ 
	friend bool operator > (const food& ob, const food& ob2);//���������� ��������� ������
	friend ostream& operator << (ostream& out, const food& ob);//���������� ��������� ������(�������� ������/����� ������ ������)
	friend istream& operator >> (istream& in, food& ob);//���������� ��������� �����

	//CRUD
	friend void add(vector<food>& vect_add);
	friend void print_vector(const vector<food>& vect_print);
	friend void update(vector<food>& vect_update);
	friend void del(vector<food>& vect_del);	

	//�����, ������������� �� Provision (��� ����� ����� ���������� �����)
	void pack() {
		cout << "���-��� ����������! ���-���!\n";
	}

};