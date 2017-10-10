/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		check_int_range(char *nb)
{
	int	i;
	int	j;
	int	minus;

	i = 0;
	j = 0;
	minus = FALSE;
	while (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			minus = TRUE;
		i++;
	}
	while (nb[i + j] != '\0')
		j++;
	if (j < 10)
		return (TRUE);
	if (j > 10)
		return (FALSE);
	if (j == 10)
		if (minus == TRUE)
			return (check_int_min(nb + i));
		return (check_int_max(nb + i));
	return (FALSE);
}

int		check_int_min(char *nb)
{
	int		part1;
	int		part2;
	char	c;

	c = nb[0];
	part1 = ft_atoi(&c);
	part2 = ft_atoi(nb + 1);
	if (part2 <= 147483648 && part1 <= 2)
		return (TRUE);
	else if (part2 <= 147483648 && part1 > 2)
		return (FALSE);
	else if (part2 > 147483648 && part1 < 2)
		return (TRUE);
	else if (part2 > 147483648 && part1 >= 2)
		return (FALSE);
	return (-1);
}

int		check_int_max(char *nb)
{
	int		part1;
	int		part2;
	char	c;

	c = nb[0];
	part1 = ft_atoi(&c);
	part2 = ft_atoi(nb + 1);
	if (part2 <= 147483647 && part1 <= 2)
		return (TRUE);
	else if (part2 <= 147483647 && part1 > 2)
		return (FALSE);
	else if (part2 > 147483647 && part1 < 2)
		return (TRUE);
	else if (part2 > 147483647 && part1 >= 2)
		return (FALSE);
	return (-1);
}
