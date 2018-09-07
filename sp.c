#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * get_int - convert integer to string
 * @list: the character to add to string
 * Return: string
 */
char *get_int(va_list list)
{
	int num, num_tmp; /* number from argument */
	int len = 1; /* length of number */
	int last_digit;
	char *string = NULL;

	num = va_arg(list, int);
	num_tmp = num;
	/* increase len by 1 if num_tmp is negative */
	if (num_tmp < 0)
		len++;
	/* loop until num_tmp has only one digit */
	while (num_tmp / 10 != 0)
	{
		/* increase len by 1 by each time num_tmp divide by 10 */
		num_tmp = num_tmp / 10;
		len++;
	}
	string = malloc(sizeof(char) * len + 1);
		if (string == NULL)
			return (NULL);

	string[len + 1] = '\0';
	/* loop until num has only 1 digit by dividing num by 10 in each loop*/
	while (num <= -10 || num >= 10)
	{
		/* put the last digit of num in string from right to left */
		last_digit = ((num % 10) >= 0) ? (num % 10) : -(num % 10);
		string[len - 1] = last_digit + '0';
		/* decrease len by 1 to move index backward */
		len--;
		num = num / 10;
	}
	/* for num is (-9) to (-1) */
	if (num < 0)
	{
		/* put the negative sign, and follow by num to string */
		string[0] = '-';
		string[1] = -num + '0';
	}
	/* for n is (0) to (9), put num to string*/
	else
		string[0] = num + '0';
	return (string);
}

/**
 * not_match - return null
 * @list: not use variable
 * Return: null
 */
char *not_match(__attribute__((unused))va_list list)
{
	return (NULL);
}

/**
 * get_char - put/add character in buffer
 * @list: the character to add to buffer
 * Return: buffer
 */
char *get_char(va_list list)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 2);
		if (buffer == NULL)
			return (NULL);
	buffer[0] = va_arg(list, int);
	/* put '\0' at the end of string */
	buffer[1] = '\0';
	return (buffer);
}

/**
 * get_string - put/add string in buffer
 * @list: the string to add to buffer
 *
 * Return: buffer
 */
char *get_string(va_list list)
{
	char *tmp = NULL;
	char *buffer = NULL;
	int i = 0, len = 0;

	tmp = va_arg(list, char*);
	/* if argument is NULL, print (null) */
	if (tmp == NULL)
		tmp = "(null)";
	len = _strlen(tmp);
	buffer = malloc(sizeof(char) * len);
		if (buffer == NULL)
			return (NULL);
	/* copy string to buffer */
	while (tmp[i] != '\0')
	{
		buffer[i] = tmp[i];
		i++;
	}
	/* put '\0' at the end of string */
	buffer[i] = '\0';
	return (buffer);
}

/**
 * get_percent - put/add percent in buffer
 * @list: the percent to add to buffer
 * Return: buffer
 */
char *get_percent(__attribute__((unused))va_list list)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 2);
		if (buffer == NULL)
			return (NULL);
	buffer[0] = '%';
	buffer[1] = '\0';
	return (buffer);
}
