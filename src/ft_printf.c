//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"

static void 	initialize_structures(t_data_format *data)
{
	//" +-#0"
	//"cspdiouxXf"
	data->nbr_of_symbols = 0;
	data->output = NULL;
}

int 			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_data_format	*data;
	int 			symbols;

	if (!(data = (t_data_format*)malloc(sizeof(t_data_format))))
		exit(0);
	initialize_structures(data);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			parse_format(&format, data, ap);
			//print_percents(data->nbf_of_printed_percentages);
			ft_putstr(data->argument);
			/*
			 * FORMAT: %[nbr of %][flags][width][precisely][size][type]
			 * PERCENTAGES: check number of them.
			 * FLAGS: -; +; space; #; 0.
			 * WIDTH: decimal number.
			 * PRECISELY: . then decimal number.
			 * SIZE: hh,  h, l, ll (L, l).
			 * TYPE: c, s, p, d, i, o, u, x, X, (f).
			 */
		}
		else {
			ft_putchar(*format);
			format++;
			data->nbr_of_symbols += 1;
		}
	}
	symbols = data->nbr_of_symbols;
	//free(my_struct)
	va_end(ap);
	return (symbols);
}



