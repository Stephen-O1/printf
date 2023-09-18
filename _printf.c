#include "main.h"

/**
 * _printf - function that produces
 * output according to a format
 * Return: printed chars
 */

int _printf(const char *format, ...)
{
	int r, output = 0, output_chars = 0;
	int flags, size, length, address, buff_ind = 0;
	va_list lists;
	char buffer[Buffer_size];

	if (format == NULL)
		return (-1);

	va_start(lists, format);

	for (r = 0; format && format[r] != '\0'; r++)
	{
		if (format[r] != '%')
		{
			buffer[buff_ind++] = format[r];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);

			/* write(1, &format[r], 1);*/
			output_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &r);
			width = get_width(format, &r, lists);
			precision = get_precision(format, &r, lists);
			size = get_size(format, &r);
			++r;
			output = handle_print(format, &r, lists, buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			output_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(lists);
}

/**
 * print_buffer - prints the contents of the buffer 
 * @buffer: chars array
 * @buff_ind: index to add next char, repr length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write (1, &buff[0], *buff_ind);
	*buff_ind = 0;
}
