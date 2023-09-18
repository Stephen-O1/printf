#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define BUFF_SIZE 1024
#define UNUSED(X) (void)(x)

/* SIZES */
#define S_SHORT 1
#define S_LONG 2

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct fmt - struct op 
 * @fmt: format
 * @fn: the function associated.
 */
struct fmt;
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);int _printf(const char *format, ...);
};



#endif /* MAIN_H */
