#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "time.h"
#include "conio.h"
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>

#define size_of_matrix 10

void fill_matrix(int matrix_1[size_of_matrix][size_of_matrix], int matrix_2[size_of_matrix][size_of_matrix]);
void print_matrix(int matrix_1[size_of_matrix][size_of_matrix], int matrix_2[size_of_matrix][size_of_matrix], int matrix_3[size_of_matrix][size_of_matrix]);
void sum_matrix(int matrix_1[size_of_matrix][size_of_matrix], int matrix_2[size_of_matrix][size_of_matrix], int matrix_3[size_of_matrix][size_of_matrix]);


int main() {

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int c = 0;
	int number_of_cycles, noc;
	int matrix_1[size_of_matrix][size_of_matrix], matrix_2[size_of_matrix][size_of_matrix], matrix_3[size_of_matrix][size_of_matrix], matrix_reference[size_of_matrix][size_of_matrix];
	
	
	do {
		system("cls");
		rewind(stdin);
		printf("The number of cycles: ");
		c = scanf_s("%d", &number_of_cycles);
		noc = number_of_cycles;
		
	} while (c == 0);

	fill_matrix(matrix_1, matrix_2);

	//----------------C
	double start_time = clock();
	while (noc != 0) {
		sum_matrix(matrix_1, matrix_2, matrix_3);
		noc--;
	}
	double end_time = clock();
	double search_time = end_time - start_time;
	printf("\nВремя работы просто С: %f\n", search_time / 1000);

	 //-----------------
	for (int i = 0; i < size_of_matrix; i++) {
		for (int j = 0; j < size_of_matrix; j++) {
			matrix_reference[i][j] = matrix_3[i][j];
		}
	}
	//--------------
	for (int i = 0; i < size_of_matrix; i++) {
		for (int j = 0; j < size_of_matrix; j++) {
			if (matrix_3[i][j] != matrix_reference[i][j]) {
				printf("Не совпадают");
				break; break;
			}
			else{
				continue;
			}
		}
	}
	printf("Совпадают");
	//----------------C with optimize
	noc = number_of_cycles;
	double start_time2 = clock();
	while (noc != 0) {
		for (int i = 0; i < size_of_matrix; i++) {
			for (int j = 0; j < size_of_matrix; j++) {
				matrix_3[i][j] = matrix_1[i][j] - matrix_2[i][j];
			}
		}
		noc--;
	}
	double end_time2 = clock();
	double search_time2 = end_time2 - start_time2;
	printf("\nВремя работы С c оптимизацией: %f\n", search_time2 / 1000);

	for (int i = 0; i < size_of_matrix; i++) {
		for (int j = 0; j < size_of_matrix; j++) {
			if (matrix_3[i][j] != matrix_reference[i][j]) {
				printf("Не совпадают");
				break;
			}
			else {
				continue;
			}
		}
	}
	printf("Совпадают");


	//----------------MMX
	noc = number_of_cycles;
	double start_time3 = clock();
	while (noc != 0) {
		_asm {
			xor edx, edx
			mov ecx, (size_of_matrix * size_of_matrix) / 2
			add_loop:
			movq mm1, matrix_1[edx]
				psubd mm1, matrix_2[edx]
				movq matrix_3[edx], mm1
				add edx, 8
				loop add_loop

				emms
		}
		noc--;	
	}
	double end_time3 = clock();
	//Костыль, оно все портил
	/*for (int i = 0; i < size_of_matrix; i++)
	{
		for (int j = 0; j < size_of_matrix; j++)
		{
			if (matrix_3[i][j] > 200)
			{
				matrix_3[i][j] -= 256;
			}
		}
	}*/

	double search_time3 = end_time3 - start_time3;
	printf("\nВремя работы MMX: %f\n", search_time3 / 1000);

	for (int i = 0; i < size_of_matrix; i++) {
		for (int j = 0; j < size_of_matrix; j++) {
			if (matrix_3[i][j] != matrix_reference[i][j]) {
				printf("Не совпадают");
				break;
			}
			else {
				continue;
			}
		}
	}
	printf("Совпадают");

	
	//----------------Asm
	noc = number_of_cycles;
	double start_time4 = clock();
	while (noc != 0) {
		_asm {
			XOR EDX, EDX //
			MOV ECX, size_of_matrix* size_of_matrix
			ADD_LOOP1 :
			MOV EAX, matrix_1[EDX]
				SUB EAX, matrix_2[EDX]
				MOV matrix_3[EDX], EAX
				ADD EDX, 4//извращенное i++
				LOOP ADD_LOOP1
		}
		noc--;
	}
	double end_time4 = clock();
	double search_time4 = end_time4 - start_time4;
	printf("\nВремя работы Asm: %f\n", search_time4 / 1000);

	for (int i = 0; i < size_of_matrix; i++) {
		for (int j = 0; j < size_of_matrix; j++) {
			if (matrix_3[i][j] != matrix_reference[i][j]) {
				printf("Не совпадают");
				break;
			}
			else {
				continue;
			}
		}
	}
	printf("Совпадают");


	return 0;
}

void fill_matrix(int matrix_1[size_of_matrix][size_of_matrix], int matrix_2[size_of_matrix][size_of_matrix]) {

	for (int i = 0; i < size_of_matrix; i++) {
		for (int j = 0; j < size_of_matrix; j++) {
			matrix_1[i][j] = rand()%10;
			matrix_2[i][j] = rand()%10;
		}
	}
}

void print_matrix(int matrix_1[size_of_matrix][size_of_matrix], int matrix_2[size_of_matrix][size_of_matrix], int matrix_3[size_of_matrix][size_of_matrix]) {
	for (int i = 0; i < size_of_matrix; i++) {
		for (int j = 0; j < size_of_matrix; j++) {
			printf("%d", matrix_1[i][j]);
			printf(" ");
		}
		printf("\n");
	}

	printf("----------\n");

	for (int i = 0; i < size_of_matrix; i++) {
		for (int j = 0; j < size_of_matrix; j++) {
			printf("%d", matrix_2[i][j]);
			printf(" ");
		}
		printf("\n");
	}

	printf("----------\n");

	for (int i = 0; i < size_of_matrix; i++) {
		for (int j = 0; j < size_of_matrix; j++) {
			printf("%d", matrix_3[i][j]);
			printf(" ");
		}
		printf("\n");
	}
}

#pragma optimize("", off)
void sum_matrix(int matrix_1[size_of_matrix][size_of_matrix], int matrix_2[size_of_matrix][size_of_matrix], int matrix_3[size_of_matrix][size_of_matrix]) {
	for (int i = 0; i < size_of_matrix; i++) {
		for (int j = 0; j < size_of_matrix; j++) {
			matrix_3[i][j] = matrix_1[i][j] - matrix_2[i][j];
		}
	}
}
#pragma optimize("", on)

