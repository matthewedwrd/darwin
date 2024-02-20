#include <math.h>

#include <darwin/vector.h>

/**
 *	@brief Convert a vector of logits into a probability distribution.
 *	@param input The input vector, containing the logits.
 *	@param output The output vector, where the probabilities will be stored.
 */
int softmax(vector_t *input, vector_t *output)
{
	/*
	 *	This variable will be used to store the sum of exponentials of input
	 *	values.
	 */
	float l_sum = 0.0f;

	/* Calculate the sum of exponentials of the input values. */
	for(int i = 0; i < input->size; i++)
	{
		l_sum += exp(input->data[i]);
	}

	/*
	 *	Calculate the softmax probabilities for each element of the input
	 *	vector.
	 */
	for(int i = 0; i < input->size; i++)
	{
		/* Compute the softmax probability for the current element. */
		output->data[i] = exp(input->data[i]) / l_sum;
	}
}