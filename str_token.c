#include "shell.h"
/**
 * _strtok - Splits a string into tokens using specified delimiters.
 *
 * @line: A pointer to the input string received from getline.
 * @delim: A string containing the characters used as delimiters.
 * Return: A pointer to the created token, or NULL if there are no more tokens.
 */

char *_strtok(char *line, char *delim)
{
	int j;
	static char *str;
	char *copystr;
	/*If a new line is provided, set str to it*/
	if (line != NULL)
		str = line;
	/*Find the first character not in delim*/
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			break;
		}
		if (delim[j] == '\0')
			break;
	}
	/*Save the starting position of the token*/
	copystr = str;
	/*Return null if end of string reaches*/
	if (*copystr == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
		}
	}
	return (copystr);
}