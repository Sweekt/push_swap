/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:59:07 by beroy             #+#    #+#             */
/*   Updated: 2024/02/01 17:57:46 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int stack_is_sorted(t_pile **a_pile, t_pile **b_pile)
{
	t_pile	*tmp;
	int 	i;

	if (*b_pile != NULL || *a_pile == NULL)
		return (0);
	tmp = *a_pile;
	i = 0;
	while (tmp->next != NULL)
	{
		if (tmp->rank != i)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

int ft_lst_size(t_pile **lst)
{
	int i;
	t_pile	*tmp;

	i = 0;
	tmp = *lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int ft_is_int(char *str)
{
	int i;
	long int	res;
	int sign;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '-')
			sign *= -1;
	}
	while (str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	res *= sign;
	if (res > 2147483647 || res < -2147483648)
		return (0);
	return (1);
}

int ft_is_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (i == 1 && ft_isdigit(str[i]) == 0)
		return (0);
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] != 0)
		return (0);
	return (1);
}

int	ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
