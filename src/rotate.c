/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_a(t_p *piles, int print)
{
	size_t	i;

	if (!piles->p_a->pile || piles->p_a->size < 2)
		return ;
	i = 0;
	while (i < piles->p_a->size - 1)
	{
		swap_int(&piles->p_a->pile[i], &piles->p_a->pile[i + 1]);
		i++;
	}
	if (print == 1)
		add_buffer(piles, "ra\n");
	piles->min_index--;
	if (piles->min_index < 0)
		piles->min_index = piles->p_a->size - 1;
}

void	rotate_b(t_p *piles, int print)
{
	size_t	i;

	if (!piles->p_b->pile || piles->p_b->size < 2)
		return ;
	i = 0;
	while (i < piles->p_b->size - 1)
	{
		swap_int(&piles->p_b->pile[i], &piles->p_b->pile[i + 1]);
		i++;
	}
	if (print == 1)
		add_buffer(piles, "rb\n");
}

void	rotate_ab(t_p *piles, int print)
{
	size_t	i;

	i = 0;
	if (!piles->p_a->pile || piles->p_a->size < 2
		|| !piles->p_b->pile || piles->p_b->size < 2)
		return ;
	while (i < piles->p_a->size - 1)
	{
		swap_int(&piles->p_a->pile[i], &piles->p_a->pile[i + 1]);
		i++;
	}
	piles->min_index--;
	if (piles->min_index < 0)
		piles->min_index = piles->p_a->size - 1;
	i = 0;
	while (i < piles->p_b->size - 1)
	{
		swap_int(&piles->p_b->pile[i], &piles->p_b->pile[i + 1]);
		i++;
	}
	if (print == 1)
		add_buffer(piles, "rr\n");
}
