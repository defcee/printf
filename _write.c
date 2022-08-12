#include <unistd.h>

/**
 * _write - writes
 * @c: character
 *
 * Return: 1
 */

int _write(char c)
{
	return (write(1, &c, 1));
}
