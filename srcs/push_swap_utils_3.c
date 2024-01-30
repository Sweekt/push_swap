/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:03:01 by beroy             #+#    #+#             */
/*   Updated: 2024/01/30 19:30:06 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_nbr_len(int nbr, int *len)
{
	if (nbr >= 2)
		ft_nbr_len(nbr / 2, len);
	*len += 1;
}

void	ft_fill_zero(char *str, int len, int *i)
{
	while (*i < MAX_BIN - len)
	{
		str[*i] = '0';
		*i += 1;
	}
}

void	ft_nbr_to_str(unsigned int nbr, char *str, int *i)
{
	if (nbr >= 2)
		ft_nbr_to_str(nbr / 2, str, i);
	str[*i] = nbr % 2 + 48;
	*i += 1;
}

char	*ft_itob(unsigned int nbr)
{
	int len;
	int i;
	char	*res;

	len = 0;
	i = 0;
	ft_nbr_len(nbr, &len);
	res = malloc(sizeof(char) * (MAX_BIN + 1));
	ft_fill_zero(res, len, &i);
	ft_nbr_to_str(nbr, res, &i);
	res[i] = 0;
	return (res);
}
