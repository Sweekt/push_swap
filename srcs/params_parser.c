/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:49:13 by beroy             #+#    #+#             */
/*   Updated: 2024/01/16 13:47:10 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*params_parser(int ac, char **av)
{
	t_list	*a_pile;
	t_list	*tmp;
	int	i;

	a_pile = ft_lstnew(av[1]);
	i = 2;
	while (i < ac)
	{
		tmp = ft_lst_new(av[i]);
		if (tmp == NULL)
			return (ft_lstclear, NULL);
		ft_lstadd_back(&a_pile, tmp);
	}
	return (a_pile);
}