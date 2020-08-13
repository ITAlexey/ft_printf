/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 19:23:26 by dshala            #+#    #+#             */
/*   Updated: 2020/08/16 15:17:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define POS 0
#define NEG 1

int 	ft_nbrlen(int nbr)
{
	int	sign;
	int len;

	if (nbr == 0)
		return (1);
	len = 0;
	sign = nbr < 0 ? NEG : POS;
	nbr = ABC(nbr);
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (sign == NEG ? len + 1 : len);
}