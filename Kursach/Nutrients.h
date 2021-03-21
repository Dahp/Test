#pragma once
#include "Libr.h"

//класс, который будет полем класса Food

class Nutrients {//подкласс класса food

public:
	//Конструкторы

	//Геттеры и Сетторы
	float GetProteins()const { return proteins; }
	float GetFats()const { return fats; }
	float GetCarbohydrates()const { return carbohydrates; }

	void SetProteins(float proteins) { this->proteins = proteins; }
	void SetFats(float fats) { this->fats = fats; }
	void SetCarbohydrates(float carbohydrates) { this->carbohydrates = carbohydrates; }
	
	//


private:
	float proteins;//белки 
	float fats;//жиры
	float carbohydrates;//углеводы


};