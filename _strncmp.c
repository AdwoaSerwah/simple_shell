#include "main.h"

/**
 * _strncmp - Compares n bytes of two strings.
 * @str1: String 1
 * @str2: String 2
 * @num_sk: Number of bytes
 *
 * Return: 0 if both equal, else s1 -s2
 */
int _strncmp(const char *str1, const char *str2, size_t num_sk)
{
	while (num_sk > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (*str1 == '\0' || *str2 == '\0')
			break;
		num_sk--;
		str2++;
		str1++;
	}
	return (0);
}
