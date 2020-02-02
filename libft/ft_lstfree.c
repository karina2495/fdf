/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:50:09 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 15:50:13 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *alst)
{
	t_list	*tmp;

	if (alst == NULL)
		return ;
	while (alst)
	{
		tmp = alst->next;
		free(alst->content);
		free(alst);
		alst = tmp;
	}
	free(alst);
	alst = NULL;
}
