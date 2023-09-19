#include "main.h"
<<<<<<< HEAD

 void print_buffer(char buffer[], int *buff_int);

/**
 * _printf - function that produces output 7according to a format
 * @format: format
 * Return: printed chars
=======
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
>>>>>>> cb2d2f3debdedd00e59289bdd92e1fb0e5d43a63
 */
int _printf(const char * const format, ...)
{
<<<<<<< HEAD
	int r, printed = 0, printed_chars = 0;
	int flags, size, width, precision, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[r];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1); */
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++r;
			printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
=======
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
>>>>>>> cb2d2f3debdedd00e59289bdd92e1fb0e5d43a63
		}
		_putchar(format[i]);
		len++;
		i++;
	}
<<<<<<< HEAD

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - prints the contents of the buffer 
 * @buffer: chars array
 * @buff_ind: index to add next char, repr length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
=======
	va_end(args);
	return (len);
>>>>>>> cb2d2f3debdedd00e59289bdd92e1fb0e5d43a63
}
