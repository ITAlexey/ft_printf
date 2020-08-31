//
// Created by alexey on 24.08.2020.
//

#include "ft_printf.h"

static char		*is_inf_or_nan(t_data_format *data)
{
	if (data->decimal.ld != data->decimal.ld)
		return (ft_strdup("nan"));
	else if (data->decimal.field.sign == 1)
		return (ft_strdup("-inf"));
	else if (data->decimal.field.sign == 0)
		return (ft_strdup("inf"));
	return (ft_strdup("(null)"));
}


char 	*parse_type_f(t_data_format *data, t_fpoint decimal, short specifier, va_list ap)
{
	char	*binary_mantissa;
	int 	exp;
	char 	*tmp;

	decimal.ld = specifier == BIGL ? va_arg(ap, long double) :
			(double)va_arg(ap, double);
	if ((decimal.field.exp == SHRT_MAX && decimal.field.mantissa > LONG_MAX) || decimal.ld != decimal.ld)
		return (is_inf_or_nan(data));
	exp = decimal.field.exp - OFFSET;
	binary_mantissa = ft_uitoa_base(decimal.field.mantissa, 2);
	return (represent_in_decimal_form(data, decimal, exp, binary_mantissa));
}
