//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"
#define LEFT 0
#define RIGHT 1

static void		alignment_by_zeros(t_data_format *data, char *arg, int arg_len, int diff)
{
		*(data->output) = '-';
		ft_strncpy(data->output + 1 + diff, arg + 1, arg_len);
		ft_memset((char*)(data->output + 1), ZERO, diff);
}

static void 	align_output(t_data_format *data, char *arg, char *direction, char to_fill)
{
	int 	arg_len;
	int		diff;
	int 	offset;
	short 	side;

	arg_len = ft_strlen(arg);
	diff = arg_len - data->numeric_value_of_width;
	if (diff >= 0)
		data->output = ft_strsub(arg, 0, arg_len);
	else
	{
		diff = ABC(diff);
		data->output = ft_strnew(data->numeric_value_of_width);
		side = (ft_strequ("left", direction) == 1) ? LEFT : RIGHT;
		offset = side == LEFT ? 0 : diff;
		if (*arg != '-' || to_fill == SPACE)
		{
			ft_strncpy(data->output + offset, arg, arg_len);
			ft_memset((side == LEFT ? (char*)(data->output + arg_len) : (char*)(data->output)), to_fill, diff);
		}
		else
			alignment_by_zeros(data, arg, arg_len - 1, diff);
	}
}

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
		if ((flag->pos + flag->space) != 0)
			add_sign(data, flag->pos == TRUE ? "+" : " ");
	}
}