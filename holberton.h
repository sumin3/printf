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
	char *(*f)(va_list list);
} sp_t;

int _printf(const char *format, ...);
char *(*get_sp(char c))(va_list list);
char *get_char(va_list list);
char *get_string(va_list list);
char *get_percent(va_list list);
char *not_match(va_list list);
int _putchar(char c);
char *get_int(va_list list);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
#endif
