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

#include "../inc/push_swap.h"

void	sort_piles(t_p *piles)
{
	int	i;

	while (check(piles) == 0)
	{
		//printf("PILE A :\n");
		//print_tab(piles->p_a);
		i = 0;
		reset(piles);
		if (piles->p_a->pile[piles->min_index] != piles->min)
		{
			if ((size_t)piles->min_index < piles->p_a->size / 2)
			{
				while (i < piles->min_index)
				{
					rotate_a(piles->p_a, 1);
					i++;
				}
			}
			else
			{
				while ((size_t)i < piles->p_a->size - piles->min_index)
				{
					r_rotate_a(piles->p_a, 1);
					i++;
				}
			}
			start_sort(piles);
		}
		else
		{
			new_min_index(piles);
			new_min(piles);
		}
	}
}

void	start_sort(t_p *piles)
{
	int	i;
	int	pivot;

	push_b(piles->p_a, piles->p_b, 1);
	pivot = piles->p_b->pile[0];
	i = 0;
	while (piles->p_a->pile[0] != piles->max)
	{
		if (piles->p_a->pile[0] < pivot)
			push_b(piles->p_a, piles->p_b, 1);
		else
			rotate_a(piles->p_a, 1);
	}
	r_rotate_b(piles->p_b, 1);
	rotate_a(piles->p_a, 1);
	while (i < piles->min_index)
	{
		rotate_a(piles->p_a, 1);
		i++;
	}
	while (piles->p_b->size > 0)
	{
		//if (piles->p_a->pile[0] > piles->p_a->pile[1]
			//&& piles->p_b->pile[0] > piles->p_a->pile[1]
			//&& piles->p_a->size >= 2 && piles->p_b->size >= 2)
			//swap_ab(piles->p_a, piles->p_b, 1);
		push_a(piles->p_a, piles->p_b, 1);
	}
	while (i > 0)
	{
		r_rotate_a(piles->p_a, 1);
		i--;
	}
}
