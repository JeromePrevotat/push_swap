/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c	   	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_tab(t_pile *pile)
{
	size_t	i;

	i = 0;
	while (i < pile->size)
	{
		ft_putnbr(pile->pile[i]);
		ft_putstr(" // ");
		i++;
	}
	ft_putchar('\n');
}

void	swap_int(int *a, int *b)
{
	int tmp;

	if (a && b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/*void	swap_int(int *a, int *b)
{
	if (a && b)
	{
		*a = *a - *b;
		*b = *a + *b;
		*a = *b - *a;
	}
}*/

void ft_error(void)
{
	ft_putendl("Error");
	exit(0);
}
