/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		verbal_mode(char **argv)
{
	if (ft_strcmp(argv[1], "-v") == 0)
		return (TRUE);
	return (FALSE);
}

void	print_piles(t_p *piles)
{
	ft_putendl("PILE A :");
	print_tab(piles->p_a);
	ft_putendl("PILE B :");
	print_tab(piles->p_b);
	ft_putchar('\n');
}
