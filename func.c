#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * _print_char - prints char
 * @args: args
 *
 * Return: 1
 */
int _print_char(va_list args)
{
	_write(va_arg(args, int));
return (1);
}

/**
 * _print_string - print string
 * @args:args
 *
 * Return: ..
 */
int _print_string(va_list args)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			_write(arg[i]);
			i++;
		}
	return (i);
	}
	return (0);
}
