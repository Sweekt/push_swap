/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:24:41 by beroy             #+#    #+#             */
/*   Updated: 2024/01/18 00:49:24 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*a_pile;

	if (ac < 2)
		return (0);
	a_pile = params_parser(ac, av);
	ft_lst_display(&a_pile);
	//error_checker();
}