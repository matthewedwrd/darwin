#pragma once

typedef struct
{
	int rows, columns;
	float **data;
} matrix_t;

typedef struct
{
	int length;
	float *data;
} vector_t;

int matrix_create(matrix_t *matrix);
void matrix_random(matrix_t *matrix);
int matrix_multiply(matrix_t *result, matrix_t *matrix0, matrix_t *matrix1);
int matrix_add(matrix_t *result, matrix_t *matrix0, matrix_t *matrix1);
int matrix_delete(matrix_t *matrix);
int matrix_print(matrix_t *matrix);