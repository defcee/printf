#include <stdlib.h>
#include "main.h"

/**
 * _print - print
 * @format: format
 * @args: args
 *
 * Return: length
 */

int _print(const char *format, va_list args)
{
	int count = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			i++;
			while (format[i] == ' ')
				i++;
			if (format[i] == '%')
				count += _write(format[i]);
			if (validate(format[i]) == 0)
			{
				count = invalid(format[i - 1], format[i], count);
			}
			else
			{
				count += spec(format[i], args);
			}
		}
		else
		{
			count += _write(format[i]);
		}
		i++;
	}
	return (count);
}

/**
 * spec - specifier
 * @format: format
 * @args: args
 *
 * Return: length
 */
int spec(char format, va_list args)
{
	int i  = 0, length = 0;
	spc types[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"d", _print_int},
		{"i", _print_int},
		{NULL, NULL}
	};

	while (types[i].specifier)
	{
		if (*types[i].specifier == format)
			length = types[i].f(args);
		i++;
	}
	return (length);
}

/**
 * validate - validate
 * @type: type
 *
 * Return: 0
 */
int validate(char type)
{
	char types[] = {'c', 's', 'd', 'i', '%'};
	int i = 0;

	while (types[i])
	{
		if (types[i] == type)
			return (1);
		i++;
	}
return (0);
}

/**
 * invalid - invalid
 * @prev: previos
 * @format: format
 * @count: len
 *
 * Return: count
 */
int invalid(char prev, char format, int count)
{
	count += _write('%');
	if (prev == ' ')
	{
		count += _write(' ');
		count += _write(format);
	}
	else
	{
		count += _write(format);
	}
	return (count);
}
