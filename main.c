#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info= INFO_INIT;

	info.arg = NULL;
	info.argv = NULL;
	info.path = NULL;
	info.argc = 0;
	info.environ = NULL;
	info.filename = NULL;
	info.line_count = 0;
	info.err_num = 0;
	info.linecount_flag = 0;
	info.env_changed = 0;
	info.status = 0;
	info.cmd_buf = NULL;
	info.cmd_buf_type = 0;
	info.readfd = STDIN_FILENO;

	int fd = 2;
	
	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
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
		info->readfd = fd;
	}
	populate_env_list(&info);
	read_history(&info);
	hsh(&info, av);
	return (EXIT_SUCCESS);
}