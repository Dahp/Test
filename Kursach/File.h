#pragma once
#include "Libr.h"


template <typename T>							//��������� �����
class File
{
public:
	File(string path);
	~File();
	void get(vector<T>& vc);
	void save(const vector<T>& vc);
private:
	string path;                                // ���� � �����
	fstream finout;								//����� ��� ����� � ������
};

template<typename T>
File<T>::File(string path)
{
	this->path = path;
	finout.open(path, fstream::in | fstream::out | fstream::app);
	if (!finout.is_open()) {
		//throw FileException("Wrong path", path);					//���� ���� �� �������� ����������� ����������
	}
}

template<typename T>
File<T>::~File()
{
	finout.close();
}

template<typename T>
void File<T>::get(vector<T>& vc)						//����� ���������� � ������ ���������� �� �����
{
	vc.clear();
	T tmp;
	while (!finout.eof())								// ���� �� ����� �����
	{
		finout >> tmp;									//��������� �� ����� � tmp
		vc.push_back(tmp);								//������ � ������
	}
	vc.pop_back();										//��������� ������� ����� ������������� ,������� ���
}

template<typename T>
void File<T>::save(const vector<T>& vc)										// ������ �� ������� � ����
{
	finout.close();
	finout.open(path, fstream::in | fstream::out | fstream::trunc);              //��������� ������ ������ ����  , trunc ������� ���� ������� �� ��������� , app �� �������, in � out �������� ��� �� ����� ��������� � ���������� � ����
	for (auto& el : vc)
	{
		finout << el << "\n";
	}
	finout.close();
	finout.open(path, fstream::in | fstream::out | fstream::app);				//��������� ��� ���� ������ � app 
}