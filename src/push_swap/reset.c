/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void reset(t_p *piles)
{
	size_t	i;

	i = 0;
	while (piles->p_a->pile[i] != piles->max)
		i++;
	if ((piles->p_a->size / 2) - i > 0)
		while (piles->p_a->pile[piles->p_a->size - 1] != piles->max)
			rotate_a(piles->p_a);
	else
		while (piles->p_a->pile[piles->p_a->size - 1] != piles->max)
			r_rotate_a(piles->p_a);
}
