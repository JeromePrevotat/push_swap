/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int.c		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_piles(t_p *piles)
{
	int	i;

	while (check(piles) == 0)
	{
		i = 0;
		reset(piles);
		if (piles->p_a->pile[piles->min_index] != piles->min)
		{
			while (i < piles->min_index)
			{
				rotate_a(piles->p_a);
				i++;
			}
			start_sort(piles);
		}
		else
		{
			piles->min_index = new_min_index(piles);
			new_min(piles);
		}
	}
}

void	start_sort(t_p *piles)
{
	int	i;
	int	pivot;

	pivot = piles->p_b->pile[0];
	push_b(piles->p_a, piles->p_b);
	while (piles->p_a->pile[0] != piles->max)
	{
		i = 0;
		if (piles->p_a->pile[0] < pivot)
			push_b(piles->p_a, piles->p_b);
		else
			rotate_a(piles->p_a);
	}
	r_rotate_b(piles->p_b);
	rotate_a(piles->p_a);
	while (i < piles->min_index)
	{
		rotate_a(piles->p_a);
		i++;
	}
	while (piles->p_b->size > 0)
		push_a(piles->p_a, piles->p_b);
	while (i > 0)
	{
		r_rotate_a(piles->p_a);
		i--;
	}
	ft_putendl("Pile A :");
	print_tab(piles->p_a);
	ft_putendl("Pile B :");
	print_tab(piles->p_b);
}
