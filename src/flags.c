//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"
#define LEFT 0
#define RIGHT 1
#define SPACE 32
#define ZERO 48

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

void		process_flag(t_data_format *data, char *flag, char *arg)
{
	if (*flag == '-')
		align_output(data, arg, "left", SPACE);
	else if (*flag == ' ')
		align_output(data, arg, "right", SPACE);
	else if (*flag == '0')
		return align_output(data, arg, "right", ZERO);
	else if (*flag == '+')
		return;
	else if (*flag == '#')
		return;
}