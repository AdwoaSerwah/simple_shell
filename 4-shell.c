#include "main.h"


/**
 * check_end - Checks the end of the line
 * @inp_ask: Input
 * @end: end
 */
void check_end(char *end, char *inp_ask)
{
	while (end >= inp_ask && (*end == '\n' || *end == ' ' || *end == '\t'))
	{
		*end = '\0';
		end--;
	}
}

/**
 * exec_child - Executes child process
 * @tok_ask: tok_ask
 * @ags_ask: Arguments
 * @inp_ask: Input
 */
void exec_child(char *tok_ask, char *ags_ask[], char *inp_ask)
{
	int i = 0;

	while (tok_ask != NULL)
	{
		ags_ask[i] = tok_ask;
		i++;
		tok_ask = strtok(NULL, " ");
	}
	ags_ask[i] = NULL;

	if (execve(ags_ask[0], ags_ask, NULL) == -1)
	{
		free(inp_ask);
		perror("./hsh");
		_exit(EXIT_FAILURE);
	}
}

/**
* create_ps - Creates a new process
 * @inp_ask: Input
 */
void create_ps(char *inp_ask)
{
	pid_t child_ask;

	child_ask = fork();

	if (child_ask == -1)
	{
		free(inp_ask);
		perror("fork");
		_exit(EXIT_FAILURE);
	}
	else if (child_ask == 0)
	{
		char *tok_ask = strtok(inp_ask, " "), *ags_ask[1024];

		if (tok_ask == NULL)
		{
			free(inp_ask);
			_exit(EXIT_SUCCESS);
		}
		if (_strcmp(tok_ask, "env") == 0)
		{
			char **env_sk = environ;

			while (*env_sk != NULL)
			{
				print_str(*env_sk);
				_putchar('\n');
				env_sk++;
			}
			free(inp_ask);
			_exit(EXIT_SUCCESS);
		}
		exec_child(tok_ask, ags_ask, inp_ask);
	}
	else
	{
		int stat_ask;

		waitpid(child_ask, &stat_ask, 0);
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *inp_ask = NULL, *prmt_ask = "($) ", n_line_ask = '\n', *end;
	size_t inp_sz = 0;
	int act_ask = isatty(STDIN_FILENO);

	while (1)
	{
		if (act_ask)
			write(STDOUT_FILENO, prmt_ask, _strlen(prmt_ask));
		if (getline(&inp_ask, &inp_sz, stdin) == -1)
		{
			if (act_ask)
				write(STDOUT_FILENO, &n_line_ask, 1);
			break;
		}
		end = inp_ask + _strlen(inp_ask) - 1;
		check_end(end, inp_ask);
		if (_strcmp(inp_ask, "exit") == 0)
			break;
		create_ps(inp_ask);
	}

	free(inp_ask);
	return (0);
}
