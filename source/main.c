#include <stdio.h>

#include <darwin/matrix.h>
#include <darwin/vector.h>
#include <darwin/function.h>
#include <darwin/endl.h>


int main()
{
	matrix_t matrix;

	matrix_create(&matrix, 8, 8);

	matrix_clear(&matrix);

	matrix_print(&matrix);

	matrix_delete(&matrix);

	return 0;
}