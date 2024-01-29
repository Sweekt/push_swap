/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:33:40 by beroy             #+#    #+#             */
/*   Updated: 2024/01/29 19:50:33 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(t_pile **a_pile, t_pile **b_pile)
{
	t_pile	*tmp;

	if (*a_pile == NULL)
		return ;
	tmp = *a_pile;
	*a_pile = tmp->next;
	tmp->next = *b_pile;
	*b_pile = tmp;
}

void	do_pa(t_pile **a_pile, t_pile **b_pile)
{
	ft_push(a_pile, b_pile);
	ft_printf("pa\n");
}

void	do_pb(t_pile **a_pile, t_pile **b_pile)
{
	ft_push(b_pile, a_pile);
	ft_printf("pb\n");
}
