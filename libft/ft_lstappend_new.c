/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:49:17 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 15:49:21 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstappend_new(t_list **alst, t_list *new)
{
	t_list		*alstcp;

	alstcp = *alst;
	if (*alst == NULL)
	{
		*alst = ft_lstnew(new->content, new->content_size);
		return ;
	}
	while (alstcp->next)
		alstcp = alstcp->next;
	alstcp->next = new;
}
