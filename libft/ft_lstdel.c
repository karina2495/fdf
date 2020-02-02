/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:49:43 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 15:49:47 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*next;

	ptr = *alst;
	if (del != NULL && *alst != NULL && alst != NULL)
	{
		while (ptr != NULL)
		{
			next = ptr->next;
			del(ptr->content, ptr->content_size);
			free(ptr);
			ptr = next;
		}
		*alst = NULL;
	}
}
