#include <stddef.h>
#include <stdlib.h>

#include <darwin/vector.h>

int vector_create(vector_t *vector, int size)
{
	vector->size = size;
	vector->data = malloc(sizeof(float) * size);

	if(vector->data == NULL)
	{
		return -1;
	}
}

int vector_resize(vector_t *vector, int size)
{
	vector->size = size;
	vector->data = realloc(vector->data, sizeof(float) * size);

	if(vector->data == NULL)
	{
		return -1;
	}

	return 0;
}

int vector_delete(vector_t *vector)
{
	vector->size = 0;
	free(vector->data);

	return 0;
}