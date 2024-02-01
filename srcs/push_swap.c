/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:11:38 by beroy             #+#    #+#             */
/*   Updated: 2024/01/31 01:58:18 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_small_sort(t_pile **a_pile, t_pile **b_pile)
{
	int i;
	int pile_len;

	i = 0;
	pile_len = ft_lst_size(a_pile);
	while (i < pile_len - 2)
	{
		if ((*a_pile)->rank == i)
		{
			do_pb(a_pile, b_pile);
			i++;
		}
		else
			do_ra(a_pile);
	}
	if ((*a_pile)->rank > (*a_pile)->next->rank)
		do_ra(a_pile);
	while (i > 0)
	{
		do_pa(a_pile, b_pile);
		i--;
	}
}

void	ft_big_sort(t_pile **a_pile, t_pile **b_pile)
{
	int i;
	int j;
	int pile_len;

	i = MAX_BIN - 1;
	pile_len = ft_lst_size(a_pile);
	while (stack_is_sorted(a_pile, b_pile) == 0 && i >= 0)
	{
		j = 0;
		while (j < pile_len)
		{
			if ((*a_pile)->b_rank[i] == '0')
				do_pb(a_pile, b_pile);
			else
				do_ra(a_pile);
			j++;
		}
		while (*b_pile != NULL)
			do_pa(a_pile, b_pile);
		i--;
	}
}

void	push_swap(t_pile **a_pile, t_pile **b_pile)
{
	if (stack_is_sorted(a_pile, b_pile) == 1)
		return ;
	if (ft_lst_size(a_pile) <= 5)
		ft_small_sort(a_pile, b_pile);
	else
		ft_big_sort(a_pile, b_pile);
}
