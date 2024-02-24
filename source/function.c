#include <stddef.h>
#include <math.h>

#include <darwin/function.h>
#include <darwin/vector.h>

void softmax(vector_t *input, vector_t *output)
{
	vector_resize(output, input->size);

	float m = -INFINITY;
	for(size_t i = 0; i < input->size; i++)
	{
		if(input->data[i] > m)
		{
			m = input->data[i];
		}
	}

	float sum = 0.0;
	for(size_t i = 0; i < input->size; i++)
	{
		sum += expf(input->data[i] - m);
	}

	float offset = m + logf(sum);
	for(size_t i = 0; i < input->size; i++)
	{
		output->data[i] = expf(input->data[i] - offset);
	}
}