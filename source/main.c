#include <stdio.h>
#include <time.h>

#include <darwin/matrix.h>
#include <darwin/endl.h>
#include <darwin/seed.h>
#include <darwin/neural.h>

int main()
{
	g_seed = time(NULL);

	int input_nodes = 2;
	int hidden_nodes = 2;
	int output_nodes = 2;

	fnn_t my_fnn;

	fnn_create(&my_fnn, input_nodes, hidden_nodes, output_nodes);

	matrix_t input;
	input.rows = input_nodes;
	input.columns = 1;
	matrix_create(&input);
	matrix_random(&input);

	printf("INPUT:" ENDL);
	matrix_print(&input);

	matrix_t output;
	output.rows = output_nodes;
	output.columns = 1;
	matrix_create(&output);

	fnn_forward(&my_fnn, &input, &output);

	printf("OUTPUT AFTER FORWARD PASS:" ENDL);
	matrix_print(&output);

	matrix_delete(&input);
	matrix_delete(&output);
	fnn_delete(&my_fnn);

	return 0;
}