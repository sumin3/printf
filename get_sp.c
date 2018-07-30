#include "holberton.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/**
 * get_sp - selects the correct specifier function
 * @s: specifier that need check
 *
 * Return: buffer
 */

char *(*get_sp(char c))(va_list list, char *buffer, int *index)
{
	sp_t sps[] = {
		{'c', get_char},
		{'s', get_string},
		{'%', get_percent}
	}; /* declare structure array called sps */
	/* 1st column is specifier. 2nd column is the corresponding function */
	int i; /* counter */
	int n; /* number of structures */

	i = 0;
	n = 3;
	/* loop n time to compare c with 1st column of structure array*/
	while (i < n)
	{
		if (c == sps[i].sp)
		{
			/* if find match, return the corresponding function*/
			return (sps[i].f);
		}
		i++;
	}
	/* if not match, exit with error message */
	write(2,"Error\n", 7);
	exit(99);
}
