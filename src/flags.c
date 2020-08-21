//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"

static char 	*add_prefix(char *arg, char type)
{
	char	*tmp;

	tmp = arg;
	if (ft_strequ(arg, "0") != 0)
	{
		if (type == 'x')
			arg = ft_strjoin("0x", arg);
		else if (type == 'X')
			arg = ft_strjoin("0X", arg);
		else
			arg = ft_strjoin("0", arg);
		free(tmp);
	}
	return (arg);
}

static void 	align_by_width(char *arg, int arg_len, t_flag *flag, int width, short is_digit)
{
	int		diff;
	short 	offset;

	diff = width - arg_len;
	offset = 0;
	if (flag->neg == TRUE)
	{
		if (is_digit == TRUE && *(arg) != '-' && (flag->pos + flag->space) != 0)
			ft_putchar(flag->pos == TRUE ? PLUS : SPACE);
		ft_putstr(arg);
		print_signs(diff, SPACE);
	}
	else if (is_digit == TRUE)
	{
		if (*arg == '-')
		{
			offset = flag->zero == TRUE ? 1 : 0;
			ft_putchar(offset != 0 ? MINUS : 0);
			print_signs(diff, offset != 0 ? ZERO : SPACE);
			ft_putstr(arg + offset);
		}
		else
		{
			if (flag->pos + flag->space + flag->zero != 0)
			{
				ft_putchar(flag->pos == TRUE ? PLUS : 0);
				ft_putchar(flag->space == TRUE ? SPACE : 0);
				print_signs(--diff, flag->zero == TRUE ? ZERO : SPACE);
				ft_putstr(arg);
			}
			else
			{
				print_signs(diff, SPACE);
				ft_putstr(arg);
			}
		}
	}
	else
	{
		if (flag->hash == TRUE && data->type == 'x' || data->type == 'X' || data->type == 'o')
			arg = add_prefix(arg, data->type);
		print_signs(diff, SPACE);
		ft_putstr(arg);
	}
}

void		process_flag(t_data_format *data, t_flag *flag, short is_digit)
{
	int 	len;
	char 	*tmp;

	len = ft_strlen(data->argument);
	if (len >= data->width)
	{
		if (is_digit == TRUE && (flag->pos + flag->space) != 0 && *(data->argument) != '-')
		{
			tmp = data->argument;
			data->argument = ft_strjoin(flag->pos == TRUE ? "+" : " ", tmp);
			free(tmp);
		}
		ft_putstr(data->argument);
	}
	else
		align_by_width(data->argument, len, flag, data->width, is_digit);
}