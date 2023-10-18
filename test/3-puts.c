#include "main.h"

/**
 * _puts - Prints a string followed by a newline to stdout
 * @str: String to return
 *
 * Return: str
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(str[0]);
		str++;
	}
	_putchar('\n');
}
