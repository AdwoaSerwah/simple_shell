#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: String
 * @accept: String
 *
 * Return: Number of bytes in the initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int found;

	while (*s)
	{
		char *accept_ptr = accept;

		found = 0;
		while (*accept_ptr)
		{
			if (*s == *accept_ptr)
			{
				found = 1;
				break;
			}
			accept_ptr++;
		}
		if (!found)
		{
			break;
		}
		count++;
		s++;
	}
	return (count);
}
