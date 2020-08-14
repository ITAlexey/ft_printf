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

static char		*record_matched_pattern(char const **format, int *symbols)
{
	char	*to_string;

	to_string = char_to_string(**format);
	(*format)++;
	*symbols += 1;
	return (to_string);
}

static char 	*get_width(char const **format, int *symbols)
{
	char		*end;
	char 		*width;
	int			diff;

	end = (char*)(*format);
	while (ft_isdigit(*end) != 0)
	{
		*symbols += 1;
		end++;
	}
	diff = end - *format;
	if (diff == 0)
		return (NULL);
	else
	{
		width = ft_strsub(*format, *symbols, diff);
		*format += diff;
		return (width);
	}
}

static char			*search_match(char const **format, char *pattern, int *symbols)
{
	char	*pointer;

	pointer = pattern;
	while (*pointer != '\0')
	{
		if (*pointer == **format)
			return (record_matched_pattern(format, symbols));
		pointer++;
	}
	return (NULL);
}

void 			parse_format(char const **format, t_data_format *data, t_pattern *pattern, va_list ap)
{
	int		*symbols;

	symbols = &(data->nbr_of_symbols);
	data->nbr_of_percent_signs = get_nbr_of_percentages(format);
	data->nbr_of_printed_percentages = data->nbr_of_percent_signs / 2;
	symbols += data->nbr_of_percent_signs;
	if (data->nbr_of_percent_signs % 2 != 0)
	{
		data->flag = search_match(format, pattern->flag, symbols);
		/*if (data->flag == NULL)
			printf("YES\n");*/
		data->width = get_width(format, symbols);
		data->numeric_value_of_width = data->width == NULL ? 0 : ft_atoi(data->width);
		//data->precisly = define_pricesly(format);
		//data->size = get_size(format);
		data->type = search_match(format, pattern->type, symbols);
		generate_output(data, ap);
	}
}
