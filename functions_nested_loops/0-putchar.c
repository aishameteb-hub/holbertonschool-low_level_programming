#include <unistd.h>

/**
 * main - prints _putchar followed by a new line
 *
 * Return: Always 0
 */
int main(void)
{
	write(1, "_putchar\n", 9);
	return (0);
}
