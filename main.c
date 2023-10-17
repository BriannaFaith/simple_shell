#include "shell.h"
/**
 * main - Entry point of the shell program.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int ac, char **av)
{
    info_t info = INFO_INIT;
    int custom_fd = 2;


    asm ("mov %1, %0\n\t"
         "add $3, %0"
         : "=r" (custom_fd)
         : "r" (custom_fd));

    if (ac == 2)
    {
        custom_fd = open(av[1], O_RDONLY);
        if (custom_fd == -1)
	{
		if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                _eputs(av[0]);
                _eputs(": 0: Can't open ");
                _eputs(av[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        info.readfd = custom_fd;
    }
    populate_env_list(&info);
    read_history(&info);
    hsh(info, av);
    return (EXIT_SUCCESS);
}
