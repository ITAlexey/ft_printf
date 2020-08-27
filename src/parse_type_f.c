//
// Created by alexey on 24.08.2020.
//

#include "ft_printf.h"

/*static char		*is_inf_on_nan(t_data_format *data)
{
	if (data->decimal.lb != data->decimal.lb)
		return (ft_strdup("nan"));
	else if (data->decimal.sign == 1)
		return (ft_strdup("-inf"));
	else if (data->decimal.sign == 0)
		return (ft_strdup("inf"));
}*/

char 	*parse_type_f(t_data_format *data, t_fpoint decimal, short specifier, va_list ap)
{
	char	*binary_mantissa;
	short 	exp;

	decimal.ld = specifier == BIGL ? va_arg(ap, long double) :
			(double)va_arg(ap, double);
	if ((decimal.feilds.exp == SHRT_MAX && decimal.feilds.mantissa > LONG_MAX) || decimal.lb != decimal.lb)
		return (is_inf_or_nan(data));
	data->specifier = data->specifier < 0 ? 6 : data->specifier;
	exp = decimal.field.exp - OFFSET;
	binary_mantissa = ft_uitoa_base(decimal.field.mantissa, 2);
	//data->argument = nbr_to_string((long long)decimal.ld);

}