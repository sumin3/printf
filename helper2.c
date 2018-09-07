#include "holberton.h"
/**
 * copy_literal - copy literal string to buffer
 * @format: argument
 * @char_count: number of character stored in buffer
 * @current_idx: current index
 * @literal_beg: the first index of literal
 * Return: return buffer
 */
char *copy_literal(const char *format, int *char_count,
		   int *current_idx, int *literal_beg)
{
	char *tmp_buff = NULL;
	int num_to_tmp = 0, i = 0;

	tmp_buff = malloc(*(current_idx) - *(literal_beg) + 1);
	if (tmp_buff == NULL)
		return (NULL);
	num_to_tmp = *(current_idx) - *(literal_beg);
	*(char_count) = num_to_tmp;
	for (i = 0; i < num_to_tmp; i++)
	{
		tmp_buff[i] = format[*literal_beg];
		*(literal_beg) = *(literal_beg) + 1;
	}
	tmp_buff[i] = '\0';
	return (tmp_buff);
}
/**
 * write_buff - write string from buffer
 * @count: the number of written character
 * @tmp_buff: the buffer
 * @char_count: number of character that stores in buffer
 * Return: 0
 */
int write_buff(int *count, int *char_count, char *tmp_buff)
{
	int len = *char_count, j;
	char *buff = NULL;

	buff = malloc(BUFFER_SIZE * sizeof(char));
	for (j = 0; j < *char_count; j = j + BUFFER_SIZE)
	{
		if (buff == NULL)
			return (-1);
		if (len > BUFFER_SIZE)
		{
			len = len - BUFFER_SIZE;
			_strncpy(buff, tmp_buff + j, BUFFER_SIZE);
			*(count) += write(1, buff, BUFFER_SIZE);
		}
		else
		{
			_strncpy(buff, tmp_buff + j, BUFFER_SIZE);
			*(count) += write(1, buff, len);
		}
	}
	free(buff);
	free(tmp_buff);
	return (0);
}
/**
 * percent_helper - handle specifiler - %
 * @format: argument
 * @list: argument list
 * @char_count: number of char stored in buffer
 * @status: the return value
 * @tmp_buff: buffer that stores a string
 * @find_percent: flag for percent symbol
 * @match: flag for found specifiler
 * @current_idx: current index
 * Return: return string tmp_buff if there is string need to write,
 * otherwise, return NULL
 */
char *percent_helper(const char *format, va_list list, int *char_count,
		     int *status, char *tmp_buff, int *find_percent,
		     int *match, int *current_idx)
{
	if (format[*(current_idx) + 1] != '\0')
	{
		tmp_buff = get_sp(format[*(current_idx) + 1])(list, char_count);
		*find_percent = 1;
		if (tmp_buff == NULL)
		{
			tmp_buff = malloc(sizeof(char) * 2);
			tmp_buff[0] = '%';
			tmp_buff[1] = '\0';
			*match = 1;
			*char_count = 1;
		}
		else
			*(current_idx) = *(current_idx) + 1;
	}
	else if (format[*(current_idx) + 1] == '\0' &&
		 (*find_percent == 0 || *match == 0))
	{
		*(current_idx) = *(current_idx) + 1;
		*status = 1;
		return (NULL);
	}
	else if (format[*(current_idx) + 1] == '\0' && *match == 1)
	{

		tmp_buff = malloc(sizeof(char) * 2);
		tmp_buff[0] = '%';
		tmp_buff[1] = '\0';
		*char_count = 1;
	}
	return (tmp_buff);
}
