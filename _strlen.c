#include "main.h"


/**
 * _strlen - Finds the length of a string
 * @s: String
 *
 * Return: len_ask
 */
int _strlen(const char *s)
{
	int len_ask = 0;

	while (s[len_ask] != '\0')
	{
		len_ask++;
	}
	return (len_ask);
}
