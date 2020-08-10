//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"

static char	 	*record_output(char *output, char *src, size_t size)
{
	data-output = ft_strnew(data->width);
	return (ft_strcnpy(data->output, arg, arg_len));
}

static void 	left_alignment(t_data_format *data, char *arg)
{
	int 	arg_len;
	char 	*tmp;
	int		diff;

	arg_len = ft_strlen(arg);
	diff = arg_len - data->width;
	if (diff >= 0)
		record_output(data->output, arg, arg_len);
	else
	{
		record_output(data->output, arg, data->width);
		tmp = data->output;
		ft_memset((char*)(tmp + arg_len), ' ', ABS(diff));
	}
}

void		process_flags(t_data_format *data, char *flag, char *arg)
{
	if (*flag == '-')
		left_alignment(data, arg);
}