/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		main(int argc, char **argv)
{
	t_p		*piles;
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
		if (!(piles = (t_p *)malloc(1 * sizeof(t_p)))
			|| !(pile_a = (t_pile *)malloc(1 * sizeof(t_pile)))
			|| !(pile_b = (t_pile *)malloc(1 * sizeof(t_pile))))
			return (ERROR);
		if (set_pile(arg_tab, pile_a, pile_b, piles) == ERROR)
			ft_error();
	}
	checker(piles);
	free_ressources(piles, arg_tab, arg);
	return (0);
}

void	checker(t_p *piles)
{
	char	*line;
	int		instruction;

	instruction = 0;
	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		exec_line(line, piles);
		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
		instruction++;
	}
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	if (check(piles) == 0)
		ft_putendl("KO");
	else
		ft_putendl("OK");
	printf("NB COUPS : %d\n", instruction);
}
