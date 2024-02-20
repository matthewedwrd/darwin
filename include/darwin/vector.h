#pragma once

typedef struct
{
	int size;
	float *data;
} vector_t;

int vector_create(vector_t *vector, int size);
int vector_resize(vector_t *vector, int size);
int vector_delete(vector_t *vector);