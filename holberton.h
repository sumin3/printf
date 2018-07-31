#ifndef HOLBERTON_H_
#define HOLBERTON_H_
#include <stdarg.h>

/**
 * struct sp - Struct sp
 *
 * @sp: the specifier
 * @f: the function associated
 */
typedef struct sp
{
	char sp;
	char *(*f)(va_list list, char *buffer, int *index);
} sp_t;

int _printf(const char *format, ...);
char *(*get_sp(char c))(va_list list, char *buffer, int *index);
char *get_char(va_list list, char *buffer, int *index);
char *get_string(va_list list, char *buffer, int *index);
char *get_percent(va_list list, char *buffer, int *index);
char *not_match(va_list list, char *buffer, int *index);
int _putchar(char c);
char *get_int(va_list list, char *buffer, int *index);
#endif
