//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"

void 		add_sign(t_data_format *data, char *sign)
{
	char 	*tmp;

	tmp = data->argument;
	data->argument = ft_strjoin(sign, tmp);
	free(tmp);
}

void		process_flag(t_data_format *data, t_flag *flag, char *arg)
{
	int		width;
	int 	len;

	len = ft_strlen(data->argument)
	width = ft_atoi(data->width);
	if (len >= width)
	{
		if ((flag->pos + flag->space) != 0 && *(data->argument) != '-')
			add_sign(data, flag->pos == TRUE ? "+" : " ");
	}
	else
	{
		char *tmp;

		tmp = data->argument;
		data->argument = ft_strnew(width);
		if (flag->neg == TRUE)
		{
			if (*(data->argument) != '-' && (flag->pos  + flag->space) != 0)
			{
				*(data->argument) = flag->pos == TRUE ? '+' : " ";
				ft_memset((char*)(ft_strcpy(data->argument + 1, tmp) + len), SPACE, width - len);
			}
			else
				ft_memset((char*)(ft_strcpy(data->argument, tmp) + len), SPACE, width - len);
		}
		else
		{
			if (*(data->argument) != '-' && (flag->pos + flag->space + flag->zero) != 0)
			{
				
			}
			else if (flag->zero == FALSE)
				ft_memset((char*)(ft_strcpy(data->argument + (width - len), tmp), SPACE, (width - len)));
			else
			{
				*(data->argument) = '-';
				ft_memset((char*)(ft_strcpy(data->argument + (width - len) + 1, tmp + 1) + 1, ZERO, (width - len - 1)));
			}
		}
		free(tmp);
	}
}