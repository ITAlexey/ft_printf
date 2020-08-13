//
// Created by alexey on 12.08.2020.
//

#include "ft_printf.h"

char 	*character_to_string(char ch)
{
	char 	*string;

	string = (char*)malloc(2);
	ISNULL(string);
	string[0] = ch;
	string[1] = '\0';
	return string;
}

static void 	retrieve_integer(t_data_format *data, int nbr)
{

}

static void 	retrieve_string(t_data_format *data, char *str)
{
	data->argument = ft_strsub(str, 0, ft_strlen(str)); // allocate memory
}

static void 	retrieve_char(t_data_format *data, char ch)
{
	character_to_string(ch);
}

static void 	retrieve_arg_by_the_type(t_data_format *data, char *type, va_list ap)
{
	if (ft_strequ(type, "d"))
		 retrieve_integer(data, va_arg(ap, int)); // beta returned value
	else if (ft_strequ(type, "c"))
		retrieve_char(data, va_arg(ap, char));
	else if (ft_strequ(type, "s"))
		retrieve_string(data, va_arg(ap, char*));
	/*else if (ft_strequ(type, "p"))
		retrieve_pointer(data, va_arg(ap, char*));
	else if (ft_strequ(type, "i"))
		return;
	else if (ft_strequ(type, "o"))
		return;
	else if (ft_strequ(type, "u"))
		return;
	else if (ft_strequ(type, "x"))
		return;
	else if (ft_strequ(type, "X"))
		return;
	else if (ft_strequ(type, "f"))
		return;*/
}

void 	generate_output(t_data_format *data, va_list ap)
{
	if (data->type != NULL)
	{
		// types: char. int, char *
		retrieve_arg_by_the_type(data, data->type, va_list ap);
		//process_flags();
	}
}