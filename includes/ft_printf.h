//
// Created by alexey on 10.08.2020.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# define PERCENT 37
# define PLUS 43
# define MINUS 45
# define HASH 35
# define SPACE 32
# define ZERO 48
# define DOT 46
# define L 1
# define H 2
# define LL 3
# define HH 4
# define OFFSET 16383;
# define BIGL 5

typedef union	 		u_fpoint
{
	long double			ld;
	struct
	{
		unsigned long	mantissa : 64;
		unsigned		exp : 15;
		unsigned short	sign : 1;
	}					field;

}						t_fpoint;

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
	int 			precision;
	short 			is_digit;
	char			type;
	char			*arg;
	t_flag			*flag;
	t_fpoint		decimal;
	short 			specifier;
}					t_data_format;

int					ft_printf(char const *format, ...);
int					parse_format(char const **format, t_data_format *data, va_list ap);
t_flag 				*get_flags(char const **format, int (*fun)(char ch, t_flag* flag));
int					is_matched_to_flag(char ch, t_flag *flag);
int 				get_numeric_value(char const **format, int (*fun)(int ch), int symbol);
int					generate_output(t_data_format *data, va_list ap);
int 				print_signs(int times, int sign);
void				put_space_or_zero(char *arg, t_flag *flag, int times);
short 				is_difp(char ch);
short 				is_oXx(char ch);
char 				*sum(char *a, char *b, unsigned len_a, unsigned len_b);
char 				*add_prefix(char *str, char *pattern);
char 				*parse_type_d(short specifier, va_list ap);
char 				*parse_type_u(short specifier, va_list ap);
char 				*parse_type_o(short specifier, va_list ap);
char 				*parse_type_f(t_data_format *data, t_fpoint decimal, short specifier, va_list ap);

#endif
