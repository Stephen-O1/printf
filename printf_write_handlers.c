#include "main.h"

/**
 * handle_write_char - print string
 * @c: char types
 * @flags: calculates active flags
 * @buffer: array to handle print
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: printed number of char
 */
int handle_write_char(char c, char buffer[], int flags, int precision, int size)
{
	if (flags & F_ZERO)
		padd = '0';

	buffer[r++] = c;
	buffer[r] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (r = 0 ; r < width - 1 ; r++)
			buffer[BUFF_SIZE - r - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - r - 1], width -1));
		else
}
