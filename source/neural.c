#include <darwin/neural.h>
#include <darwin/matrix.h>

void fnn_create(fnn_t *fnn, int input_nodes, int hidden_nodes, int output_nodes)
{
	fnn->weights_input_hidden.rows = hidden_nodes;
	fnn->weights_input_hidden.columns = input_nodes;
	matrix_create(&fnn->weights_input_hidden);
	matrix_random(&fnn->weights_input_hidden);

	fnn->weights_hidden_output.rows = output_nodes;
	fnn->weights_hidden_output.columns = hidden_nodes;
	matrix_create(&fnn->weights_hidden_output);
	matrix_random(&fnn->weights_hidden_output);

	fnn->bias_hidden.rows = hidden_nodes;
	fnn->bias_hidden.columns = 1;
	matrix_create(&fnn->bias_hidden);
	matrix_random(&fnn->bias_hidden);

	fnn->bias_output.rows = output_nodes;
	fnn->bias_output.columns = 1;
	matrix_create(&fnn->bias_output);
	matrix_random(&fnn->bias_output);
}

void fnn_forward(fnn_t *fnn, matrix_t *input, matrix_t *output)
{
	matrix_t hidden;
	hidden.rows = fnn->weights_input_hidden.rows;
	hidden.columns = 1;
	matrix_create(&hidden);

	matrix_multiply(&hidden, &fnn->weights_input_hidden, input);
	matrix_add(&hidden, &hidden, &fnn->bias_hidden);

	matrix_multiply(output, &fnn->weights_hidden_output, &hidden);
	matrix_add(output, output, &fnn->bias_output);

	matrix_delete(&hidden);
}

void fnn_delete(fnn_t *fnn)
{
	matrix_delete(&fnn->weights_input_hidden);
	matrix_delete(&fnn->weights_hidden_output);
	matrix_delete(&fnn->bias_hidden);
	matrix_delete(&fnn->bias_output);
}