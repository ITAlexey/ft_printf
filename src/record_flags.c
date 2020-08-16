//
// Created by alexey on 15.08.2020.
//

#include "ft_printf.h"

static int		record_flag(short *value)
{
	*value = TRUE;
	return (TRUE);
}

int		is_matched_to_flag(char ch, t_flag *flag)
{
	if (ch == PLUS)
		return (record_flag(&(flag->pos)));
	else if (ch == MINUS)
		return (record_flag(&(flag->neg)));
	else if (ch == SPACE)
		return (record_flag(&(flag->space)));
	else if (ch == ZERO)
		return (record_flag(&(flag->zero)));
	else if (ch == HASH)
		return (record_flag(&(flag->hash)));
	else
		return (FALSE);
}

static void 	init(t_flag *tmp)
{
	tmp->pos = FALSE;
	tmp->neg = FALSE;
	tmp->hash = FALSE;
	tmp->zero = FALSE;
	tmp->space = FALSE;
}

t_flag		*get_flags(char const **format, int(*fun)(char, t_flag*))
{
	t_flag	*tmp;

	tmp = (t_flag*)malloc(sizeof(t_flag));
	if (tmp == NULL)
		exit(1);
	init(tmp);
	while (fun(**format, tmp))
		(*format)++;
	return (tmp);
}