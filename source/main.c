#include <darwin/matrix.h>

int main()
{
	matrix_t l_matrix;

	matrix_create(&l_matrix, 2, 2);
	l_matrix.data[0][0] = 1.0f;
	l_matrix.data[0][1] = 1.0f;
	l_matrix.data[1][0] = 1.0f;
	l_matrix.data[1][1] = 1.0f;

	return 0;
}