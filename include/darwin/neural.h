#pragma once

#include <darwin/matrix.h>

typedef struct
{
	matrix_t weights_input_hidden;
	matrix_t weights_hidden_output;
	matrix_t bias_hidden;
	matrix_t bias_output;
} fnn_t;

void fnn_create(fnn_t *fnn, int input_nodes, int hidden_nodes, int output_nodes);
void fnn_forward(fnn_t *fnn, matrix_t *input, matrix_t *output);
void fnn_delete(fnn_t *fnn);