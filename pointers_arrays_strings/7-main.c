#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line
 * @str: the string
 *
 * Return: nothing
 */
void puts_half(char *str)
{
	int len;
	int n;
	int i;

	len = 0;
	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		n = len / 2;
	else
		n = (len + 1) / 2;

	for (i = len - n; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}
