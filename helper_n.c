#include "shell.h"
/**
 * long_to_string - Convert a long integer to a string representation.
 * @number: The long integer to be converted to a string.
 * @string: A buffer to store the resulting string.
 * @base: The base in which to represent the number
 *
 * Return:Nothing
*/
void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}
/**
 * _atoi - Convert a string to an integer.
 * @s: A pointer to the input string.
 * Return: The integer value converted from the string.
 */
int _atoi(char *s)
{
    int sign = 1;
    unsigned int number = 0;

    /*Analyze the sign and skip non-digit characters*/
    while (*s != '\0')
    {
        if (*s == '-')
            sign *= -1;
        else if (*s == '+')
            sign *= 1;
        else if ('0' <= *s && *s <= '9')
            break;
        s++;
    }

    /*extract the number*/
    while ('0' <= *s && *s <= '9' && *s != '\0')
    {
        number = (number * 10) + (*s - '0');
        s++;
    }

    return (number * sign);
}
/**
 * count_characters - count the coincidences of character in string.
 * @string: pointer to the str origen.
 * @character: string with  chars to be counted
 * Return: int of string or 0.
 */
int count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}
	return (counter);
}