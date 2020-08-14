//
// Created by alexey on 14.08.2020.
//

#include "ft_printf.h"

int 	free_struct(t_data_format *data)
{
	int	result;

	result = ft_strlen(data->argument);
	result = ft_strlen(data->output);
	free(data->flag);
	free(data->width);
	free(data->type);
	free(data->output);
	data->output = NULL;
	free(data->argument);
	data->argument = NULL;
}

int		print_output(t_data_format *data)
{
	if (data->output == NULL)
	{
		ft_putstr(data->argument);
		return (ft_strlen(data->argument));
	}
	ft_putstr(data->output);
	return (ft_strlen(data->output));
}