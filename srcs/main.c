/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:24:41 by beroy             #+#    #+#             */
/*   Updated: 2024/01/30 21:06:22 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*a_pile;
	t_pile	*b_pile;

	b_pile = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		ac = ft_tablen(av) + 1;
	}
	else
		av++;
	if (params_checker(ac, av) == 1)
		return (write(2, "Error\n", 7), 0);
	a_pile = params_parser(ac, av);
	if (dupe_checker(&a_pile) == 1)
		return (write(2, "Error\n", 7), 0);
	pile_ranker(&a_pile);
	ft_lst_display(&a_pile);
	push_swap(&a_pile, &b_pile);
	ft_lst_display(&a_pile);
}
