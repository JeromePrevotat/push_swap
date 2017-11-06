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

void	push_a(t_p *piles, int print, int verbal)
{
	size_t	i;

	if (!piles->p_a || !piles->p_b || piles->p_b->size == 0)
		return ;
	piles->p_a->pile[piles->p_a->size] = piles->p_b->pile[0];
	i = piles->p_a->size;
	while (i > 0)
	{
		swap_int(&piles->p_a->pile[i], &piles->p_a->pile[i - 1]);
		i--;
	}
	i = 0;
	while (i < piles->p_b->size - 1)
	{
		swap_int(&piles->p_b->pile[i], &piles->p_b->pile[i + 1]);
		i++;
	}
	piles->p_b->size--;
	piles->p_a->size++;
	piles->min_index++;
	if (print == 1)
		ft_putendl("pa");
	if (verbal == 1)
		print_piles(piles);
}

void	push_b(t_p *piles, int print, int verbal)
{
	size_t	i;

	if (!piles->p_a || !piles->p_b || piles->p_a->size == 0)
		return ;
	piles->p_b->pile[piles->p_b->size] = piles->p_a->pile[0];
	i = piles->p_b->size;
	while (i > 0)
	{
		swap_int(&piles->p_b->pile[i], &piles->p_b->pile[i - 1]);
		i--;
	}
	i = 0;
	while (i < piles->p_a->size - 1)
	{
		swap_int(&piles->p_a->pile[i], &piles->p_a->pile[i + 1]);
		i++;
	}
	piles->p_a->size--;
	piles->p_b->size++;
	piles->min_index--;
	if (print == 1)
		ft_putendl("pb");
	if (verbal == 1)
		print_piles(piles);
}
