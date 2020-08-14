//
// Created by alexey on 10.08.2020.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "libft.h"
#include <stdarg.h>

typedef struct		s_data_format
{
	int				nbr_of_symbols;
	int				nbr_of_percent_signs;
	int				nbr_of_printed_percentages;
	char			*width;
	int				numeric_value_of_width;
	char			*flag;
	char			*type;
	char			*argument;
	char			*output;

}					t_data_format;

typedef struct		s_pattern
{
	char			*flag; // [ +-#0]
	char			*type; // [cspdiouxXf]
}					t_pattern;

void				parse_format(char const **format, t_data_format *data, t_pattern *pattern, va_list ap);
void				generate_output(t_data_format *data, va_list ap);
void				process_flag(t_data_format *data, char *flag, char *arg);
int					ft_printf(char const *format, ...);

#endif
