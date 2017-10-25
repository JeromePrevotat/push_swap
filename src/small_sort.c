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


int	sort_three(t_p *piles, int print)
{
	get_max(piles);
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

int	sort_five(t_p *piles, int print)
{
	(void)print;
	(void)piles;
	return (TRUE);
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
