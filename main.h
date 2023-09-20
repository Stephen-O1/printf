#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define UNUSED(X) (void)(x)

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct op 
 * @fmt: the format
 * @fn: the function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - struct op
 * @fmt: format
 * @fm_t: function associated
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****** Functions  *****/

/* Function to print chars and strings */

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Function to print numbers */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper( va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list types, char buffer[], char map_to[], char flag_ch, int flags, int width, int precision, int size);

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
int write_pointer(char buffer[], int ind, int length, int width, char padd, char extra_c, int flags, int padd_start);
int write_unsigned(int is_negative, int ind, char buffer[], int width, int precision, int size, int flags);

/*****UTILS*****/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

int printf_pointer(va_list val);
int printf_hex_aux(unsigned long int num);
int printf_HEX_aux(unsigned int num);
int printf_exclusive_string(va_list val);
int printf_HEX(va_list val);
int printf_hex(va_list val);
int printf_oct(va_list val);
int printf_unsigned(va_list args);
int printf_bin(va_list val);
int printf_srev(va_list args);
int printf_rot13(va_list args);
int printf_int(va_list args);
int printf_dec(va_list args);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int rev_string(char *s);
int _strlenc(const char *s);
int printf_37(void);
int printf_char(va_list val);
int printf_string(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
