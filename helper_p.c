#include "shell.h"

/**
 * _print - Write a array of chars to the standard outpu.
 * @string: pointer to array of chars.
 *
 * Return: The number of bytes written on success, or -1 on error with 'errno' set accordingly.
 */
int _print(char *string)
{
    return(write(STDOUT_FILENO, string, str_length(string)));
}

/**
 * _printe - Write a character array to the standard error.
 * @string: A pointer to the character array to be written.
 * Return: The number of bytes written on success, or -1 on error with 'errno' set accordingly.
 */
int _printe(char *string)
{
    return write(STDERR_FILENO, string, str_length(string));
}

/**
 * _print_error - Write error messages to standard error based on error codes.
 * @errorcode: An integer representing a specific error condition.
 * @data: A pointer to the program's data.
 * Return: 0, indicating the function has completed without errors.
 */
int _print_error(int errorcode, data_of_program *data)
{
    char n_as_string[10] = {'\0'};

    long_to_string((long)data->exec_counter, n_as_string, 10);

    if (errorcode == 2 || errorcode == 3)
    {

        _printe(data->program_name);
        _printe(": ");
        _printe(n_as_string);
        _printe(": ");
        _printe(data->tokens[0]);
        if (errorcode == 2)
            _printe(": Illegal number: ");
        else
            _printe(": can't cd to ");
        _printe(data->tokens[1]);
        _printe("\n");
    }
    else if (errorcode == 127)
    {
        _printe(data->program_name);
        _printe(": ");
        _printe(n_as_string);
        _printe(": ");
        _printe(data->command_name);
        _printe(": not found\n");
    }
    else if (errorcode == 126)
    {
        _printe(data->program_name);
        _printe(": ");
        _printe(n_as_string);
        _printe(": ");
        _printe(data->command_name);
        _printe(": Permission denied\n");
    }
    return 0; // Indicating successful execution.
}
