//
// Created by alexey on 10.08.2020.
//
#include "ft_printf.h"
#define PERCENT 37
#define ISNULL(pointer) if ((pointer) == NULL) return (pointer)

static int 		get_nbr_of_percentages(char const *format)
{
	int 	percent_counter;

	percent_counter = 0;
	while (*format == PERCENT) {
		percent_counter++;
		format++;
	}
	return (percent_counter);
}

static char 	*get_type_of_flag(char const *format, char *pattern)
{
	char	*pointer;
	char 	*to_string;
	char 	ch;

	ch = *format;
	pointer = pattern;
	while (*pointer != '\0')
	{
		if (*pointer == ch)
		{
			to_string = (char*)malloc(1); // allocated memory
			ISNULL(to_string);
			format++;
			return (ft_strncpy(to_string, pointer, 1));
		}
		pointer++;
	}
	return (NULL);
}

void 			parse_format(char const *format, t_data_format *data, t_pattern *pattern)
{
	data->nbr_of_percent_signs = get_nbr_of_percentages(format);
	data->nbr_of_printed_percentages = data->nbr_of_percent_signs / 2;
	data->flag_type = get_type_of_flag(format, pattern->flag_pattern);
}
