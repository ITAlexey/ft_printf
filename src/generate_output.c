//
// Created by alexey on 12.08.2020.
//

#include "ft_printf.h"
#define NULLSTR "(null)"

static char 	*retrieve_according_type(t_data_format *data, va_list ap)
{
	char	*string;

	if (data->type == 'd' || data->type == 'i')
		return (parse_type_d(data->specifier, ap));
	else if (data->type == 'p')
		return (add_prefix(ft_strlowcase(ft_itoa_base((long long)va_arg(ap, void *), 16)), "0x"));
	else if (data->type == 'o')
		return (parse_type_o(data->specifier, ap));
	else if (data->type == 'u')
		return (parse_type_u(data->specifier, ap));
	else if (data->type == 'x')
		return (ft_strlowcase(ft_itoa_base(va_arg(ap, long long), 16)));
	else if (data->type == 'X')
		return (ft_itoa_base(va_arg(ap, long long), 16));
	else if (data->type == 'c')
		return (char_to_string(va_arg(ap, int)));
	else if (data->type == 's')
	{
		string = va_arg(ap, char*);
		return (ft_strdup(string == NULL ? NULLSTR : string));
	}
	else if (data->type == 'f')
		return (NULL);
	else
		return (NULL);
}

int 	generate_output(t_data_format *data, va_list ap)
{
	int	result;

	result = 0;
	if (data->type != '\0')
	{
		data->argument = retrieve_according_type(data, ap);
		process_flag(data, data->flag, data->type, data->width);
		result = MAX(data->width, (int) ft_strlen(data->argument));
		free(data->flag);
		free(data->argument);
	}
	return (print_signs(data->percentages / 2, PERCENT) + result);
}
