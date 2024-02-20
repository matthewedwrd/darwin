#include <darwin/selfattention.h>
#include <darwin/vector.h>
#include <darwin/matrix.h>

void selfattention(matrix_t *input, matrix_t *output, int heads_count)
{
	int l_hidden_size = input->cols;
	int l_head_size = l_hidden_size / heads_count;

	for(int i = 0; i < input->rows; i++)
	{
		for(int h = 0; h < heads_count; h++)
		{
			int l_start_index = h * l_head_size;
			int l_end_index = (h + 1) * l_head_size;

			vector_t l_query, l_key, l_value;
			vector_create(&l_query, l_head_size);
			vector_create(&l_key, l_head_size);
			vector_create(&l_value, l_head_size);
			for(int j = l_start_index; j < l_end_index; j++)
			{
				l_query.data[j - l_start_index] = input->data[i][j];
				l_key.data[j - l_start_index] = input->data[i][j];
				l_value.data[j - l_start_index] = input->data[i][j];
			}

			float l_dot_product = 0.0f;
			for(int j = 0; j < l_head_size; j++)
			{
				l_dot_product += l_query.data[j] * l_key.data[j];
			}

			float l_attention_weight = exp(l_dot_product);
			float l_attention_sum = 0.0f;

			for(int j = 0; j < l_head_size; j++)
			{
				l_attention_sum += exp(l_dot_product);
			}

			l_attention_weight /= l_attention_sum;

			for(int j = 0; j < l_head_size; j++)
			{
				output->data[i][l_start_index + j] = l_attention_weight * l_value.data[j];
			}

			vector_delete(&l_query);
			vector_delete(&l_key);
			vector_delete(&l_value);
		}
	}
}