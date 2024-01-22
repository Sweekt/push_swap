/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:49:13 by beroy             #+#    #+#             */
/*   Updated: 2024/01/22 19:25:46 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int params_checker(int ac, char **av)
{
	int	i;
	int j;

	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (1);
			j++;
		}
		if (ft_strlen(av[i]) > 11)
			return (1);

		i++;
	}
	return (0);
}

t_pile	*params_parser(int ac, char **av)
{
	t_pile	*a_pile;
	t_pile	*tmp;
	int	i;

	a_pile = ft_lst_new(ft_atoi(av[0]));
	i = 1;
	while (i < ac - 1)
	{
		tmp = ft_lst_new(ft_atoi(av[i]));
		if (tmp == NULL)
			return (ft_lst_clear(&a_pile), NULL);
		ft_lst_add_back(&a_pile, tmp);
		i++;
	}
	return (a_pile);
}
