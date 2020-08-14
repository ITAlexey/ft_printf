//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"

static void 	initialize_structures(t_data_format *data)
{
	data->output = NULL;
}

int 			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_data_format	*data;
	int 			res;

	if (!(data = (t_data_format*)malloc(sizeof(t_data_format))))
		exit(0);
	initialize_structures(data);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			res += parse_format(&format, data, ap);
		else
		{
			ft_putchar(*format);
			format++;
			res++;
		}
	}
	//free(my_struct)
	va_end(ap);
	return (res);
}



