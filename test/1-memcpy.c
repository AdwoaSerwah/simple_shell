#include "main.h"

/**
 * _memcpy - Copies memory area
 * @dest: Pointer to destination
 * @src: Pointer to source
 * @n: Size of bytes to copy
 *
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
