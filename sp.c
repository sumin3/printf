#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * get_int - convert integer to string
 * @list: the character to add to buffer
 * @buffer: the buffer
 * @index: index of the buffer
 * Return: buffer
 */
char *get_int(va_list list, char *buffer, int *index)
{
	int n, m; /* number from argument */
	int len = 1; /* length of number */
	int tmp;
	int len_tmp;

	n = va_arg(list, int);
	m = n;
	/* increase len by 1 if m is negative */
	if (m < 0)
		len++;
	/* loop until m has only one digit */
	while (m / 10 != 0)
	{
		/* increase len by 1 by each time m divide by 10 */
		m = m / 10;
		len++;
	}
	len_tmp = len;
	/* if n has two or more digit */
	/* loop until n has only 1 digit by dividing m by 10 in each loop*/
	while (n <= -10 || n >= 10)
	{
		/* put the last digit of n in buffer from right to left */
		tmp = ((n % 10) >= 0) ? (n % 10) : -(n % 10);
		buffer[*index + len - 1] = tmp + '0';
		/* decrease len by 1 to move index backward */
		len--;
		n = n / 10;
	}
	/* for n is (-9) to (-1) */
	if (n < 0)
	{
		/* put the negative sign, and follow by n to buffer */
		buffer[*index] = '-';
		buffer[*index + len - 1] = -n + '0';
	}
	/* for n is (0) to (9) */
	/* put n to buffer */
	else
		buffer[*index] = n + '0';
	/* increase index */
	*index = *index + len_tmp - 1;
	return (buffer);
}

/**
 * not_match - free buffer
 * @list: the character to add to buffer
 * @buffer: the buffer
 * @index: index of the buffer
 * Return: null
 */
char *not_match(__attribute__((unused))va_list list,
__attribute__((unused))char *buffer, __attribute__((unused))int *index)
{
	return (NULL);
}

/**
 * get_char - put/add character in buffer
 * @list: the character to add to buffer
 * @buffer: the buffer
 * @index: index of the buffer
 *
 * Return: buffer
 */
char *get_char(va_list list, char *buffer, int *index)
{
	buffer[*index] = va_arg(list, int);
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
char *get_string(va_list list, char *buffer, int *index)
{
	char *tmp;
	int i = 0;

	tmp = va_arg(list, char*);
	while (tmp[i] != '\0')
	{
		buffer[*index] = tmp[i];
		i++;
		(*index)++;
	}
	(*index)--;
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
char *get_percent(__attribute__((unused))va_list list, char *buffer,
int *index)
{
	buffer[*index] = '%';
	return (buffer);
}
