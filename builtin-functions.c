#include "simple-shell.h"

/**
 *env - this prints the current_environnement
 *@tokenized_cmd: The command entered
 *
 *Return: void
 */

void env(char **tokenized_cmd __attribute__((unused)))
{
	int j;

	for (j = 0; environ[j] != NULL; j++)
	{
		print(environ[j], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
 * quit - this exits the shell
 * @tokenized_cmd: the command entered
 *
 * Return: void
 */

void quit(char **tokenized_cmd)
{
	int num_token = 0, arg;

	for (; tokenized_cmd[num_token] != NULL; num_token++)
		;
	if (num_token == 1)
	{
		free(tokenized_cmd);
		free(line);
		free(commands);
		exit(status);
	}
	else if (num_token == 2)
	{
		arg = _atoi(tokenized_command[1]);
		if (arg == -1)
		{
			print(shell_name, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(tokenized_cmd[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(tokenized_cmd);
			free(commands);
			exit(arg);
		}
	}
	else
		print("$: The exit does not take more than one argument\n", STDERR_FILENO);
}
