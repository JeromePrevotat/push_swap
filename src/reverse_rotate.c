/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	r_rotate_a(t_pile *pile_a, int print)
{
	size_t	i;

	if (!pile_a->pile || pile_a->size < 2)
		return ;
	i = pile_a->size - 1;
	while (i > 0)
	{
		swap_int(&pile_a->pile[i], &pile_a->pile[i - 1]);
		i--;
	}
	if (print == 1)
		ft_putendl("rra");
}

void	r_rotate_b(t_pile *pile_b, int print)
{
	size_t	i;

	if (!pile_b->pile || pile_b->size < 2)
		return ;
	i = pile_b->size - 1;
	while (i > 0)
	{
		swap_int(&pile_b->pile[i], &pile_b->pile[i - 1]);
		i--;
	}
	if (print == 1)
		ft_putendl("rrb");
}

void	r_rotate_ab(t_pile *pile_a, t_pile *pile_b, int print)
{
	size_t	i;

	if (!pile_a->pile || pile_a->size < 2 || !pile_b->pile || pile_b->size < 2)
		return ;
	i = pile_a->size - 1;
	while (i > 0)
	{
		swap_int(&pile_a->pile[i], &pile_a->pile[i - 1]);
		i--;
	}
	i = pile_b->size - 1;
	while (i > 0)
	{
		swap_int(&pile_b->pile[i], &pile_b->pile[i - 1]);
		i--;
	}
	if (print == 1)
		ft_putendl("rrr");
}
