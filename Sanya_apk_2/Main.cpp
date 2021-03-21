#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "time.h"
#include "conio.h"
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>

#define matrix_size 50

void fill_matrix(int matrix_B[matrix_size][matrix_size], int matrix_C[matrix_size][matrix_size]);
void un_optimese_count(int matrix_A[matrix_size][matrix_size], int matrix_B[matrix_size][matrix_size], int matrix_C[matrix_size][matrix_size], int scalar_factor);
int main() {
	srand(time(NULL));
	int matrix_etalon[matrix_size][matrix_size];
	int matrix_A[matrix_size][matrix_size];
	int matrix_B[matrix_size][matrix_size];
	int matrix_C[matrix_size][matrix_size];
	int scalar_factor=1;
	int check_1 = 1, check_2 = 1, iteration_amount;
	
	do {
		system("cls");
		rewind(stdin);
			printf("Iput scalar factor:");
			check_1 = scanf_s("%d", &scalar_factor);
			printf("Input iteration amount:");
			check_2 = scanf_s("%d", &iteration_amount);
	} while (check_1 == 0 && check_2 == 0);
	fill_matrix(matrix_B, matrix_C);
	
	//=---------------C without optimization
	int num_of_cycle = iteration_amount;
	double start_time_1 = clock();
	while (num_of_cycle != 0) {
		un_optimese_count(matrix_A, matrix_B, matrix_C, scalar_factor);
		num_of_cycle--;
	}
	double end_time_1 = clock();
	double search_time_1 = end_time_1 - start_time_1;
	printf("\nTime work C without optimization: %f\n", search_time_1 / 1000);

	//--------------Creating etalon matrix
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			matrix_etalon[i][j] = matrix_A[i][j];
		}
	}
	//---------------------
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			if (matrix_A[i][j] == matrix_etalon[i][j])
				continue;
			else {
				printf("Matrix unmatched!");
				break;
			}
		}
	}
	printf("Matched");

	//--------------C with optimization
	num_of_cycle = iteration_amount;
	double start_time_2 = clock();
	while (num_of_cycle != 0) {
		for (int i = 0; i < matrix_size; i++) {
			for (int j = 0; j < matrix_size; j++) {
				matrix_A[i][j] = matrix_B[i][j] + matrix_C[i][j] * scalar_factor;
			}
		}
		num_of_cycle--;
	}
	double end_time_2 = clock();
	double search_time_2 = end_time_2 - start_time_2;
	printf("\nTime work C with optimization: %f\n", search_time_2 / 1000);

	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			if (matrix_A[i][j] == matrix_etalon[i][j])
				continue;
			else {
				printf("Matrix unmatched!");
				break;
			}
		}
	}
	printf("Matched");

	//----------------MMX
	num_of_cycle = iteration_amount;
	double start_time_3 = clock();
	while (num_of_cycle != 0) {
		_asm
		{
			pusha
			XOR ECX, ECX
			XOR esi, esi
			MOV ECX, (matrix_size* matrix_size)/2
			Loop2 :
			MOVQ mm0, matrix_C[esi]
				MOVQ mm1, scalar_factor
				pmullw mm0,mm1
				paddb mm0, matrix_B[esi]
				MOVD matrix_A[esi], mm0
				ADD esi, 8 //извращенное i++
				LOOP Loop2
				emms
				popa
		}
		num_of_cycle--;
	}
	double end_time_3 = clock();
	double search_time_3 = end_time_3 - start_time_3;
	printf("\nTime work of MMX: %f\n", search_time_3 / 1000);

	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			if (matrix_A[i][j] == matrix_etalon[i][j])
				continue;
			else {
				printf("Matrix unmatched!%d %d \n%d\n%d\n", i, j, matrix_A[i][j], matrix_etalon[i][j]);
				
				break;
			}
		}
	}
	printf("Matched");

	num_of_cycle = iteration_amount;
	double start_time_4 = clock();
	while (num_of_cycle != 0) {
		_asm {
			//
			XOR EAX, EAX
			XOR EBX, EBX
			MOV ECX, matrix_size * matrix_size
			Loop1 :
				MOV EAX, matrix_C[EBX]
				MUL scalar_factor
				ADD EAX, matrix_B[EBX]
				MOV matrix_A[EBX], EAX
				ADD EBX, 4 //извращенное i++
				LOOP Loop1
		}
		num_of_cycle--;
	}
	double end_time_4 = clock();
	double search_time_4 = end_time_4 - start_time_4;
	printf("\nTime work of asm: %f\n", search_time_4 / 1000);

	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			if (matrix_A[i][j] == matrix_etalon[i][j])
				continue;
			else {
				printf("Matrix unmatched!%d %d \n%d\n%d\n", i, j, matrix_A[i][j], matrix_etalon[i][j]);

				break;
			}
		}
	}
	printf("Matched");

	return 0;
}

void fill_matrix(int matrix_B[matrix_size][matrix_size], int matrix_C[matrix_size][matrix_size]) {

	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			matrix_B[i][j] =1 + rand() % 9;
			matrix_C[i][j] =1 +  rand() % 9;
		}
	}
}
#pragma optimize ("", off)
void un_optimese_count(int matrix_A[matrix_size][matrix_size], int matrix_B[matrix_size][matrix_size], int matrix_C[matrix_size][matrix_size], int scalar_factor)
{
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			matrix_A[i][j] = matrix_B[i][j] + matrix_C[i][j] * scalar_factor;
		}
	}
}
#pragma optimize ("", on)