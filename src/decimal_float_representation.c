//
// Created by alexey on 29.08.2020.
//

#include "ft_printf.h"

static char 	*combine_nbr(t_data_format *data, char *int_part, char *fract_part, unsigned sign)
{
	char	*result;

	round_nbr(&int_part, &fract_part, data->precision);
	int_part = sign ? add_prefix(int_part, "-") : int_part;
	if (data->flag->hash || data->precision)
		int_part = add_suffix(int_part, ".");
	result = ft_strjoin(int_part, fract_part);
	ft_strdel(&int_part);
	ft_strdel(&fract_part);
	return (result);
}

static void 	skip_zero_bits(char **b_fract, int *exp)
{
	while (**b_fract == '0')
	{
		(*b_fract)++;
		(*exp)--;
	}
	(*b_fract)++;
}

static int get_len(char *b_mant, int exp)
{
	int		len;
	int 	cpy;

	cpy = -exp;
	len = 0;
	while (*b_mant != '\0')
	{
		if (*b_mant == '1')
			len = cpy;
		cpy++;
		b_mant++;
	}
	if (len == -exp || len == 0)
		return (-exp);
	return (len + 1);
}

char 	*powered_by_ten(char *nbr, int max_len, int exp)
{
	int 	i;
	int 	j;
	char 	*tmp;
	int 	nbr_len;

	i = 0;
	j = 0;
	tmp = ft_strnew(max_len);
	ISNULL(tmp);
	ft_memset(tmp, ZERO, max_len);
	nbr_len = (int)ft_strlen(nbr);
	while (nbr[j] != '\0')
	{
		while (nbr_len < -exp)
		{
			i++;
			nbr_len++;
		}
		tmp[i++] = nbr[j++];
	}
	ft_strdel(&nbr);
	return (tmp);
}

char 	*initialize_nbr(int len, int exp)
{
	int 	i;
	char 	*init;

	i = 1;
	init = ft_strdup("5");
	ISNULL(init);
	while (i++ < -exp)
		init = multiplication(init, ft_strdup("5"), ft_strlen(init), 1);
	return (powered_by_ten(init, len, exp));
}

char 	*convert_fraction_to_decimal(char *b_fract, int exp)
{
	char 	*decimal_form;
	char 	*powered_nbr;
	int 	len;

	if (*b_fract != '\0')
		skip_zero_bits(&b_fract, &exp);
	len = get_len(b_fract, exp);
	decimal_form = initialize_nbr(len, exp--);
	while (*b_fract != '\0')
	{
		if (*b_fract == '1')
		{
			powered_nbr = do_power(ABC(exp), 27, powered_value_of_base_five);
			powered_nbr = powered_by_ten(powered_nbr, len, exp);
			decimal_form = sum(decimal_form, powered_nbr, ft_strlen(decimal_form), len);
		}
		exp--;
		b_fract++;
	}
	return(decimal_form);
}

static char 	*convert_int_to_decimal(char **b_mant, int *exp)
{
	char 	*decimal_form;
	char 	*powered_nbr;

	decimal_form = char_to_string(ZERO);
	while (**b_mant != '\0' && *exp >= 0)
	{
		if (**b_mant == '1')
		{
			powered_nbr = do_power(*exp, 64, powered_value_of_base_two);
			decimal_form = sum(decimal_form, powered_nbr, ft_strlen(decimal_form), ft_strlen(powered_nbr));
		}
		(*b_mant)++;
		(*exp)--;
	}
	return (decimal_form);
}

char 	*represent_in_decimal_form(t_data_format *data, t_fpoint decimal, int exp, char *b_mant)
{
	char 	*int_part;
	char 	*fraction_part;
	char 	*cpy;

	cpy = b_mant;
	int_part = exp < 0 ? char_to_string(ZERO) : convert_int_to_decimal(&b_mant, &exp);
	fraction_part = convert_fraction_to_decimal(b_mant, exp);
	ft_strdel(&cpy);
	return (combine_nbr(data, int_part, fraction_part, decimal.field.sign));
}
