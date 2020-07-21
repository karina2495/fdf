/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:49:06 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 15:49:10 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp->next != NULL && *alst != NULL && alst != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
