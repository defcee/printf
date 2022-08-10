#include "main.h"
#include <stdlib.h>

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
			if (_validate(format[i]) == 0)
			{
				count = _print_invalid_spec(format[i - 1], format[i], count);
			}
			else
			{
				count += _print_spec(format[i], args);
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
 * _print_spec - specifier
 * @format: format
 * @args: args
 *
 * Return: length
 */
int _print_spec(char format, va_list args)
{
	int i  = 0, length = 0;
	spc_dt _types[] = {
		{"c", _print_char},
		{"s", _print_string},
		{NULL, NULL}
	};

	while (_types[i].specifier)
	{
		if (*_types[i].specifier == format)
			length = _types[i].f(args);
		i++;
	}
	return (length);
}

/**
 * _validate - validate
 * @_type: type
 *
 * Return: 0
 */
int _validate(char _type)
{
	char _types[] = {'c', 's', 'd', 'i', '%'};
	int i = 0;

	while (_types[i])
	{
		if (_types[i] == _type)
			return (1);
		i++;
	}
return (0);
}

/**
 * _print_invalid_spec - invalid
 * @prev_format: previos
 * @format: format
 * @count: len
 *
 * Return: count
 */
int _print_invalid_spec(char prev_format, char format, int count)
{
	count += _write('%');
	if (prev_format == ' ')
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
