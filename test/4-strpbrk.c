#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: Pointer
 * @accept: Pointer
 *
 * Return: s or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s)
	{
		char *accept_ptr = accept;

		while (*accept_ptr)
		{
			if (*s == *accept_ptr)
			{
				return (s);
			}
			accept_ptr++;
		}
		s++;
	}
	return (NULL);
}
