#include "holberton.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0; /* counter */
	int *index = NULL; /* index for buffer */
	int index1 = 0;
	char *buffer;

	index = &index1;
	if (format == NULL)
		return (-1);
	/* initalize va list */
	va_start(list, format);
	/* malloc space for buffer */
	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		return (-1);
	/* loop the string format until reach '\0' */
	while (format && format[i] != '\0')
	{
		/* if find % symbol, pass the next character, list, index */
		/* of buffer and buffer to get_sp function*/
		if (format[i] == '%')
		{
			get_sp(format[i+1])(list, buffer, index);
			/* increase i by 1 to skip the index % */
			i++;
		}
		/* if % not found, just put character to buffer */
		else
		{
			buffer[*index] = format[i];
		}
		i++;
		(*index)++;
	}
	/* put a '\0' character at the end of the string */
	buffer[*index] = '\0';
	write(1, buffer, BUFFER_SIZE);
	free(buffer);
	return (0);
}
