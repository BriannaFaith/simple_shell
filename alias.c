#include "shell.h"
/**
 * print_alias - Manage aliases by adding, removing, or displaying them.
 * @data: A data structure for program information.
 * @alias: The name of the alias to be operated on or displayed.
 *
 * Return: 0 on success, or another number if an error is encountered.
 */
int print_alias(data_of_program *data, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_length(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			/*Checks if alias is null or matches the beginning of alias definition.*/
			if (!alias || (str_compare(data->alias_list[i], alias, alias_length)
				&&	data->alias_list[i][alias_length] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
						break;
				}
				/*Print the alias name and command enclosed*/
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[i] + j + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}
	return (0);
}
/**
 * get_alias - Retrieve an alias by name or perform alias-related operations.
 *
 * @data: A data structure for program information.
 * @name: The name of the alias to retrieve or perform operations on.
 *
 * Return: 0 on success, or another number indicating operation status.
 */

char *get_alias(data_of_program *data, char *name)
{
	int i, alias_length;

	/* Validate the arguments: checks if name and alias list are not null */
	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (i = 0; data->alias_list[i]; i++)
	{
		if (str_compare(name, data->alias_list[i], alias_length) &&
			data->alias_list[i][alias_length] == '=')
		{
			return (data->alias_list[i] + alias_length + 1);
		}
	}
	/* returns NULL if did not find it */
	return (NULL);
}

/**
 * set_alias - Add or update an alias.
 * @alias_string: The alias string to be added or updated.
 * @data: A data structure containing alias information.
 *
 * Return: 0 on success, or 1 if there are validation errors.
 */
int set_alias(char *alias_string, data_of_program *data)
{
    int i, j;
    char alias_name[250] = {'\0'};
    char *alias_value = NULL;

    /* Check for null or missing arguments */
    if (alias_string == NULL || data->alias_list == NULL)
        return 1;

    /* Extract alias name and check if the value is another alias */
    for (i = 0; alias_string[i] && alias_string[i] != '='; i++)
        alias_name[i] = alias_string[i];

    if (alias_string[i] == '=')
    {
        alias_value = get_alias(data, alias_string + i + 1);
    }

    /* Iterate through the alias list and check for matching alias names */
    for (j = 0; data->alias_list[j]; j++)
    {
        if (str_compare(alias_name, data->alias_list[j], i) &&
            data->alias_list[j][i] == '=')
        {
            /* If the alias already exists, free the previous alias */
            free(data->alias_list[j]);
            break;
        }
    }
    /* Add the alias */
    if (alias_value)
    {
        char buffer[250] = {'\0'};
        buffer_add(buffer, alias_name);
        buffer_add(buffer, "=");
        buffer_add(buffer, alias_value);
        data->alias_list[j] = str_duplicate(buffer);
    }
    else
    {
        /* If the alias doesn't exist, create a new one */
        data->alias_list[j] = str_duplicate(alias_string);
    }

    return 0;
}
