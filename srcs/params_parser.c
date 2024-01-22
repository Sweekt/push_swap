/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:49:13 by beroy             #+#    #+#             */
/*   Updated: 2024/01/17 16:03:40 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*params_parser(int ac, char **av)
{
	t_pile	*a_pile;
	t_pile	*tmp;
	int	i;

	a_pile = ft_lst_new(ft_atoi(av[1]));
	i = 2;
	while (i < ac)
	{
		tmp = ft_lst_new(ft_atoi(av[i]));
		if (tmp == NULL)
			return (ft_lstclear(a_pile), NULL);
		ft_lstadd_back(&a_pile, tmp);
	}
	return (a_pile);
}