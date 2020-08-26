//
// Created by alexey on 12.08.2020.
//

#include "ft_printf.h"
#define NULLSTR "(null)"

static void		align_dp_by_width(t_data_format *data, t_flag *flag, char type, int diff)
{
	int 	offset;

	offset = 0;
	if (*(data->arg) != '-' && (flag->space + flag->pos))
	{
		ft_putchar(flag->pos ? PLUS : SPACE);
		diff--;
	}
	if (flag->zero)
	{
		if (*(data->arg) == '-' || type == 'p')
		{
			ft_putstr(type == 'p' ? "0x" : "-");
			offset = type == 'p' ? 2 : 1;
		}
	}
	put_space_or_zero(data->arg + offset, flag, diff);
}

static void 	align_ox_by_width(t_data_format *data, t_flag *flag, char type, int diff)
{
	if (flag->hash == TRUE && ft_strcmp(data->arg, "0"))
	{
		diff -= type == 'o' ? 1 : 2;
		data->arg = flag->zero ? data->arg : add_prefix(data->arg, type == 'x' || type == 'X' ? "0x" : "0");
		if (flag->zero && (type == 'x' || type == 'X'))
			ft_putstr(type == 'x' ? "0x" : "0X");
		else if (flag->zero)
			ft_putchar(ZERO);
	}
	put_space_or_zero(type == 'X' ? ft_strupcase(data->arg) : data->arg, flag, diff);
}

static char 	*retrieve_according_type(t_data_format *data, va_list ap)
{
	char	*string;

	if (data->type == 'd' || data->type == 'i')
		return (parse_type_d(data->specifier, ap));
	else if (data->type == 'p')
		return (add_prefix(ft_itoa_base((long long)va_arg(ap, void *), 16), "0x"));
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
	//else if (data->type == 'f')
		//return (parse_type_f(data, data->decimal, data->specifier, ap));
	else
		return (NULL);
}

void 	apply_modifiers(t_data_format *data, t_flag *flag, char type, int width)
{
	int 	diff;
	int 	len;

	len = (int)ft_strlen(data->arg);
	diff = len - width;
	if (is_difp(type))
	{
		if (diff < 0)
			align_dp_by_width(data, flag, type, ABC(diff));
		else
		{
			if (*(data->arg) != '-' && (flag->space + flag->pos))
				data->arg = add_prefix(data->arg, flag->pos ? "+" : " ");
			ft_putstr(data->arg);
		}
	}
	else if (is_oXx(type))
	{
		if (diff < 0)
			align_ox_by_width(data, flag, type, ABC(diff));
		else
		{
			if (flag->hash == TRUE && ft_strcmp(data->arg, "0"))
				data->arg = add_prefix(data->arg, type == 'x' || type == 'X' ? "0x" : "0");
			ft_putstr(type == 'X' ? ft_strupcase(data->arg) : data->arg);
		}
	}
	else
	{
		if (diff < 0)
		{
			diff = ABC(diff);
			flag->neg ? ft_putstr(data->arg) : print_signs(diff, SPACE);
			flag->neg ? print_signs(diff, ZERO) : ft_putstr(data->arg);
		}
		else
			ft_putstr(data->arg);
	}
}

void 	put_space_or_zero(char *arg, t_flag *flag, int times)
{
	if (flag->zero)
	{
		print_signs(times, ZERO);
		ft_putstr(arg);
	}
	else
	{
		flag->neg ? ft_putstr(arg) : print_signs(times, SPACE);
		flag->neg ? print_signs(times, SPACE) : ft_putstr(arg);
	}
}

int 	generate_output(t_data_format *data, va_list ap)
{
	int result;

	result = 0;
	if (data->type != '\0')
	{
		data->arg = retrieve_according_type(data, ap);
		apply_modifiers(data, data->flag, data->type, data->width);
		result = MAX(data->width, (int) ft_strlen(data->arg));
		free(data->flag);
		free(data->arg);
	}
	return (print_signs(data->percentages / 2, PERCENT) + result);
}
