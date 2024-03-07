#pragma once

typedef struct
{
	int rows;
	int cols;
	float **data;
} matrix_t;

int matrix_create(matrix_t *matrix, int width, int height);
int matrix_resize(matrix_t *matrix, int width, int height);
int matrix_delete(matrix_t *matrix);
int matrix_clear(matrix_t *matrix);
int matrix_print(matrix_t *matrix);