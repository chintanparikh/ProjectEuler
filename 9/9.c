#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int i, j;
	float k;
	for (i = 1; i<= 1000; i++)
	{
		for (j = 1; j<= 1000; j++)
		{
			k = sqrt(i*i + j*j);

			// Use floats because it is widening so you don't lose information
			if ((float)i + (float)j + k == (float)1000)
			{
				break;
			}
		}
		if ((float)i + (float)j + k == (float)1000)
		{
			printf("%d, %d, %f\n", i, j, k);
			printf("Product: %f\n", i * j * k);
			break;
		}	
	}
	return 0;
}