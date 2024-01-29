/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:12:18 by beroy             #+#    #+#             */
/*   Updated: 2024/01/29 20:11:45 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../super_libft/libft.h"

typedef struct s_pile
{
	int 			content;
	int				rank;
	struct s_pile	*next;
}	t_pile;

// Params Parser

t_pile	*params_parser(int ac, char **av);
int		params_checker(int ac, char **av);
int 	dupe_checker(t_pile **pile);
void	pile_ranker(t_pile **pile);

// Push Swap Utils

t_pile	*ft_lst_new(int content);
t_pile	*ft_lst_last(t_pile *lst);
void	ft_lst_add_back(t_pile **lst, t_pile *new);
void	ft_lst_clear(t_pile **lst);
void	ft_lst_display(t_pile **lst);

// Push Swap Utils 2

int 	ft_lst_size(t_pile **lst);
int		ft_tablen(char **tab);
int 	ft_is_number(char *str);
int		ft_is_int(char *str);

// Pile Swap

void	ft_swap(t_pile **pile);
void	do_sa(t_pile **a_pile);
void	do_sb(t_pile **b_pile);
void	do_ss(t_pile **a_pile, t_pile **b_pile);

// Pile Push

void	ft_push(t_pile **a_pile, t_pile **b_pile);
void	do_pa(t_pile **a_pile, t_pile **b_pile);
void	do_pb(t_pile **a_pile, t_pile **b_pile);

// Pile Rotate

void	ft_rotate(t_pile **pile);
void	do_ra(t_pile **a_pile);
void	do_rb(t_pile **b_pile);
void	do_rr(t_pile **a_pile, t_pile **b_pile);

// Pile Reverse Rotate

void	ft_reverse_rotate(t_pile **pile);
void	do_rra(t_pile **a_pile);
void	do_rrb(t_pile **b_pile);
void	do_rrr(t_pile **a_pile, t_pile **b_pile);

#endif