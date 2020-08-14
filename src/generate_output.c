//
// Created by alexey on 12.08.2020.
//

#include "ft_printf.h"

static char 	*retrieve_according_type(t_data_format *data, char *type, va_list ap)
{
	char	*string;

	if (ft_strequ(type, "d"))
		return (nbr_to_string((int) va_arg(ap, long long)));
	else if (ft_strequ(type, "c"))
		return (char_to_string(va_arg(ap, int)));
	else if (ft_strequ(type, "s"))
	{
		string = va_arg(ap, char*);
		return (ft_strsub(string, 0, ft_strlen(string)));
	}
	else
		return (NULL);
	/*else if (ft_strequ(type, "p"))
		retrieve_pointer(data, va_arg(ap, char*));
	else if (ft_strequ(type, "i"))
		return;
	else if (ft_strequ(type, "o"))
		return;
	else if (ft_strequ(type, "u"))
		return;
	else if (ft_strequ(type, "x"))
		return;
	else if (ft_strequ(type, "X"))
		return;
	else if (ft_strequ(type, "f"))
		return;*/
}

static void 	apply_specifiers_to_arg(t_data_format *data, char *arg)
{
	if (data->flag != NULL)
		process_flag(data, data->flag, arg);
	else
		data->output = ft_strsub(data->argument, 0, ft_strlen(data->argument));
}

static int		print_output(t_data_format *data)
{
	if (data->output == NULL)
	{
		ft_putstr(data->argument);
		return (ft_strlen(data->argument));
	}
	ft_putstr(data->output);
	return (ft_strlen(data->output));
}

int 	generate_output(t_data_format *data, va_list ap)
{
	if (data->type != NULL)
	{
		data->argument = retrieve_according_type(data, data->type, ap); // argument is recorded
		apply_specifiers_to_arg(data, data->argument);
	}
	return (print_percents(data->percentages / 2) + print_output(data));
}
