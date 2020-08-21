//
// Created by alexey on 12.08.2020.
//

#include "ft_printf.h"
#define NULLSTR "(null)"

static char 	*get_arg(char *s)
{
	return (ft_strsub(s, 0, ft_strlen(s)));
}

static char 	*retrieve_according_type(t_data_format *data, va_list ap)
{
	char	*string;

	if (data->type == 'd' || data->type == 'i')
		return (parse_type_d(data->specifier, ap));
	else if (data->type == 'p')
		return (ft_itoa_base((long long)va_arg(ap, void *), 16);
	else if (data->type == 'o')
		return (parse_type_o(data->specifier, ap));
	else if (data->type == 'u')
		return (parse_type_u(data->specifier, ap));
	else if (data->type == 'x')
		return (ft_tolower(ft_itoa_base(va_arg(ap, long long), 16)));
	else if (data->type == 'X')
		return (ft_itoa_base(va_arg(ap, long long), 16));
	else if (data->type == 'c')
		return (char_to_string(va_arg(ap, int)));
	else if (data->type == 's')
	{
		string = va_arg(ap, char*);
		return (string == NULL ? get_arg(NULLSTR) : get_arg(string));
	}
	else if (data->type == 'f')
		return (NULL);
	else
		return (NULL);
}

static void 	apply_specifiers_to_arg(t_data_format *data)
{
	process_flag(data, data->flag, data->is_digit);
}

int 	generate_output(t_data_format *data, va_list ap)
{
	int	result;

	result = 0;
	if (data->type != '\0')
	{
		data->argument = retrieve_according_type(data, ap);
		apply_specifiers_to_arg(data);
		result = MAX(data->width, (int) ft_strlen(data->argument));
		free(data->flag);
		free(data->argument);
	}
	return (print_signs(data->percentages / 2, PERCENT) + result);
}
