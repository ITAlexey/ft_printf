//
// Created by alexey on 10.08.2020.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# define PERCENT 37
# define PLUS 43
# define MINUS 45
# define HASH 35
# define SPACE 32
# define ZERO 48

typedef struct		s_data_format
{
	int				percentages;
	char			*flag;
	char			*width;
	int				numeric_value_of_width;
	char			*type;
	char			*argument;
	char			*output;

}					t_data_format;

int					parse_format(char const **format, t_data_format *data, va_list ap);
int					generate_output(t_data_format *data, va_list ap);
void				process_flag(t_data_format *data, char *flag, char *arg);
int					ft_printf(char const *format, ...);
int 				print_percents(int times);
int 				print_output(t_data_format *data);
char 				*record_flags(char const **format, t_data_format *format);
char 				*retrieve_str_by_pattern(char const **format, int(*fun)(char), int symbol);

#endif
