#include <stdio.h>

int main(int argc, char const *argv[])
{
	int sum = 0;
	int sumOfSquares = 0;
	int i;
	for (i = 1; i <= 100; i++)
	{
		sum += i;
		sumOfSquares += i*i;
	}

	printf("%d\n", sum*sum - sumOfSquares);
	return 0;
}