/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c		   	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void push_a(t_pile *pile_a, t_pile *pile_b, int print)
{
	size_t	i;

	if (!pile_a || !pile_b || pile_b->size == 0)
		return ;
	pile_a->pile[pile_a->size] = pile_b->pile[0];
	i = pile_a->size;
	while (i > 0)
	{
		swap_int(&pile_a->pile[i], &pile_a->pile[i - 1]);
		i--;
	}
	i = 0;
	while (i < pile_b->size - 1)
	{
		swap_int(&pile_b->pile[i], &pile_b->pile[i + 1]);
		i++;
	}
	pile_b->size--;
	pile_a->size++;
	if (print == 1)
		ft_putendl("pa");
}

void push_b(t_pile *pile_a, t_pile *pile_b, int print)
{
	size_t	i;

	if (!pile_a || !pile_b || pile_a->size == 0)
		return ;
	pile_b->pile[pile_b->size] = pile_a->pile[0];
	i = pile_b->size;
	while (i > 0)
	{
		swap_int(&pile_b->pile[i], &pile_b->pile[i - 1]);
		i--;
	}
	i = 0;
	while (i < pile_a->size - 1)
	{
		swap_int(&pile_a->pile[i], &pile_a->pile[i + 1]);
		i++;
	}
	pile_a->size--;
	pile_b->size++;
	if (print == 1)
		ft_putendl("pb");
}
