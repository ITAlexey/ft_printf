//
// Created by alexey on 14.08.2020.
//

#include "ft_printf.h"

int 	free_fields(t_data_format *data, char *pattern)
{
	int	result;

	if (ft_strequ("arg", pattern))
	{
		ft_putstr(data->argument);
		result = ft_strlen(data->argument);
	}
	else
	{
		ft_putstr(data->output);
		result = ft_strlen(data->output);
		free(data->output);
		data->output = NULL;
	}
	free(data->flag);
	free(data->width);
	free(data->type);
	free(data->argument);
	return (result);
}

int		print_output(t_data_format *data)
{
	return (data->output == NULL ? free_fields(data, "arg") : free_fields(data, "output"));
}