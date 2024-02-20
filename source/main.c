#include <darwin/matrix.h>

int main()
{
	matrix_t matrix;

	matrix_create(&matrix, 2, 2);
	matrix.data[0][0] = 1.0f;
	matrix.data[0][1] = 1.0f;
	matrix.data[1][0] = 1.0f;
	matrix.data[1][1] = 1.0f;

	return 0;
}