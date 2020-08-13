/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_to_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 19:23:26 by dshala            #+#    #+#             */
/*   Updated: 2020/08/16 15:17:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define NEG 1
#define POS 0

static char*	nbrcpy(char *dest, int nbr, int len)
{
	int sign;

	sign = nbr < 0 ? NEG : POS;
	nbr = ABC(nbr);
	while (nbr != 0)
	{
		dest[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign == NEG)
		dest[len] = '-';
	return (dest);
}

char 			*integer_to_string(int nbr)
{
	int 	len;
	char 	*str;

	len = ft_nbrlen(nbr);
	str = (char*)malloc(len + 1);
	ISNULL(str);
	str[len] = '\0';
	return (nbrcpy(str, nbr, len - 1));
}