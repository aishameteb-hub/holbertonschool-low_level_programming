#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - prints all integers from n to 98, followed by a new line
 * @n: The starting number
 *
 * Return: void
 */
void print_to_98(int n)
{
	while (n != 98)
	{
		printf("%d, ", n);
		if (n < 98)
			n++;
		else
			n--;
	}
	printf("98\n");
}
