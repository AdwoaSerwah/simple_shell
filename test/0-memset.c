#include "main.h"

/**
 * _memset - Fills memory with a constant byte
 *  @s: Pointer
 *  @n: Size of byte(s)
 *  @b: Character to fill n with
 *
 *  Return: Pointer to s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
