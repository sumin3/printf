#include "holberton.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
/**
 * _printf - print anyting
 * @format: the format and string that need to print
 * Return: return length of the buffer. if error, return -1
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0; /* counter */
	int *index = NULL;
	int index1 = 0;
	char *buffer = NULL;
	int len = 0;
	char *m = NULL;
	int error = 0;

	index = &index1;
	if (format == NULL)
		return (-1);
	/* initialize va list */
	va_start(list, format);
	/* malloc space for buffer */
	buffer = calloc(BUFFER_SIZE, sizeof(char));
	if (buffer == NULL)
		return (-1);
	/* loop the string format until reach '\0' */
	while (format && format[i] != '\0')
	{
		/* if find % symbol, pass the next character, list, index */
		/* of buffer and buffer to get_sp function*/
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				m = get_sp(format[i + 1])(list, buffer, index);
				error = 1;
				if (m == NULL)
					error = 2;
				else
					i++;
			}
			if (format[i + 1] == '\0' && error == 0)
			{
				error = 3;
				i++;
			}
			if (format[i + 1] == '\0' && error == 1)
				error = 3;
		}
		else
		{
			/* if % not found, just put character to buffer */
			buffer[*index] = format[i];
		}
		if (error == 2)
			buffer[*index] = format[i];
		if (format[i] != '\0')
			i++;
		(*index)++;
	}
	while (buffer[len] != '\0')
		len++;
	/* put a '\0' character at the end of the string */
	buffer[*index] = '\0';
	write(1, buffer, len);
	free(buffer);
	if (error == 3)
		len = -1;
	va_end(list);
	return (len);
}
