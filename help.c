#include "simple-shell.h"

/**
 * tokenizer - This tokenizes the input and stores it in an array
 *@input_str: the input to be parsed
 *@delim: the delimiter to be used, 
 * and it needs to be one character string
 *
 *Return: array of tokens
 */

char **tokenizer(char *input_str, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = _strtok_r(input_str, delim, &save_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);
		num_delim++;
	}

	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
}

/**
 *print - It prints a string to stdout
 *@string: The string to be printed
 *@stream: The stream to print out to
 *
 *Return: void, return nothing
 */
void print(char *string, int stream)
{
	int j = 0;

	for (; string[j] != '\0'; j++)
		write(stream, &string[j], 1);
}

/**
 *remove_newline - This removes new line from a string
 *@str: string to be used
 *
 *
 *Return: void
 */

void remove_newline(char *str)
{
	int j = 0;

	while (str[j] != '\0')
	{
		if (str[j] == '\n')
			break;
		j++;
	}
	str[j] = '\0';
}

/**
 *_strcpy - This copies a string to another buffer
 *@source: the source to copy from
 *@dest: the destination to copy to
 *
 * Return: void
 */

void _strcpy(char *source, char *dest)
{
	int j = 0;

	for (; source[j] != '\0'; j++)
		dest[j] = source[j];
	dest[j] = '\0';
}

/**
 *_strlen - it counts string length
 *@string: the string to be counted
 *
 * Return: the length of the string
 */

int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
		;
	return (len);
}
