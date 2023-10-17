#include "shell.h"
/**
 * print_error_message - prints an input string to standard error
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void print_error_message(char *str)
{
    int i = 0;

    if (!str)
        return;
    while (str[i] != '\0')
    {
        _eputchar(str[i]);
        i++;
    }
}
/**
 * _eputchar - writes the character c to standard error
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];
    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        fwrite(2, buf, i);
        i = 0;
    }
    if (c != BUF_FLUSH)
        buf[i++] = c;

    return (1);
}
/**
 * put_fd - writes the character c to given fd
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int put_fd(char c, int fd)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];
    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(fd, buf, i);
        i = 0;
    }
    if (c != BUF_FLUSH)
        buf[i++] = c;
    return (1);
}
/**
 * puts_fd - prints an input string to the given file descriptor
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of chars written
 */
int puts_fd(char *str, int fd)
{
    int char_count = 0;

    if (!str)
        return (0);
    while (*str)
    {
        char_count += put_fd(*str++, fd);
    }
    return (char_count);
}
