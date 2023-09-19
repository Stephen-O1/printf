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
 * @fmt: the format
 * @fn: the function associated.
 */
struct fmt;
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
}

/**
 * typedef struct fmt fmt_t - struct op
 */

/* Function to handle other specifiers*/
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Function to print in rot 13 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

 /* Function to print string in reverse */
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);

/* width handler */
int handler_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],int flags, int width, int precision, int size);
int write_num(int ind, char buff[], int flags, int width, int precision, int length, int padd, char extra_c);
int write_ printer(char buffer[], int ind, int length, int width, char padd, char extra_c, int flags, int padd_start);
int write_unsigned(int is_negative, int ind, char buffer[], int width, int precision, int size, int flags);

/*****UTILS*****/
int is_printable(char);
int append_hex_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif /* MAIN_H */
