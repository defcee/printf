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

/**
 * _print_int - Prints a integer
 * @args: arguments
 *
 * Return: length of the string
 */

int _print_int(va_list args)
{
	int count = 1;
	int i = 0;
	unsigned int j = 0;

	j = va_arg(args, int);
	i = j;
	if (i < 0)
	{
		_write('-');
		i = i * -1;
		j = i;
		count += 1;
	}
	while (j > 9)
	{
		j = j / 10;
		count++;
	}
	recursion_int(i);
	return (count);
}

/**
 * recursion_int - Prints a integer
 * @a: integer to print
 *
 * Return: void
 */

void recursion_int(int a)
{
	unsigned int t;

	t = a;
	if (t / 10)
	recursion_int(t / 10);
	_write(t % 10 + '0');
}
