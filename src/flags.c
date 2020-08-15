//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"
#define LEFT 0
#define RIGHT 1

static void 	align_output(t_data_format *data, char *arg, char *direction)
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
		ft_strncpy(data->output + offset, arg, arg_len);
		ft_memset((side == LEFT ? (char*)(data->output + arg_len) : (char*)(data->output)), ' ', diff);
	}
}

void		process_flag(t_data_format *data, char *flag, char *arg)
{
	if (*flag == '-')
		align_output(data, arg, "left");
	else if (*flag == ' ')
		align_output(data, arg, "right");
}