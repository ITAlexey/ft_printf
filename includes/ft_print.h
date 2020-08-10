//
// Created by alexey on 10.08.2020.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "libft.h"

typedef struct		s_data_format
{
	int 			nbr_of_percent_signs;
	int 			nbr_of_symbols;
	//int 			pointer_offset;
	int 			nbr_of_printed_percentages;
	//char 			*type_pattern; // [cspdiouxXf]
	//char 			*width;
	char 			*flag_type;
	char 			*output;

}					t_data_format;

typedef struct		s_pattern
{
	char 			*flag_pattern; // [ +-#0]
}					t_pattern;

void 				parse_format(char const *format, t_data_format *data, t_pattern *pattern);
void 				process_flags(t_data_format *data, char *flag, char *arg);

#endif
