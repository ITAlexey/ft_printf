/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:59:03 by dshala            #+#    #+#             */
/*   Updated: 2019/10/03 16:16:53 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclr(t_gnl **head, int const fd)
{
	t_gnl*remove;
	t_gnl*current;

	current = *head;
	if (current->fd_gnl == fd)
	{
		if (current->next != NULL)
			*head = current->next;
		free(current);
		current = NULL;
		return ;
	}
	while (current->next->fd_gnl != fd)
		current = current->next;
	remove = current->next;
	current->next = remove->next;
	free(remove);
	remove = NULL;
}
