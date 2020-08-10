//
// Created by alexey on 10.08.2020.
//

#include <stdarg.h>
#include "ft_printf.h"

static void 	initialize_structures(t_data_format *data, t_pattern *pattern)
{
	if (!(data = (t_data_format*)malloc(sizeof(data))) ||
		!(pattern = (t_pattern*)malloc(sizeof(pattern))))
		exit();
	pattern->flag_pattern = " +-#0";
	data->nbr_of_symbols = 0;
}

int 			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_data_format	*data;
	t_pattern		*pattern;
	int 			nbr;

	initialize_structures(data, pattern);
	va_start(ap, format);
	symbols_counter = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			parse_format(format);
			nbr = va_arg(ap, int);
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
		}
		data->nbr_of_symbols += 1;
	}
	//free(my_struct)
	va_end(ap);
	return (symbols_counter);
}


