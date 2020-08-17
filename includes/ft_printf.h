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
# define TRUE 1
# define FALSE 0

typedef struct		s_flag
{
	short 			neg;
	short 			pos;
	short 			zero;
	short 			hash;
	short 			space;
}					t_flag;

typedef struct		s_data_format
{
	int				percentages;
	int 			width;
	short 			is_digit;
	char			type;
	char			*argument;
	t_flag			*flag;
}					t_data_format;

int					ft_printf(char const *format, ...);
int					parse_format(char const **format, t_data_format *data, va_list ap);
t_flag 				*get_flags(char const **format, int(*fun)(char ch, t_flag* flag));
int					is_matched_to_flag(char ch, t_flag *flag);
int 				get_width(char const **format, int (*fun)(int ch), int symbol);
int					generate_output(t_data_format *data, va_list ap);
void				process_flag(t_data_format *data, t_flag *flag, short is_digit);
int 				print_signs(int times, int sign);

#endif
