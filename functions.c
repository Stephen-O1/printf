#include  "main.h"

/**
 * print_pointer - print value of pointer variable
 * @buffer: buffer array to handle print
 * @types: list of arguments
 * @buffer: array to handle print
 * @flags: calculates active flags
 * @precision: precision specification
 * @size: size specifier
 * @width: get width
 * @Return: number of chars printed
 */

int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int place = 0, r;
	char *str = va_arg(types, char*);

	UNUSED(buffer);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision > 6)
			str - " ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length
