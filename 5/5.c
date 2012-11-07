#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	// Brute forced solution
	int i;
	int j;
	bool divisible = true;
	for (i = 1;;i++)
	{
		for (j = 1; j <= 20; j++)
		{
			if (i % j == 0)
			{
				divisible = true;
			}
			else
			{
				divisible = false;
				break;
			}
		}

		if (divisible)
		{
			printf("%d\n", i);
			break;
		}

	}
	return 0;
}