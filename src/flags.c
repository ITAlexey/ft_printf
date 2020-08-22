//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"

char 	*add_prefix(char *arg, char *pattern)
{
	char	*tmp;

	tmp = arg;
	arg = ft_strjoin(pattern, arg);
	free(tmp);
	return (arg);
}

static void 	put_zeros(t_flag *flag, int diff)
{
	if (flag->pos + flag->space)
	{
		ft_putchar(flag->pos ? PLUS : SPACE);
		diff--;
	}
	print_signs(diff, ZERO);
}

static void 	put_spaces(t_flag *flag, int diff)
{
	if (flag->pos + flag->space)
	{
		diff--;
		print_signs(diff, SPACE);
		ft_putchar(flag->pos ? PLUS : SPACE);
	}
	else
		print_signs(diff, SPACE);
}

static void		align_by_right_side(char *arg, short *offset, t_flag *flag, int diff)
{
	if (*arg == '-')
	{
		*offset = flag->zero == TRUE ? 1 : 0;
		ft_putchar(*offset != 0 ? MINUS : 0);
		print_signs(diff, *offset != 0 ? ZERO : SPACE);
	}
	else if (flag->pos + flag->space + flag->zero)
		flag->zero == TRUE ? put_zeros(flag, diff) : put_spaces(flag, diff);
	else
		print_signs(diff, SPACE);
	ft_putstr(arg + *offset);
}

static void 	align_by_width(char *arg, int arg_len, t_flag *flag, int width, char type)
{
	int		diff;
	short 	offset;

	diff = width - arg_len;
	offset = 0;
	if (flag->neg == TRUE)
	{
		if (is_digit_type(type) && *(arg) != '-' && (flag->pos + flag->space) != 0)
			ft_putchar(flag->pos == TRUE ? PLUS : SPACE);
		ft_putstr(arg);
		print_signs(diff, SPACE);
	}
	else if (is_digit_type(type))
		align_by_right_side(arg, &offset, flag, diff);
	else
	{
		print_signs(diff, SPACE);
		ft_putstr(arg);
	}
}

static short		is_not_decimal_type(char ch)
{
	return ((ch == 'x' || ch == 'X' || ch == 'o') ? 1 : 0);
}

void		process_flag(t_data_format *data, t_flag *flag, char type, int width)
{
	int 	len;

	if (flag->hash == TRUE && is_not_decimal_type(type) && ft_strcmp(data->argument, "0"))
		data->argument = add_prefix(data->argument, type == 'x' || type == 'X' ? "0X" : "0");
	len = ft_strlen(data->argument);
	if (len >= width)
	{
		if (is_digit_type(type) && (flag->pos + flag->space) != 0 && *(data->argument) != '-')
			data->argument = add_prefix(data->argument, flag->pos == TRUE ? "+" : " ");
		ft_putstr(data->argument);
	}
	else
		align_by_width(data->argument, len, flag, width, type);
}