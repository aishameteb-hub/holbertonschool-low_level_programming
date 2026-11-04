#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible combinations of
 * single-digit numbers, separated by a comma and a space.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 0; n < 10; n++)
	{
		putchar('0' + n);

		if (n != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}
