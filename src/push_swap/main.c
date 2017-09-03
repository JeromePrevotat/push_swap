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

#include "../../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	char	**arg_tab;
	char	*arg;

	arg = NULL;
	if (argc < 2)
		exit(0);
	else
	{
		arg = get_arg(argc, argv, arg);
		if ((arg_tab = check_arg(arg)) == NULL)
			ft_error();
		if(!(pile_a = (t_pile *)malloc(1 * sizeof(t_pile)))
			|| !(pile_b = (t_pile *)malloc(1 * sizeof(t_pile))))
			return (ERROR);
		if (set_pile(arg_tab, pile_a, pile_b) == ERROR)
			ft_error();
		push_swap(pile_a, pile_b);
	}
	if (arg != NULL)
		free(arg);
	return (0);
}

void push_swap(t_pile *pile_a, t_pile *pile_b)
{
	size_t	i;

	i = 0;
	quicksort(pile_a, 0, pile_a->size - 1, pile_b);
	ft_putendl("Pile A :");
	print_tab(pile_a);
	ft_putendl("Pile B :");
	print_tab(pile_b);
}
