#include "holberton.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#define BUFFER_SIZE 1024
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0; /* counter */
	int index = 0; /* index for buffer */
	char *buffer;

	/* initalize va list */
	va_start(list, format);
	/* malloc space for buffer */
	buffer = malloc(BUFFER_SIZE);
	/* loop the string format until reach '\0' */
	while (format && format[i] != '\0')
	{
		/* if find % symbol, pass the next character, list, index */
		/* of buffer and buffer to get_sp function*/
		if (format[i] == '%')
		{
			get_sp(format[i+1])(list, buffer, index);
			/* increase i by 1 to skip the index % */
			i = i + 1;
		}
		/* if % not found, just put character to buffer */
		else
		{
			buffer[index] = format[i];
		}
		i++;
		index++;
	}
	/* put a '\0' character at the end of the string */
	buffer[index] = '\0';
	write(1, buffer, BUFFER_SIZE);
	return (0);
}
