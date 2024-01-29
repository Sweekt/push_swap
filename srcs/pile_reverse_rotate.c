/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:55:50 by beroy             #+#    #+#             */
/*   Updated: 2024/01/29 20:12:42 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse_rotate(t_pile **pile)
{
	t_pile	*last;
	t_pile	*tmp;

	last = ft_lst_last(*pile);
	tmp = *pile;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *pile;
	*pile = last;
}

void	do_rra(t_pile **a_pile)
{
	ft_reverse_rotate(a_pile);
	ft_printf("rra\n");
}

void	do_rrb(t_pile **b_pile)
{
	ft_reverse_rotate(b_pile);
	ft_printf("rrb\n");
}

void	do_rrr(t_pile **a_pile, t_pile **b_pile)
{
	ft_reverse_rotate(a_pile);
	ft_reverse_rotate(b_pile);
	ft_printf("rrr\n");
}
