//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"

static void 	initialize_structures(t_data_format *data, t_pattern *pattern)
{
	pattern->flag = " +-#0";
	pattern->type = "cspdiouxXf";
	data->nbr_of_symbols = 0;
	data->output = NULL;
}

int 			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_data_format	*data;
	t_pattern		*pattern;
	int 			symbols;

	if (!(data = (t_data_format*)malloc(sizeof(data))) ||
		!(pattern = (t_pattern*)malloc(sizeof(pattern))))
		exit(0);
	initialize_structures(data, pattern);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			parse_format(&format, data, pattern, ap);
			//print_percents(data->nbf_of_printed_percentages);
			ft_putstr(data->output);
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



