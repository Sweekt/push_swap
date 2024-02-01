/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:37:25 by beroy             #+#    #+#             */
/*   Updated: 2024/02/01 15:47:12 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lst_display(t_pile **lst)
{
	t_pile	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		ft_printf("Content : %d || Rank : %d || B_rank : %s\n", tmp->content, tmp->rank, tmp->b_rank);
		tmp = tmp->next;
	}
}

void	ft_lst_clear(t_pile **lst)
{
	t_pile	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (*lst)
	{
		tmp = tmp->next;
		if ((*lst)->b_rank != NULL)
			free((*lst)->b_rank);
		free(*lst);
		*lst = tmp;
	}
}

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

	s_new = malloc(sizeof(t_pile));
	if (s_new == NULL)
		return (s_new);
	s_new->content = content;
	s_new->rank = -1;
	s_new->b_rank = NULL;
	s_new->next = NULL;
	return (s_new);
}
