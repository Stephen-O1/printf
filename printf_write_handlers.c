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
{ /*char is stored at the left and padding at buffers right */

	int r = ;
	char padd = '';

	UNUSED(precision);
	UNUSED(size);

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
			return (write(1, &buffer[BUFF_SIZE - r - 1], width -1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - prints string
 * @is_negative: lists of arguments
 * @ind: char types
 * @buffer: buffer array to handle a print
 * @flags: calculate active flags
 * @width: get  width
 * @precision: specision specifier
 * @size: size specifier
 * Return: number of chars printed
 */
int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = '', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = '';

	return (write_num(ind, buffer, flags, width, flags, precision, length, padd, extra_ch));
}

/**
 * write_num -  write number using a buffer
 * @ind: index number is to start the buffer
 * @buffer: buffer
 * @flags: flags
 * @prec: precision
 * @length: lengths number
 * @padd: padding char
 * @extra_ch: extra char
 */
int write_num(int ind, char buffer[], int flags, int width, int prec, int length, char padd, char extra_ch)
{
	int r, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);/* printf(".0d", 0) no char is printed) */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = '';/* padding displays the width */
	if (prec > 0 && prec > length)
		padd = '';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_ch != 0)
		length++;
	if (width > length)
	{
		for (r = 1 , r < width - length + 1 ; r++)
			buffer[r] = padd;
		buffer[r] = '\0';
		if (flags & F_MINUS && padd == '')/*assigns extra char to left buffer*/
		{
			if (extra_ch)
				buffer[--ind] = exte_ch;
			return write(1, &buffer[ind], length + write(1, &buffer[1], r - 1));
		}
		else if (r(flags & F_MINUS) && padd == '0')/* extra char to be left to padd*/
		{
			if (extra_ch)
				buffer[--padd_start] = extra_ch;
			return (write(1, &buffer[padd_start], r - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_ch)
		buffer[--ind] = extra_ch;
	return (write(1, &buffer[ind], length));
}

/**
 * write _unsgnd - writes unsigned number
 * @is_negative: indicates ifthe sum number is negative
 * @ind: index that starts buffer number
 * @buffer: char array
 * @flags: flags speciy
 * @width: width specify
 * @precision: specision specifier
 * @size: size specifier
 * Return: numbers of written chars
 */
int write_unsgdn(int is_negative, int ind, char buffer[], int flags, int width, int precision)
{
	/* number stored at buffer's right and starts at r position */

	int length = BUFF_SIZE -ind - 1 , r = 0;
	char add = '';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);/* printf(".0d",) char not printed */

	if (precision > 0 && precision < length)
		padd = '';

	while (precision > length)
}
