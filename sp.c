#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * get_char - put/add character in buffer
 * @list: the character to add to buffer
 * @buffer: the buffer
 * @index: index of the buffer
 *
 * Return: buffer
 */
char *get_char(va_list list, char *buffer, int index)
{
	buffer[index] = va_arg(list, int);
	return (buffer);
}

/**
 * get_string - put/add string in buffer
 * @list: the string to add to buffer
 * @buffer: the buffer
 * @index: index of the buffer
 *
 * Return: buffer
 */
char *get_string(va_list list, char *buffer, int index)
{
	char *tmp;
	int i = 0;

	tmp = va_arg(list, char*);
	while (tmp[i] != '\0')
	{
		buffer[index] = tmp[i];
		i++;
	}
	return (buffer);
}

/**
 * get_percent - put/add percent in buffer
 * @list: the percent to add to buffer
 * @buffer: the buffer
 * @index: index of the buffer
 *
 * Return: buffer
 */
char *get_percent(__attribute__((unused))va_list list, char *buffer, int index)
{
	buffer[index] = '%';
	return (buffer);
}
