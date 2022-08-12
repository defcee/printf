#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - printf
 * @format: format to print
 *
 * Return: int
 */

int _printf(const char *format, ...)
{
	va_list args;

	int len = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	len = _print(format, args);
	va_end(args);
	return (len);
}
