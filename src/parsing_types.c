//
// Created by alexey on 21.08.2020.
//

#include "ft_printf.h"

char 			*parse_type_u(short specifier, va_list ap)
{
	if (specifier == L)
		return (ft_uitoa_base((unsigned long)va_arg(ap, unsigned long), 10));
	else if (specifier == H)
		return (ft_uitoa_base((unsigned short)va_arg(ap, unsigned int), 10));
	else if (specifier == LL)
		return (nbr_to_string((long long)va_arg(ap, long long)));
	else if (specifier = HH)
		return (ft_uitoa_base((unsigned char)va_arg(ap, int), 10));
	return (ft_uitoa_base((va_arg(ap, unsigned), 10));
}

char 			*parse_type_d(short specifier, va_list ap)
{
	if (specifier == L)
		return (nbr_to_string((long)va_arg(ap, long)));
	else if (specifier == H)
		return (nbr_to_string((short)va_arg(ap, int)));
	else if (specifier == LL)
		return (nbr_to_string((long long)va_arg(ap, long long)));
	else if (specifier = HH)
		return (nbr_to_string((char)va_arg(ap, int)));
	return (nbr_to_string((long long)va_arg(ap, int)));
}

char 			*parse_type_o(short specifier, va_list ap)
{
	if (specifier == L)
		return (ft_uitoa_base((long)va_arg(ap, long), 8));
	else if (specifier == H)
		return (ft_uitoa_base((unsigned short)va_arg(ap, unsigned)), 8);
	else if (specifier == LL)
		return (ft_uitoa_base((long long)va_arg(ap, long long), 8));
	else if (specifier = HH)
		return (ft_uitoa_base((unsigned char)va_arg(ap, int)), 8);
	return (ft_uitoa_base(va_arg(ap, unsigned)), 8);
}