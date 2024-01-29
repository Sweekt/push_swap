/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:41:40 by beroy             #+#    #+#             */
/*   Updated: 2024/01/29 19:19:25 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_pile **pile)
{
	t_pile *tmp;

	if (ft_lst_size(pile) < 2)
		return;
	tmp = (*pile)->next;
	(*pile)->next = tmp->next;
	tmp->next = *pile;
	*pile = tmp;
}

void	do_sa(t_pile **a_pile)
{
	ft_swap(a_pile);
	ft_printf("sa\n");
}

void	do_sb(t_pile **b_pile)
{
	ft_swap(b_pile);
	ft_printf("sb\n");
}

void	do_ss(t_pile **a_pile, t_pile **b_pile)
{
	ft_swap(a_pile);
	ft_swap(b_pile);
	ft_printf("ss\n");
}
