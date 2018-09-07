#ifndef HOLBERTON_H_
#define HOLBERTON_H_
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
/**
 * struct sp - Struct sp
 *
 * @sp: the specifier
 * @f: the function associated
 */
typedef struct sp
{
	char sp;
	char *(*f)(va_list list, int *char_count);
} sp_t;
char *percent_helper(const char *format, va_list list, int *char_count, int *status,
                   char *tmp_buff, int *find_percent, int *match, int *current_idx);
int write_buff(int *count, int *char_count, char *tmp_buff);
int _printf(const char *format, ...);
char *copy_literal(const char *format, int *char_count, int *current_idx, int *literal_beg);
char *(*get_sp(char c))(va_list list, int *char_count);
char *get_char(va_list list, int *char_count);
char *get_string(va_list list, int *char_count);
char *get_percent(va_list list, int *char_count);
char *not_match(va_list list, int *char_count);
int _putchar(char c);
char *get_int(va_list list, int *char_count);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
#endif
