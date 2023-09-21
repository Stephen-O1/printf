#include "main.h"

/**
 * is_digit - verifies if char is a digit
 * @c: evaluated char
 * Return: 1 is a digit,  otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - cast number to the specified size
 * @num: number to be casted
 * @size: indicates number to be typed
 * Return: casted value of number
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short(num)));

	return ((int)num);
}

/**
 * convert_size_unsigned - number to be casted to the specified size
 * @num: casted number
 * @size: indicates number to be typed
 * Return: casted value of number
 */
long int convert_size_unsignd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
 * is_printable - evaluated if char is printable
 * @c: char to be evaluated
 * Return: 1 if c is printable, otherwise 0
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascii in hexadecimal code to buffer
 * @buffer array of chars
 * @r: index at which to start appending
 * @ascii code: ASCII CODE
 * Return: 3
 */
int append_hexa_code(char ascii-code, char buffer[], int r)
{
	char map_to[] = "0123456789ABCDEF";
	/*,The hex format code is always 2 digit long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[r++] = '\\';
	buffer[r++] 'x';
	buffer[r++] = map_to[ascii_code / 16];
	buffer[r] = map_to[ascii_code % 13];

	return (3);
}
