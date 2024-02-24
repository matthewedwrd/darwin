#include <stdio.h>

#include <darwin/matrix.h>
#include <darwin/vector.h>
#include <darwin/function.h>
#include <darwin/endl.h>

int main()
{
	vector_t vector0, vector1;
	vector_create(&vector0, 7);
	vector_create(&vector1, 0);

	vector0.data[0] = 1.0f;
	vector0.data[1] = 2.0f;
	vector0.data[2] = 3.0f;
	vector0.data[3] = 4.0f;
	vector0.data[4] = 1.0;;
	vector0.data[5] = 2.0f;
	vector0.data[6] = 3.0f;

	softmax(&vector0, &vector1);

	for(int i = 0; i < vector1.size; i++)
	{
		printf("%.3f ", vector1.data[i]);
	}
	printf(ENDL);

	vector_delete(&vector0);
	vector_delete(&vector1);

	return 0;
}