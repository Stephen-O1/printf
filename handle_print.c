#include "main.h"
 /**
  * handle_printf - prints argument based on its type
  * @fmt: string to print the argument
  * @size: size specifier
  * @width: get width
  * @ind: ind
  * @flags: calculate active flags
  * @list: list of arguments to be printed
  * @precision: precision specification
  * @buffer: buffer array to handle print
  * Return: 1 or 2
  */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int r, printed_chars = -1, unknown_len = 0;

	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', printf_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', printf_oct}, {'x', print_hex},
		{'X', printf_hex_aux}, {'p', printf_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (r = 0; fmt_types[r].fmt != '\0'; r++)
		if (fmt[*ind] == fmt_types[r].fmt)
			return (fmt_types[r].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[r].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &fmt[*ind], 1);
		return (unknown_len);
	}

	return (printed_chars);
}
