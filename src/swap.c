/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_a(t_pile *pile_a, int print)
{
	int	tmp;

	if (!pile_a->pile || pile_a->size < 2)
		return ;
	tmp = pile_a->pile[0];
	pile_a->pile[0] = pile_a->pile[1];
	pile_a->pile[1] = tmp;
	if (print == 1)
		ft_putendl("sa");
}

void	swap_b(t_pile *pile_b, int print)
{
	int	tmp;

	if (!pile_b->pile || pile_b->size < 2)
		return ;
	tmp = pile_b->pile[0];
	pile_b->pile[0] = pile_b->pile[1];
	pile_b->pile[1] = tmp;
	if (print == 1)
		ft_putendl("sb");
}

void	swap_ab(t_pile *pile_a, t_pile *pile_b, int print)
{
	int	tmp;

	if (!pile_a->pile || pile_a->size < 2 || !pile_b->pile || pile_b->size < 2)
		return ;
	tmp = pile_a->pile[0];
	pile_a->pile[0] = pile_a->pile[1];
	pile_a->pile[1] = tmp;
	tmp = pile_b->pile[0];
	pile_b->pile[0] = pile_b->pile[1];
	pile_b->pile[1] = tmp;
	if (print == 1)
		ft_putendl("ss");
}
