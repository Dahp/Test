#pragma once
#include "Libr.h"

//�����, ������� ����� ����� ������ Food

class Nutrients {//�������� ������ food

public:
	//������������

	//������� � �������
	float GetProteins()const { return proteins; }
	float GetFats()const { return fats; }
	float GetCarbohydrates()const { return carbohydrates; }

	void SetProteins(float proteins) { this->proteins = proteins; }
	void SetFats(float fats) { this->fats = fats; }
	void SetCarbohydrates(float carbohydrates) { this->carbohydrates = carbohydrates; }
	
	//


private:
	float proteins;//����� 
	float fats;//����
	float carbohydrates;//��������


};