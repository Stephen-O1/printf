#include "main.h"
 /**
  * handle_print - prints argument based on its type
  * @fmt: string to print the argument
  * @size: size specifier
  * @width: get width
  * @ind: ind
  * @buffer: buffer array to handle print
  */

int handle_print(const char *fmt, int *int, va_list list, char buffer[], flags, int width, int precision, int size)
{
	int r, printed_chars = -1;                                                                      
