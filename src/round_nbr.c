//
// Created by alexey on 30.08.2020.
//

#include "ft_printf.h"

static int 	case_of_nine(char **int_part, char **fract_part, int prn)
{
	while ((*fract_part)[prn] == '9')
		(*fract_part)[prn--] = '0';
	if (prn >= 0)
		(*fract_part)[prn]++;
	else
		*int_part = sum(*int_part, ft_strdup("1"), ft_strlen(*int_part), 1);
	return (prn);
}

void 	round_nbr(char **int_part, char **fract_part, int prn)
{
	if (prn == 0 && *fract_part[prn] > '5')
		*int_part = sum(*int_part, ft_strdup("1"), ft_strlen(*int_part), 1);
	if (prn <= (int)ft_strlen(*fract_part))
	{
		case_of_nine(int_part, fract_part, prn - 1);
		(*fract_part)[prn] = 0;
	}
}