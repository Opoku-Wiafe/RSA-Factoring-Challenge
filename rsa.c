#include "main.h"
/**
 * factorize - This funct factorizes a number and print results
 * @number:  Number to be factorized.
 * Return: return nothing.
 */
int factorize(char *check)
{

	u_int32_t number;
	u_int32_t i;

	number = atoi(check);


	for (i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			printf("%d=%d*%d\n",number, number / i, i);
			break;
		}
	}

return (0);
}

/**
 * main - main entry point for the code.
 * @argc: number of arguments passed
 * @argv: number of arrays in pointer.
 * Return: return 0 if the program exits successful and 1 if error 
*/
int main(int argc, char *argv[])
{
	FILE *encryptf;
	size_t counter;
	ssize_t encrypt_line;
    char *check = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}
	encryptf = fopen(argv[1], "r");
	if (encryptf == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while((encrypt_line = getline(&check, &counter, encryptf)) != -1)
	{
		factorize(check);
	}
return (0);
}
