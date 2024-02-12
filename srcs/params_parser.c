/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:49:13 by beroy             #+#    #+#             */
/*   Updated: 2024/02/01 16:33:17 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*find_unrank(t_pile **pile)
{
	t_pile	*tmp;

	tmp = *pile;
	while (tmp != NULL)
	{
		if (tmp->rank == -1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_pile	*find_smallest(t_pile **pile)
{
	t_pile	*smallest;
	t_pile	*tmp;

	tmp = *pile;
	smallest = find_unrank(pile);
	while (tmp != NULL)
	{
		if (tmp->content < smallest->content && tmp->rank == -1)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

void	pile_ranker(t_pile **pile)
{
	t_pile	*tiny;
	int		i;

	i = 0;
	while (i < ft_lst_size(pile))
	{
		tiny = find_smallest(pile);
		tiny->rank = i;
		tiny->b_rank = ft_itob(i);
		if (tiny->b_rank == NULL)
		{
			ft_lst_clear(pile);
			exit (0);
		}
		i++;
	}
}

int	params_checker(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (ft_is_number(av[i]) == 0)
			return (1);
		if (ft_strlen(av[i]) > 11)
			return (1);
		if (ft_is_int(av[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

t_pile	*params_parser(int ac, char **av)
{
	t_pile	*a_pile;
	t_pile	*tmp;
	int		i;

	a_pile = ft_lst_new(ft_atoi(av[0]));
	if (a_pile == NULL)
		return (ft_lst_clear(&a_pile), NULL);
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
