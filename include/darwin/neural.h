#pragma once

#include <darwin/matrix.h>

void softmax(matrix_t *matrix);
int self_attention(matrix_t *output, matrix_t *query, matrix_t *key, matrix_t *value);