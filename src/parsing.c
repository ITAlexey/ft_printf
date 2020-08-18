//
// Created by alexey on 10.08.2020.
//
#include "ft_printf.h"

static int		get_nbr_of_percentages(char const **format)
{
	int		percent_counter;

	percent_counter = 0;
	while (**format == PERCENT)
	{
		percent_counter++;
		(*format)++;
	}
	return (percent_counter);
}

int 	get_numeric_value(const char **format, int(*fun)(int), int symbol)
{
	int 	len;
	char 	*end;
	char 	*res;

	end = (char*)(*format);
	len = 0;
	while (fun(**format) == 1)
	{
		(*format)++;
		len++;
	}
	res = (len == 0 ? char_to_string(symbol) : ft_strsub(end, 0, len));
	len = ft_atoi(res);
	free(res);
	return (len);
}

static char 	get_type(char const **format, char *pattern)
{
	while (*pattern != '\0')
	{
		if (**format == *pattern)
		{
			(*format)++;
			break ;
		}
		pattern++;
	}
	return (*pattern);
}

static short	is_digit_type(char ch)
{
	return ((ch == 'd' || ch == 'l' || ch == 'h' || ch == 'i' || ch == 'f'
			|| ch == 'o' || ch == 'u' || ch == 'x' || ch == 'X') ? TRUE : FALSE);
}

int			parse_format(char const **format, t_data_format *data, va_list ap)
{
	data->percentages = get_nbr_of_percentages(format);
	if (data->percentages % 2 != 0)
	{
		data->flag = get_flags(format, is_matched_to_flag);
		data->width = get_numeric_value(format, ft_isdigit, ZERO);
		*format += **format == DOT ? 1 : 0;
		data->precision = get_numeric_value(format, ft_isdigit, ZERO);
		data->type = get_type(format, "cspdiouxXf");
		data->is_digit = is_digit_type(data->type);
		return (generate_output(data, ap));
	}
	return (print_signs(data->percentages / 2, PERCENT));
}
