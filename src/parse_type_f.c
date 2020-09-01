//
// Created by alexey on 24.08.2020.
//

#include "ft_printf.h"

static char		*is_inf_or_nan(long double ld)
{
	if (ld != ld)
		return (ft_strdup("nan"));
	else if (ld == -(1.0 / 0.0))
		return (ft_strdup("-inf"));
	else if (ld == (1.0 / 0.0))
		return (ft_strdup("inf"));
	return (ft_strdup("(null)"));
}


char 	*parse_type_f(t_data_format *data, t_fpoint decimal, short specifier, va_list ap)
{
	char	*binary_mantissa;
	int 	exp;

	decimal.ld = specifier == BIGL ? va_arg(ap, long double) :
			(double)va_arg(ap, double);
	if ((decimal.field.exp == SHRT_MAX && decimal.field.mantissa > LONG_MAX) || decimal.ld != decimal.ld)
		return (is_inf_or_nan(decimal.ld));
	exp = decimal.field.exp - OFFSET;
	binary_mantissa = ft_uitoa_base(decimal.field.mantissa, 2);
	return (represent_in_decimal_form(data, decimal, exp, binary_mantissa));
}
