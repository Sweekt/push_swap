/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:11:38 by beroy             #+#    #+#             */
/*   Updated: 2024/02/12 12:50:23 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_small_small_sort(t_pile **a_pile, t_pile **b_pile, int i)
{
	if ((*a_pile)->rank == 0 + i)
	{
		do_pb(a_pile, b_pile);
		do_ra(a_pile);
		do_pa(a_pile, b_pile);
	}
	else if ((*a_pile)->rank == 1 + i)
	{
		if ((*a_pile)->next->rank == 2 + i)
			do_rra(a_pile);
		else
			do_sa(a_pile);
	}
	else
	{
		if ((*a_pile)->next->rank == 1 + i)
		{
			do_sa(a_pile);
			do_rra(a_pile);
		}
		else
			do_ra(a_pile);
	}
}

void	ft_small_sort(t_pile **a_pile, t_pile **b_pile)
{
	int	i;
	int	pile_len;

	i = 0;
	pile_len = ft_lst_size(a_pile);
	while (i < pile_len - 3)
	{
		if ((*a_pile)->rank == 0 || (*a_pile)->rank == 1)
		{
			do_pb(a_pile, b_pile);
			i++;
		}
		else
			do_ra(a_pile);
	}
	if (i >= 2 && ((*b_pile)->rank < (*b_pile)->next->rank))
		do_rb(b_pile);
	if (small_stacked_sorted(a_pile) == 0)
		ft_small_small_sort(a_pile, b_pile, i);
	while (i > 0)
	{
		do_pa(a_pile, b_pile);
		i--;
	}
}

void	ft_big_sort(t_pile **a_pile, t_pile **b_pile)
{
	int	i;
	int	j;
	int	pile_size;

	pile_size = ft_lst_size(a_pile);
	i = MAX_BIN - 1;
	while (stack_is_sorted(a_pile, b_pile) == 0 && i >= 0)
	{
		j = 0;
		while (j < pile_size)
		{
			if ((*a_pile)->b_rank[i] == '0')
			{
				if (j != pile_size - 1)
					do_pb(a_pile, b_pile);
			}
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
	int	size;

	size = ft_lst_size(a_pile);
	pile_ranker(a_pile);
	if (stack_is_sorted(a_pile, b_pile) == 1)
		return (ft_lst_clear(a_pile), (void)0);
	if (size == 2)
		do_ra(a_pile);
	else if (size <= 5)
		ft_small_sort(a_pile, b_pile);
	else
		ft_big_sort(a_pile, b_pile);
	ft_lst_clear(a_pile);
}
