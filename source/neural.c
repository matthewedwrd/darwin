#include <math.h>

#include <darwin/neural.h>
#include <darwin/matrix.h>

void softmax(matrix_t *matrix)
{
	for(int i = 0; i < matrix->rows; i++)
	{
		float sum = 0.0f;

		for (int j = 0; j < matrix->columns; j++)
		{
			matrix->data[i][j] = exp(matrix->data[i][j]);
			sum += matrix->data[i][j];
		}

		for (int j = 0; j < matrix->columns; j++)
		{
			matrix->data[i][j] /= sum;
		}
	}
}

int self_attention(matrix_t *output, matrix_t *query, matrix_t *key, matrix_t *value)
{
	matrix_t temp;
	temp.rows = query->rows;
	temp.columns = key->columns;

	if(matrix_create(&temp) != 0)
	{
		return -1;
	}

	if(matrix_multiply(&temp, query, key) != 0)
	{
		matrix_delete(&temp);
		return -1;
	}

	softmax(&temp);

	if(matrix_multiply(output, &temp, value) != 0)
	{
		matrix_delete(&temp);
		return -1;
	}

	matrix_delete(&temp);
	return 0;
}