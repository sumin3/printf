#include "holberton.h"

/**
 * _printf - print anyting
 * @format: the format and string that need to print
 * Return: return length of the buffer. if error, return -1
 */
int _printf(const char *format, ...)
{
	va_list list;
	int count = 0, literal = 0, char_count = 0;
	char *tmp_buff = NULL;
	int literal_beg = 0, current_idx = 0, match = 0, status = 0, find_percent = 0;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (format && format[current_idx] != '\0')
	{
		literal = 0;
		char_count = 0;
		literal_beg = current_idx;
		while (format[current_idx] != '%' && format[current_idx] != '\0')
		{
			literal = 1;
			current_idx++;
		}
		if (format[current_idx] == '%' && literal == 0)
		{
			tmp_buff = percent_helper(format, list, &char_count, &status, tmp_buff,
						  &find_percent, &match, &current_idx);
			if (tmp_buff == NULL)
				continue;
		}
		else
			tmp_buff = copy_literal(format, &char_count, &current_idx, &literal_beg);
		write_buff(&count, &char_count, tmp_buff);
		if (format[current_idx] != '\0' && literal == 0)
			current_idx++;
	}
	if (status == 1)
		count = -1;
	va_end(list);
	return (count);
}
