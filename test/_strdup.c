#include "main.h"

/**
 * _strdup - Duplicates strings
 * @s1: String
 * Return: Pointer to s2, or NULL if error
 */
char *_strdup(const char *s1)
{
	char *s2;
	int len_sk = _strlen(s1) + 1;

	s2 = (char *)malloc(len_sk * sizeof(char));

	if (s2 != NULL)
	{
		int k = 0;

		while (k <= len_sk)
		{
			s2[k] = s1[k];
			k++;
		}
		return (s2);
	}
	else
	{
		perror("malloc");
		_exit(EXIT_FAILURE);
	}
}
