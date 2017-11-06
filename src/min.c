/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	get_min(t_p *piles)
{
	size_t	i;

	i = 0;
	piles->min = piles->p_a->pile[0];
	piles->min_index = 0;
	while (i < piles->p_a->size)
	{
		if (piles->p_a->pile[i] < piles->min)
		{
			piles->min = piles->p_a->pile[i];
			piles->min_index = i;
		}
		i++;
	}
}

int		exist_smallest(t_p *piles, int pivot)
{
	int	i;

	i = 0;
	while (i < piles->min_index)
	{
		if (piles->p_a->pile[i] < pivot)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	move_min(t_p *piles, int index_to_place, int verbal)
{
	int	i;

	i = 0;
	if (piles->min_index < index_to_place)
		move_min_down(piles, index_to_place, verbal);
	else
		move_min_up(piles, index_to_place, verbal);
	piles->min_index = index_to_place;
}

void	move_min_up(t_p *piles, int index_to_place, int verbal)
{
	int	i;

	i = 0;
	if ((size_t)(piles->min_index - index_to_place) < piles->p_a->size / 2)
	{
		i = piles->min_index - index_to_place;
		while (i > 0)
		{
			rotate_a(piles, 1, verbal);
			i--;
		}
	}
	else
	{
		i = piles->p_a->size - (piles->min_index - index_to_place);
		while (i > 0)
		{
			r_rotate_a(piles, 1, verbal);
			i--;
		}
	}
}

void	move_min_down(t_p *piles, int index_to_place, int verbal)
{
	int	i;

	i = 0;
	if ((size_t)(index_to_place - piles->min_index) > piles->p_a->size / 2)
	{
		i = piles->p_a->size - (index_to_place - piles->min_index);
		while (i > 0)
		{
			rotate_a(piles, 1, verbal);
			i--;
		}
	}
	else
	{
		i = index_to_place - piles->min_index;
		while (i > 0)
		{
			r_rotate_a(piles, 1, verbal);
			i--;
		}
	}
}
