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

#include "../inc/push_swap.h"

void	exec_line(char *line, t_p *piles)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_a(piles->p_a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		swap_b(piles->p_b, 0);
	else if (ft_strcmp(line, "ra") == 0)
		rotate_a(piles, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_b(piles, 0);
	else if (ft_strcmp(line, "pa") == 0)
		push_a(piles, 0);
	else if (ft_strcmp(line, "pb") == 0)
		push_b(piles, 0);
	else if (ft_strcmp(line, "rra") == 0)
		r_rotate_a(piles, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		r_rotate_b(piles, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_ab(piles, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		r_rotate_ab(piles, 0);
	else if (ft_strcmp(line, "ss") == 0)
		swap_ab(piles->p_a, piles->p_b, 0);
	else
		ft_error();
}

int		check(t_p *piles)
{
	size_t	i;

	i = 1;
	while (i < piles->p_a->size - 1)
	{
		if (piles->p_a->pile[i] < piles->p_a->pile[i - 1] || piles->p_a->pile[i] > piles->p_a->pile[i + 1])
			return (0);
		i++;
	}
	return (1);
}
