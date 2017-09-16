/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void exec_line(char *line, t_p *piles)
{
	if (ft_strcmp(line, "ra") == 0)
		rotate_a(piles->p_a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_b(piles->p_b);
	else if (ft_strcmp(line, "pa") == 0)
		push_a(piles->p_a, piles->p_b);
	else if (ft_strcmp(line, "pb") == 0)
		push_b(piles->p_a, piles->p_b);
	else if (ft_strcmp(line, "rra") == 0)
		r_rotate_a(piles->p_a);
	else if (ft_strcmp(line, "rrb") == 0)
		r_rotate_b(piles->p_b);
	else if (ft_strcmp(line, "rr") == 0)
	{
		rotate_a(piles->p_a);
		rotate_b(piles->p_b);
	}
	else if (ft_strcmp(line, "rrr") == 0)
	{
		r_rotate_a(piles->p_a);
		r_rotate_b(piles->p_b);
	}
	else
		ft_error();
}
