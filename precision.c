#include" main.h"
/**
 * get_precision - calculate the precision for string
 * @format: formatted string to print the argument
 * @i: list of arguments printed
 * @list: list of arguments
 * Return: precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int precision = -1;
	int curr_i = *i + 1;

	if (format[curr_i] != '.')
		return (precision);
	precision = 0;

	for (curr_i += 1 ; format[curr_i] != '\0' ; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			breake;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
