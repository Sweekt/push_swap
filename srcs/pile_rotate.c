/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:19:46 by beroy             #+#    #+#             */
/*   Updated: 2024/01/29 19:30:56 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*last;

	tmp = *pile;
	*pile = (*pile)->next;
	last = ft_lst_last(*pile);
	last->next = tmp;
	tmp->next = NULL;
}

void	do_ra(t_pile **a_pile)
{
	ft_rotate(a_pile);
	ft_printf("ra\n");
}

void	do_rb(t_pile **b_pile)
{
	ft_rotate(b_pile);
	ft_printf("rb\n");
}

void	do_rr(t_pile **a_pile, t_pile **b_pile)
{
	ft_rotate(a_pile);
	ft_rotate(b_pile);
	ft_printf("rr\n");
}
