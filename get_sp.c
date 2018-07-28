#include "holberton.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * get_sp - selects correct specifier
 * @s: specifier passed as argument to program
 *
 * Return: result
 */

char *(get_sp(char *s))(va_list list)
{
	sp_t sps[] = {
		{"c", get_char},
		{"s", get_string}
	};
	int i;

	i = 0;
	while (i < 2)
	{
		if (*s == *sps[i].sp)
		{
			return (sps[i].f);
		}
		i++;
	}
}
