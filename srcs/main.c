/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:24:41 by beroy             #+#    #+#             */
/*   Updated: 2024/01/22 19:26:22 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*a_pile;

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
	ft_lst_display(&a_pile);
	//error_checker();
}
