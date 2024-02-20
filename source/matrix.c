#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include <darwin/matrix.h>
#include <darwin/endl.h>

int matrix_create(matrix_t *matrix, int width, int height)
{
	matrix->data = malloc((height * sizeof(float *)) + (height * width * sizeof(float)));
	if(matrix->data == NULL)
	{
		return -1;
	}

	for(int i = 0; i < height; i++)
	{
		matrix->data[i] = (float *)(matrix->data + height) + i * width;
	}

	return 0;
}

int matrix_resize(matrix_t *matrix, int width, int height)
{
	float **data = malloc((height * sizeof(float *)) + (height * width * sizeof(float)));
	if(data == NULL)
	{
		return -1;
	}

	for(int i = 0; i < height; i++)
	{
		data[i] = (float *)(data + height) + i * width;
	}

	int min_rows = height < matrix->rows ? height : matrix->rows;
	int min_cols = width < matrix->cols ? width : matrix->cols;

	for(int i = 0; i < min_rows; i++)
	{
		for(int j = 0; j < min_cols; j++)
		{
			data[i][j] = matrix->data[i][j];
		}
	}

	free(matrix->data);

	matrix->data = data;
	matrix->rows = height;
	matrix->cols = width;

	return 0;
}

int matrix_delete(matrix_t *matrix)
{
	free(matrix->data);

	return 0;
}