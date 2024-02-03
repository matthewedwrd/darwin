#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>

#include <darwin/matrix.h>
#include <darwin/endl.h>
#include <darwin/seed.h>

int matrix_create(matrix_t* matrix)
{
	matrix->data = malloc(matrix->rows * sizeof(float*));
	if(matrix->data == NULL)
	{
		return -1;
	}

	for (int i = 0; i < matrix->rows; i++)
	{
		matrix->data[i] = malloc(matrix->columns * sizeof(float));
		if(matrix->data[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				free(matrix->data[j]);
			}
			free(matrix->data);
			return -1;
		}
	}

	return 0;
}

int matrix_random(matrix_t* matrix)
{
	if(matrix == NULL || matrix->data == NULL)
	{
		return -1;
	}

	srand(g_seed += g_seed);

	for(int i = 0; i < matrix->rows; i++)
	{
		for(int j = 0; j < matrix->columns; j++)
		{
			if(matrix->data[i] == NULL)
			{
				return -1;
			}

			int rand_int = rand();
			matrix->data[i][j] = (float)rand_int / RAND_MAX;
		}
	}

	return 0;
}

int matrix_add(matrix_t *result, matrix_t *matrix0, matrix_t *matrix1)
{
	if(matrix0->rows != matrix1->rows || matrix0->columns != matrix1->columns)
	{
		return -1;
	}

	for(int i = 0; i < result->rows; i++)
	{
		for(int j = 0; j < result->columns; j++)
		{
			result->data[i][j] = matrix0->data[i][j] + matrix1->data[i][j];
		}
	}

	return 0;
}

int matrix_multiply(matrix_t* result, matrix_t* matrix0, matrix_t* matrix1)
{
	if(matrix0->columns != matrix1->rows)
	{
		return -1;
	}

	for(int i = 0; i < matrix0->rows; i++)
	{
		for(int j = 0; j < matrix1->columns; j++)
		{
			result->data[i][j] = 0.0f;
			for(int k = 0; k < matrix0->columns; k++)
			{
				result->data[i][j] += matrix0->data[i][k] * matrix1->data[k][j];
			}
		}
	}

	return 0;
}

int matrix_delete(matrix_t *matrix)
{
	if(matrix->data != NULL)
	{
		for(int i = 0; i < matrix->rows; i++)
		{
			free(matrix->data[i]);
		}

		free(matrix->data);

		return 0;
	}

	return -1;
}

int matrix_print(matrix_t *matrix)
{
	if (!matrix->data)
	{
		return -1;
	}

	for (int i = 0; i < matrix->rows; i++)
	{
		printf("[");
		for(int j = 0; j < matrix->columns; j++)
		{
			printf("%.2f", matrix->data[i][j]);

			if(j < matrix->columns - 1)
			{
				printf(", ");
			}
		}
		printf("]" ENDL);
	}
	printf(ENDL);

	return 0;
}