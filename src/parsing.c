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
	while (fun(**format))
	{
		(*format)++;
		len++;
	}
	res = (len == 0 ? char_to_string(symbol) : ft_strsub(end, 0, len));
	len = ft_atoi(res);
	free(res);
	return (len);
}

static short 	get_specifier(char const **format)
{
	short	specifier;

	specifier = FALSE;
	if (**format == 'l' || **format == 'h' || **format == 'L')
	{
		if (**format == 'l' && *(*format + 1) == 'l')
			specifier = LL;
		else if (**format == 'h' && *(*format + 1) == 'h')
			specifier = HH;
		else if (**format == 'l')
			specifier = L;
		else if (**format == 'h')
			specifier = H;
		else
			specifier = BIGL;
		*format += specifier == HH || specifier == LL ? 2 : 1;
	}
	return (specifier);
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

static int 		get_precision(char const **format)
{
	short	is_dot;

	is_dot = **format == DOT ? 1 : 0;
	if (is_dot)
		(*format)++;
	return (is_dot ? get_numeric_value(format, ft_isdigit, ZERO) : 6);
}

int			parse_format(char const **format, t_data_format *data, va_list ap)
{
	data->percentages = get_nbr_of_percentages(format);
	if (data->percentages % 2 != 0)
	{
		data->flag = get_flags(format, is_matched_to_flag);
		data->width = get_numeric_value(format, ft_isdigit, ZERO);
		data->precision = get_precision(format);
		data->specifier = get_specifier(format);
		data->type = get_type(format, "cspdiouxXf");
	}
	return (generate_output(data, ap));
}
