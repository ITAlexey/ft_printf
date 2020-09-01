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
	if (!**fract_part)
	{
		while (prn)
		{
			*fract_part = add_suffix(*fract_part, "0");
			prn--;
		}
	}
	else if (prn == 0)
	{
		*int_part = *fract_part[prn] > '5' ? sum(*int_part, ft_strdup("1"), ft_strlen(*int_part), 1) : *int_part;
		(*fract_part)[prn] = 0;
	}
	else if (prn <= (int)ft_strlen(*fract_part))
	{
		case_of_nine(int_part, fract_part, prn);
		(*fract_part)[prn] = 0;
	}
}
