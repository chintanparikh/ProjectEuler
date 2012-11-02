#include <stdio.h>

int main(int argc, char const *argv[])
{
	int sum = 0;
	int i = 1;
	int j = 1;
	while (i < 4000000)
	{
		if (i % 2 == 0)
		{
			sum += i;
		}
		i = i + j;
		j = i - j;
	}
	printf("%d\n", sum);
}