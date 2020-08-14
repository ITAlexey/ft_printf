//
// Created by alexey on 10.08.2020.
//
#include "ft_printf.h"
#define PERCENT 37

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

static char		*record_matched_pattern(char const **format)
{
	char	*to_string;

	to_string = char_to_string(**format);
	(*format)++;
	return (to_string);
}

static char 	*get_width(char const **format)
{
	char		*end;
	char 		*width;
	int			diff;

	end = (char*)(*format);
	while (ft_isdigit(*end) != 0)
		end++;
	diff = end - *format;
	if (diff)
		return (NULL);
	else
	{
		width = ft_strsub(*format, 0, diff);
		*format += diff;
		return (width);
	}
}

static char			*search_match(char const **format, char *pattern)
{
	char	*pointer;

	if ((pointer = ft_strchr(pattern, **format)) != NULL)
		return (record_matched_pattern(format));
	return (pointer);
}

int 		print_percents(int times)
{
	int	tmp;

	tmp = times;
	while (tmp)
	{
		ft_putchar(PERCENT);
		tmp--;
	}
	return (times);
}

int			parse_format(char const **format, t_data_format *data, va_list ap)
{
	data->percentages = get_nbr_of_percentages(format);
	if (data->percentages % 2 != 0)
	{
		data->flag = search_match(format, " +-#0");
		data->width = get_width(format);
		data->numeric_value_of_width = data->width == NULL ? 0 : ft_atoi(data->width);
		data->type = search_match(format, "cspdiouxXf");
		return (generate_output(data, ap));
	}
	return (print_percents(data->percentages / 2));
}
