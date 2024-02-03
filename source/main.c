#include <stdio.h>
#include <time.h>

#include <darwin/matrix.h>
#include <darwin/endl.h>
#include <darwin/seed.h>

int main()
{
	g_seed = time(NULL);

	matrix_t matrix0, matrix1, matrix2;

	matrix0.rows = 2;
	matrix1.rows = 2;
	matrix2.rows = 2;

	matrix0.columns = 2;
	matrix1.columns = 2;
	matrix2.columns = 2;

	matrix_create(&matrix0);
	matrix_create(&matrix1);
	matrix_create(&matrix2);

	matrix_random(&matrix0);
	matrix_random(&matrix1);

	printf("MATRIX 1:" ENDL);
	matrix_print(&matrix0);

	printf("MATRIX 2:" ENDL);
	matrix_print(&matrix1);

	matrix_add(&matrix2, &matrix0, &matrix1);

	printf("RESULT OF ADDING MATRIX 1 AND MATRIX 2:" ENDL);
	matrix_print(&matrix2);

	matrix_multiply(&matrix2, &matrix0, &matrix1);

	printf("RESULT OF MULTIPLYING MATRIX 1 AND MATRIX 2:" ENDL);
	matrix_print(&matrix2);

	matrix_random(&matrix2);
	matrix_delete(&matrix1);
	matrix_delete(&matrix0);

	return 0;
}