//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"

static char	 	*record_output(char *output, char *src, char *size)
{
	int 	nbr;

	nbr = ft_atoi(size);
	output = ft_strnew(nbr);
	return (ft_strncpy(output, src, nbr));
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
		ft_memset((char*)(tmp + arg_len), ' ', ABC(diff));
	}
}

void		process_flags(t_data_format *data, char *flag, char *arg)
{
	if (*flag == '-')
		left_alignment(data, arg);
}