#include "shell.h"
/**
 * _strncpy - Copies a string with a maximum of 'n' characters.
 * @dest: The destination string to copy to.
 * @src: The source string to copy from.
 * @n: The maximum number of characters to copy.
 * Return: A pointer to the resulting string 'dest'.
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    while (src[i] != '\0' && i < n - 1)
    {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
    {
        j = i;
        while (j < n)
        {
            dest[j] = '\0';
            j++;
        }
    }
    return (s);
}
/**
 * _strncat - Concatenates two strings with a maximum of 'n' characters from 'src'.
 * @dest: The first string.
 * @src: The second string to concatenate.
 * @n: The maximum number of bytes to use from 'src'.
 * Return: A pointer to the concatenated string 'dest'.
 */
char *_strncat(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    j = 0;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
	if (j < n)
        dest[i] = '\0';
    return (s);
}


/**
 * _strchr - Locates a character 'c' in a string 's'.
 * @s: The string to search within.
 * @c: The character to find.
 * Return: A pointer to the first occurrence of 'c' in 's', or NULL if not found.
 */
char *_strchr(char *s, char c)
{
    do
    {
        if (*s == c)
            return (s);
    } while (*s++ != '\0');
    return (NULL);
}