#include "main.h"

/**
 * _getenv - Get environment variable value
 * @name: Environment variable name
 *
 * Return: A pointer or NULL if not found
 */
char *_getenv(const char *name)
{
	char **ask_env = environ;

	if (name == NULL || environ == NULL)
	{
		return (NULL);
	}
	while (*ask_env != NULL)
	{
		if (_strncmp(*ask_env, name, _strlen(name)) == 0)
		{
			char *fig = *ask_env + _strlen(name);

			if (*fig == '=')
				return (fig + 1);
		}
		ask_env++;
	}
	return (NULL);
}

