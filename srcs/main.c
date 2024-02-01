/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:24:41 by beroy             #+#    #+#             */
/*   Updated: 2024/02/01 16:46:17 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**tab_shift(char **av, int ac)
{
	char	**tab;
	int 	i;

	tab = malloc(sizeof(char *) * ac);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac - 1)
	{
		tab[i] = ft_strdup(av[i + 1]);
		if (tab[i] == NULL)
		{
			ft_splitdestroy(tab);
			exit (0);
		}
		i++;
	}
	tab[i] = 0;
	return (tab);
}

int	main(int ac, char **av)
{
	t_pile	*a_pile;
	t_pile	*b_pile;

	b_pile = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (av[1][0] == 0)
			return (write(STDERR_FILENO, "Error\n", 6), 0);
		av = ft_split(av[1], ' ');
		ac = ft_tablen(av) + 1;
	}
	else
		av = tab_shift(av, ac);
	if (ac < 3)
		return (ft_splitdestroy(av), 0);
	if (params_checker(ac, av) == 1)
		return (ft_splitdestroy(av), write(STDERR_FILENO, "Error\n", 6), 0);
	a_pile = params_parser(ac, av);
	ft_splitdestroy(av);
	if (dupe_checker(&a_pile) == 1)
		return (ft_lst_clear(&a_pile), write(STDERR_FILENO, "Error\n", 6), 0);
	push_swap(&a_pile, &b_pile);
	return (0);
}
