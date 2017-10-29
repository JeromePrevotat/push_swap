/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		sort_three(t_p *piles, int print)
{
	get_max(piles);
	if ((piles->min_index == 1 && piles->max_index == 0)
		|| (piles->min_index == 2 && piles->max_index == 1)
		|| (piles->min_index == 1 && piles->max_index == 2))
		return (sort_three_simple(piles, print));
	if (piles->min_index == 2 && piles->max_index == 0)
	{
		swap_a(piles, print);
		r_rotate_a(piles, print);
		return (TRUE);
	}
	if (piles->min_index == 0 && piles->max_index == 1)
	{
		swap_a(piles, print);
		rotate_a(piles, print);
		return (TRUE);
	}
	return (TRUE);
}

int		sort_three_simple(t_p *piles, int print)
{
	if (piles->min_index == 1 && piles->max_index == 0)
	{
		rotate_a(piles, print);
		return (TRUE);
	}
	if (piles->min_index == 2 && piles->max_index == 1)
	{
		r_rotate_a(piles, print);
		return (TRUE);
	}
	if (piles->min_index == 1 && piles->max_index == 2)
	{
		swap_a(piles, print);
		return (TRUE);
	}
	return (FALSE);
}

int		sort_five(t_p *piles, int print)
{
	if (piles->p_a->size == 5)
		push_b(piles, print);
	if (piles->p_a->size == 4)
		push_b(piles, print);
	get_max(piles);
	get_min(piles);
	sort_three(piles, print);
	cat_list(piles, print);
	get_min(piles);
	move_min(piles, 0);
	return (TRUE);
}

void	cat_list(t_p *piles, int print)
{
	size_t	end;

	end = 0;
	if (piles->p_b->size > 1 && piles->p_b->pile[0] > piles->p_b->pile[1])
		swap_b(piles, print);
	while (piles->p_b->size != 0)
	{
		if (end == piles->p_a->size)
			push_a(piles, print);
		if (piles->p_a->pile[0] > piles->p_b->pile[0])
			push_a(piles, print);
		else
		{
			rotate_a(piles, print);
			end++;
		}
	}
}

void	get_max(t_p *piles)
{
	size_t	i;

	i = 0;
	piles->max = piles->p_a->pile[0];
	piles->max_index = 0;
	while (i < piles->p_a->size)
	{
		if (piles->p_a->pile[i] > piles->max)
		{
			piles->max = piles->p_a->pile[i];
			piles->max_index = i;
		}
		i++;
	}
}
