//
// Created by alexey on 26.08.2020.
//

#include "ft_printf.h"

static char 	*align_to_length(char **nbr, unsigned diff)
{
	char 		*tmp;
	char 		*str_of_zeros;

	str_of_zeros = ft_strnew(diff);
	ISNULL(str_of_zeros);
	ft_memset(str_of_zeros, '0', diff);
	tmp = ft_strjoin(str_of_zeros, *nbr);
	ft_strdel(nbr);
	ft_strdel(&str_of_zeros);
	return (tmp);
}

char 	*sum(char *a, char *b, unsigned len_a, unsigned len_b)
{
	int			len;
	int		 	index;
	char 		*result;
	short 		flag;
	char 		nbr;

	flag = 0;
	index = 0;
	len = MAX(len_a, len_b);
	if (len_a > len_b)
		b = align_to_length(&b, len_a - len_b);
	else if (len_a < len_b)
		a = align_to_length(&a, len_b - len_a);
	result = ft_strnew(len + 1);
	ISNULL(result);
	while (len)
	{
		nbr = a[--len] + b[len] - 96 + flag;
		flag = nbr >= 10 ? 1 : 0;
		result[index++] = flag ? (nbr % 10 + 48) : (nbr + 48);
	}
	if (flag)
		result[index] = '1';
	ft_strdel(&a);
	ft_strdel(&b);
	return (reverse_string(result));
}