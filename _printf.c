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
	int i = 0, j = 0, len = 0, count = 0, num_to_tmp = 0;
	char *buffer = NULL;
	int lit_1st_idx = 0, current_idx = 0;
	char *tmp_buffer = NULL;
	int find_percent = 0, find = 0;
	int not_match = 0;
	int status = 0, tmp_len = 0;
	int char_count = 0;


	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (format && format[current_idx] != '\0')
	{
		find = 0;
		char_count = 0;
		lit_1st_idx = current_idx;
		while (format[current_idx] != '%' && format[current_idx] != '\0')
		{
			find = 1;
			current_idx++;
		}

		/* if find % symbol, pass the next char to get_sp function*/
		if (format[current_idx] == '%' && find == 0)
		{
			if (format[current_idx + 1] != '\0')
			{
				tmp_buffer = get_sp(format[current_idx + 1])(list, &char_count);
				find_percent = 1;
				if (tmp_buffer == NULL)
				{
					tmp_buffer = malloc(sizeof(char) * 2);
					tmp_buffer[0] = '%';
					tmp_buffer[1] = '\0';
					not_match = 1;
					char_count = 1;
				}
				else
					current_idx++;
			}
			else if (format[current_idx + 1]
				 == '\0' && (find_percent == 0 || not_match == 0))
			{
				/* change the flag to 1 */
				current_idx++;
				status = 1;
				continue;
			}
			else if (format[current_idx + 1] == '\0' && not_match == 1)
			{
				tmp_buffer = malloc(sizeof(char) * 2);
				tmp_buffer[0] = '%';
				tmp_buffer[1] = '\0';
				char_count = 1;
			}

		}
		else
		{
			/* if % not found, just put literal char to tmp_buffer*/
			tmp_buffer = malloc(current_idx - lit_1st_idx + 1);
			if (tmp_buffer == NULL)
				return (-1);
			/* copy string */
			num_to_tmp = current_idx - lit_1st_idx;
			char_count = num_to_tmp;
			for (i = 0; i < num_to_tmp; i++)
			{
				tmp_buffer[i] = format[lit_1st_idx];
				lit_1st_idx++;
			}
			tmp_buffer[i] = '\0';

		}
		len = char_count;
		buffer = malloc(BUFFER_SIZE * sizeof(char));
		for (j = 0; j < char_count; j = j + BUFFER_SIZE)
		{

			if (buffer == NULL)
				return (-1);
			if (len > BUFFER_SIZE)
			{
				len = len - BUFFER_SIZE;
				_strncpy(buffer, tmp_buffer + j, BUFFER_SIZE);
				count += write(1, buffer, BUFFER_SIZE);

			}
			else
			{
				_strncpy(buffer, tmp_buffer + j, BUFFER_SIZE);
				count += write(1, buffer, len);
			}
		}
		free(buffer);
		free(tmp_buffer);
		if (format[current_idx] != '\0' && find == 0)
			current_idx++;
	}

/* put a '\0' character at the end of the string */
	if (status == 1)
		count = -1;
	va_end(list);
	return (count);
}
