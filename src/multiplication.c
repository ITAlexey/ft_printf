//
// Created by alexey on 27.08.2020.
//

#include "ft_printf.h"

static void		swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void		do_mult(char *a, char *b, char **res, unsigned len_a, unsigned len_b)
{
	char		nbr;
	int			index;
	int			i;
	int			j;
	short		flag;

	i = len_b;
	while (i >= 0)
	{
		j = len_a;
		index = i + j + 1;
		flag = 0;
		while (j >= 0)
		{
			nbr = (a[j] - 48) * (b[i] - 48) + ((*res)[index] - 48) + flag;
			flag = nbr / 10;
			(*res)[index--] = (nbr % 10) + 48;
			j--;
		}
		(*res)[index] += flag;
		i--;
	}
	ft_strdel(&a);
	ft_strdel(&b);
}

char	*multiplication(char *a, char *b, unsigned len_a, unsigned len_b)
{
	char		*result;
	char		*tmp;
	unsigned	len;

	if (*a != ZERO && *b != ZERO)
	{
		len = len_a + len_b;
		result = ft_strnew(len + 1);
		ft_memset(result, '0', len);
		if (len_a < len_b)
			swap(&a, &b);
		do_mult(a, b, &result, MAX(len_a, len_b) - 1, MIN(len_a, len_b) - 1);
		if (*result == '0')
		{
			tmp = ft_strdup(result + 1);
			free(result);
			return (tmp);
		}
		return (result);
	}
	ft_strdel(&a);
	ft_strdel(&b);
	return (char_to_string(ZERO));
}
