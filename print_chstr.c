#include "main.h"

/**
 * print_str - Prints string
 * @str: Sring
 *
 * Return: Number of strings printed
 */
int print_str(char *str)
{
	int len_sk = 0;

	while (*str != '\0')
	{
		_putchar(*str);
		len_sk++;
		str++;
	}
	return (0);
}

/**
 * _putchar - Writes a character to standard output (stdout)
 * @c: The character to be displayed
 *
 * Return: A character
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
