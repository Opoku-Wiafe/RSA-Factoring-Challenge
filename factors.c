#include "main.h"
/**
 * rsa_factorize - This funct factorizes a number and print results
 * @number:  Number to be factorized.
 * Return: return nothing.
 */

void rsa_factorize(int number)
{
	int i;
	int x;

	x  = number;

	for (i = 2; i <= x / 2; i++)
	{
		if (x % i == 0)
		{
			printf("%d=%d*%d\n", x, i, x / i);
			return;
		}
	}
	printf("%d=1*%d\n", x, x);
}


/**
 * main - main entry point for the code.
 * @argc: number of arguments passed
 * @argv: number of arrays in pointer.
 * Return: return 0 if the program exits successful and 1 if error
*/
int main(int argc, char *argv[])
{
	FILE *encryptFile;
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	encryptFile = fopen(argv[1], "r");
	if (!encryptFile)
	{
		perror("Error opening file");
		return (1);
	}

	while (fscanf(encryptFile, "%d", &i) == 1)
	{
		rsa_factorize(i);
	}

	fclose(encryptFile);
	return (0);
}
