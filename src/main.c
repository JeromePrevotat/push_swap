/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c		   	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	int	*tab;
	int i;
	int size;

	(void)argc;
	(void)argv;
	/*size = 10;
	if (!(tab = (int *)malloc(size * sizeof(int))))
		return (-1);
	i = 0;
	while (i < size)
	{
		tab[i] = i;
		i++;
	}
	i = 1;
	while (i < size)
	{
		if (i % 2 == 0)
			tab[i] = -tab[i];
		i++;
	}*/

	size = 5;
	if (!(tab = (int *)malloc(size * sizeof(int))))
		return (-1);
	tab[0] = -58;
	tab[1] = 0;
	tab[2] = 42;
	tab[3] = -100;
	tab[4] = 58;

	i = 0;
	ft_putendl("INITIAL ORDER :");
	print_tab(tab, size);
	quicksort(tab, 0, size);
	ft_putendl("NEW ORDER :");
	print_tab(tab, size);
	return (0);
}

void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		ft_putstr(" // ");
		i++;
	}
	ft_putchar('\n');
}
