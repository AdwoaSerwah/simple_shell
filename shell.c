#include "main.h"

/**
 * check_end - Checks the end of the line
 * @input: Input
 * @end: end
 */

void check_end(char *end, char *input)
{
	while (end >= input && (*end == '\n' || *end == ' ' || *end == '\t'))
	{
		*end = '\0';
		end--;
	}
}

/**
 * exec_child - Executes child process
 * @token: token
 * @args: Arguments
 * @arg: Argument
 * @i: Index
 */
void exec_child(char *token, char *args[], char *arg, int i)
{
	while (arg != NULL)
	{
		args[i] = arg;
		i++;
		arg = strtok(NULL, " ");
	}
	args[i] = NULL;
	if (execve(token, args, NULL) == -1)
	{
		perror("./hsh");
		_exit(EXIT_FAILURE);
	}
}

/**
* create_ps - Creates a new process
 * @input: Input
 */
void create_ps(char *input)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		_exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *token = strtok(input, " "), *args[1024], *arg;
		int i = 0;

		if (token == NULL)
			_exit(EXIT_SUCCESS);
		args[0] = token;
		i = 1;
		arg = strtok(NULL, " ");
		exec_child(token, args, arg, i);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *input = NULL, *prompt = "($) ", newline = '\n', *end;
	size_t input_size = 0;
	int act = isatty(STDIN_FILENO);

	while (1)
	{
		if (act)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		if (getline(&input, &input_size, stdin) == -1)
		{
			if (act)
				write(STDOUT_FILENO, &newline, 1);
			break;
		}
		end = input + _strlen(input) - 1;
		check_end(end, input);
		create_ps(input);
	}

	free(input);
	return (0);
}
