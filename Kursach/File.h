#pragma once
#include "Libr.h"


template <typename T>							//Шаблонный класс
class File
{
public:
	File(string path);
	~File();
	void get(vector<T>& vc);
	void save(const vector<T>& vc);
private:
	string path;                                // путь к файлу
	fstream finout;								//поток для ввода и вывода
};

template<typename T>
File<T>::File(string path)
{
	this->path = path;
	finout.open(path, fstream::in | fstream::out | fstream::app);
	if (!finout.is_open()) {
		//throw FileException("Wrong path", path);					//Если файл не открылся выбрасываем исключение
	}
}

template<typename T>
File<T>::~File()
{
	finout.close();
}

template<typename T>
void File<T>::get(vector<T>& vc)						//Метод записывает в вектор информацию из файла
{
	vc.clear();
	T tmp;
	while (!finout.eof())								// Пока не конец файла
	{
		finout >> tmp;									//Считываем из файла в tmp
		vc.push_back(tmp);								//Запись в вектор
	}
	vc.pop_back();										//Последний элемент будет дублироваться ,удаляем его
}

template<typename T>
void File<T>::save(const vector<T>& vc)										// Запись из вектора в файл
{
	finout.close();
	finout.open(path, fstream::in | fstream::out | fstream::trunc);              //Открываем заново ПУСТОЙ файл  , trunc очищает файл который мы открываем , app не очищает, in и out означают что мы будем считывать и записывать в файл
	for (auto& el : vc)
	{
		finout << el << "\n";
	}
	finout.close();
	finout.open(path, fstream::in | fstream::out | fstream::app);				//Открываем наш файл заново с app 
}