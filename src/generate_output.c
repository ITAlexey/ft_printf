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
		return (ft_itoa_base((long long)va_arg(ap, void *), 16));
	else if (data->type == 'o')
		return (parse_type_o(data->specifier, ap));
	else if (data->type == 'u')
		return (parse_type_u(data->specifier, ap));
	else if (data->type == 'x')
		return (ft_itoa_base(va_arg(ap, long long), 16));
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

void 	apply_modifiers(t_data_format *data, t_flag *flag, char type, int width, int *len)
{
	int 	diff;

	diff = *len - width;
	if (is_decimal_or_pointer(type))
	{
		if (diff < 0)
		{
			diff = ABC(diff);

		}
		else
		{
			
		}
	}
	else if (is_hex_or_octal(type))
	{
		if (diff < 0)
		{
			diff = ABC(diff);
			if (!flag->zero)
			{
				if (flag->hash == TRUE && ft_strcmp(data->argument, "0"))
				{
					data->argument = add_prefix(data->argument, type == 'x' || type == 'X' ? "0X" : "0");
					diff -= type == 'o' ? 1 : 2;
				}
				flag->neg ? ft_putstr(type == 'x' ? ft_strlowcase(data->argument) : data->argument) : print_signs(diff, SPACE);
				flag->neg ? print_signs(diff, SPACE) : ft_putstr(type == 'x' ? ft_strlowcase(data->argument) : data->argument);
			}
			else
			{
				if (flag->hash == TRUE && ft_strcmp(data->argument, "0"))
				{
					if (type == 'x' || type == 'X')
						ft_putstr(type == 'x' ? "0x" : "0X");
					else
						ft_putchar(ZERO);
					diff -= type == 'o' ? 1 : 2;
				}
				print_signs(diff, ZERO);
				ft_putstr(type == 'x' ? ft_strlowcase(data->argument) : data->argument);
			}
		}
		else
		{
			if (flag->hash == TRUE && ft_strcmp(data->argument, "0"))
			{
				data->argument = add_prefix(data->argument, type == 'x' || type == 'X' ? "0X" : "0");
				*len += type == 'o' ? 1 : 2;;
			}
			ft_putstr(type == 'x' ? ft_strlowcase(data->argument) : data->argument);
		}
	}
	else
	{
		if (diff < 0)
		{
			diff = ABC(diff);
			flag->neg ? ft_putstr(data->argument) : print_signs(diff, SPACE);
			flag->neg ? print_signs(diff, ZERO) : ft_putstr(data->argument);
		}
		else
			ft_putstr(data->argument);
	}
}

int 	generate_output(t_data_format *data, va_list ap)
{
	if (data->type != '\0')
	{
		data->argument = retrieve_according_type(data, ap);
		data->arg_len = (int)ft_strlen(data->argument);
		apply_modifiers(data, data->flag, data->type, data->width, &(data->arg_len));
		//process_flag(data, data->flag, data->type, data->width);
		free(data->flag);
		free(data->argument);
	}
	return (print_signs(data->percentages / 2, PERCENT) + MAX(data->width, data->arg_len));
}
