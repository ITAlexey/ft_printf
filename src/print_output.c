//
// Created by alexey on 14.08.2020.
//

#include "ft_printf.h"

int		print_output(t_data_format *data)
{
	int 	result;

	result = MAX(data->width, ft_strlen(data->argument));
	ft_putstr(data->argument);
	free(data->flag);
	free(data->argument);
	return (result);
}