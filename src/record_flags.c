//
// Created by alexey on 15.08.2020.
//

#include "ft_printf.h"

static int		is_matched_to_flag(char ch)
{
	return ((ch == SPACE || ch == PLUS || ch == MINUS || ch == ZERO ||
			ch == HASH) ? 1 : 0);
}

char 	*retrieve_str_by_pattern(const char **format, int(*fun)(char), int symbol)
{
	int 	len;
	char 	*end;

	end = (char*)(*format);
	len = 0;
	while (fun(**format) == 1)
	{
		(*format)++;
		len++;
	}
	return (len == 0 ? char_to_string(symbol) : ft_strsub(end, 0, len));
}
char 	*record_flags(char const **format, t_data_format *data)
{
	data->flag = retrieve_str_by_pattern(format, is_matched_to_flag);
	if (ft_strlen(data->flag) > 1)
}