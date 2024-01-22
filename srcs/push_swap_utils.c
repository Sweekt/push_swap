/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:37:25 by beroy             #+#    #+#             */
/*   Updated: 2024/01/18 00:49:24 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*ft_lst_last(t_pile *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lst_add_back(t_pile **lst, t_pile *new)
{
	t_pile	*last;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last = ft_lst_last(*lst);
			last->next = new;
		}
	}
}

t_pile	*ft_lst_new(int content)
{
	t_pile	*s_new;

	s_new = malloc(sizeof(t_list));
	if (s_new == NULL)
		return (s_new);
	s_new->content = content;
	s_new->next = NULL;
	return (s_new);
}
