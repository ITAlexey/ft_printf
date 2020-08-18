/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:01:42 by dshala            #+#    #+#             */
/*   Updated: 2020/08/16 20:42:39 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 		*reverse_string(char *str)
{
	int 	len;
	char 	*tmp;
	int 	i;

	ISNULL(str);
	len = ft_strlen(str);
	i = 0;
	tmp = (char*)malloc(len + 1);
	ISNULL(tmp);
	while (len)
		tmp[i++] = str[--len];
	tmp[i] = 0;
	free(str);
	return (tmp);
}
