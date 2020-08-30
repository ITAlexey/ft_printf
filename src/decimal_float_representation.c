//
// Created by alexey on 29.08.2020.
//

#include "ft_printf.h"

static char 	*convert_int_to_decimal(char *b_int, int exp)
{
	char 	*decimal_form;
	char 	*powered_nbr;

	decimal_form = char_to_string(ZERO);
	while (*b_int != '\0' && exp >= 0)
	{
		if (*b_int == '1')
		{
			powered_nbr = do_power(exp, 64, powered_value_of_base_two);
			decimal_form = sum(decimal_form, powered_nbr, ft_strlen(decimal_form), ft_strlen(powered_nbr));
		}
		b_int++;
		exp--;
	}
	return (decimal_form);
}

char 	*convert_fraction_to_decimal(char *b_fract)
{
	char 	*decimal_form;
	char 	*powered_nbr;
	int 	min_pow;
	int 	max_pow;

	min_pow = 1;
	max_pow = (int)ft_strlen(b_fract) - 1;
	decimal_form = char_to_string(ZERO);
	while (*b_fract != '\0')
	{
		if (*b_fract == '1')
		{
			powered_nbr = do_power(min_pow, 27, powered_value_of_base_five);
			powered_nbr = powered_by_ten(powered_nbr, max_pow);
			decimal_form = sum(decimal_form, powered_nbr, ft_strlen(decimal_form), ft_strlen(powered_nbr));
		}
		min_pow++;
		max_pow--;
		b_fract++;
	}
	return(decimal_form);
}

static char 	*combine_nbr(t_data_format *data, char *int_part, char *fract_part, unsigned sign)
{
	char	*result;

	//round_nbr(&int_part, &fract_part, data->precision);
	int_part = sign ? add_prefix(int_part, "-") : int_part;
	if (data->flag->hash || data->precision)
		int_part = add_suffix(int_part, ".");
	result = ft_strjoin(int_part, fract_part);
	ft_strdel(&int_part);
	ft_strdel(&fract_part);
	return (result);
}

char 	*represent_in_decimal_form(t_data_format *data, t_fpoint decimal, int exp, char *b_mant)
{
	char 	*int_part;
	char 	*tmp;
	char 	*fraction_part;

	if (exp < 0)
	{
		exp = ABC(exp);
		tmp = ft_strnew(exp);
		ft_memset(tmp, ZERO, exp);
		b_mant = add_prefix(b_mant, tmp);
		ft_strdel(&tmp);
		int_part = char_to_string(ZERO);
		fraction_part = convert_fraction_to_decimal(b_mant);
	}
	else
	{
		tmp = ft_strnew(exp + 1);
		int_part = convert_int_to_decimal(ft_strncat(tmp, b_mant, exp + 1), exp);
		ft_strdel(&tmp);
		tmp = ft_strdup(b_mant + exp + 1);
		fraction_part = convert_fraction_to_decimal(tmp);
		ft_strdel(&tmp);
	}
	return (combine_nbr(data, int_part, fraction_part, decimal.field.sign));
}
