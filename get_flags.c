#include "main.h"

/**
 * get_flags - calculate active flags
 * @format: format string to print the arguments
 * @i: take parameters
 * Return: flags
 */

int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8 16 */
	int r, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1 ; format[curr_i] != '\0' ; curr_i++)
	{
		for (r = 0 ; FLAGS_CH[r] != '\0' ; r++)
			if (format[curr_i] == FLAGS_CH[r])
			{
				flags |= FLAGS_ARR[r];
				break;
			}
		if (FLAGS_CH[r] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
