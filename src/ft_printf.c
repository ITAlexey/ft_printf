//
// Created by alexey on 10.08.2020.
//

#include "ft_printf.h"

int 		print_signs(int times, int sign)
{
	int	tmp;

	tmp = times;
	while (tmp)
	{
		ft_putchar(sign);
		tmp--;
	}
	return (times);
}

int 			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_data_format	*data;
	int 			res;

	res = 0;
	if (!(data = (t_data_format*)malloc(sizeof(t_data_format))))
		exit(0);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == PERCENT)
			res += parse_format(&format, data, ap);
		else
		{
			ft_putchar(*format);
			format++;
			res++;
		}
	}
	free(data);
	va_end(ap);
	return (res);
}



