//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"

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
	{
		int diff = data->width - len;
		if (flag->neg == TRUE)
		{
			if (data->is_digit == TRUE && *(data->argument) != '-' && (flag->pos + flag->space) != 0)
				ft_putchar(flag->pos == TRUE ? PLUS : SPACE);
			ft_putstr(data->argument);
			print_signs(diff, SPACE);
		}
		if (data->is_digit == TRUE)
		{
			if (*(data->argument) != '-' && (flag->pos + flag->space + flag->zero) != 0)
			{
				if (flag->pos + flag->space != 0)
				{
					ft_putchar(flag->pos == TRUE ? PLUS : SPACE);
					diff--;
				}
				print_signs(diff, flag->zero == TRUE ? ZERO : SPACE);
				ft_putstr(data->argument);
			}
			if (flag->zero == FALSE)
			{
				ft_putchar(MINUS);
				print_signs(diff, ZERO);
				ft_putstr(data->argument + 1);
			}
		}
		else
		{
			print_signs(diff, SPACE);
			ft_putstr(data->argument);
		}
	}
}