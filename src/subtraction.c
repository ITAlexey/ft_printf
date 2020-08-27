//
// Created by alexey on 27.08.2020.
//

#include "ft_printf.h"

static void 	swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

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

char 	*subtraction(char *a, char *b, unsigned len_a, unsigned len_b)
{
	unsigned	len;
	unsigned	index;
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
	result = ft_strnew(len);
	ISNULL(result);
	if (ft_strcmp(a, b) == -1)
		swap(&a, &b);
	while (len)
	{
		nbr = a[--len] - b[len] - flag;
		flag = nbr < 0 ? 1 : 0;
		result[index++] = nbr < 0 ? (nbr + 58) : (nbr + 48);
	}
	ft_strdel(&a);
	ft_strdel(&b);
	return (reverse_string(result));
}