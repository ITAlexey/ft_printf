//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"

static void 	left_alignment(t_data_format *data, char *arg)
{
	int 	arg_len;
	char 	*tmp;
	int		diff;

	arg_len = ft_strlen(arg);
	diff = arg_len - data->numeric_value_of_width;
	if (diff >= 0)
		data->output = ft_strsub(arg, 0, arg_len);
	else
	{
		data->output = ft_strnew(data->numeric_value_of_width);
		ft_strncpy(data->output, arg, arg_len);
		tmp = data->output;
		ft_memset((char*)(tmp + arg_len), ' ', ABC(diff));
	}
}

void		process_flag(t_data_format *data, char *flag, char *arg)
{
	if (*flag == '-')
		left_alignment(data, arg);
}