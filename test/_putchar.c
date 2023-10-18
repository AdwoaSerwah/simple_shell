#include "main.h"

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
