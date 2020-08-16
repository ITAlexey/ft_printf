//
// Created by alexey on 14.08.2020.
//

#include "ft_printf.h"

int		print_output(t_data_format *data)
{
	int 	result;

	result = ft_strlen(data->argument);
	ft_putstr(data->argument);
	free(data->flag);
	free(data->width);
	free(data->argument);
	return (result);
}