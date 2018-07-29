#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
void get_char(va_list list)
{
	_putchar(va_arg(list, int));
}
void get_string(va_list list)
{
	char *tmp;
	int i = 0;

	tmp = va_arg(list, char*);
	while (tmp[i] != '\0')
	{
		_putchar(tmp[i]);
		i++;
	}
}
