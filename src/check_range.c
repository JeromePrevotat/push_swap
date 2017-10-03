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
	int		i;
	int		j;
	char	*intmin;

	i = ft_strlen(nb);
	j = i - 1;
	intmin = "2147483648";
	while (i >= 0)
	{
		if (ft_strcmp(&nb[i], &intmin[i]) > 0)
		{
			j = i - 1;
			while (j >= 0)
			{
				if (ft_strcmp(&nb[j], &intmin[j]) > 0)
					return (FALSE);
				j--;
			}
		}
		i--;
	}
	return (TRUE);
}

int		check_int_max(char *nb)
{
	int		i;
	int		j;
	char	*intmax;

	i = ft_strlen(nb);
	j = i - 1;
	intmax = "2147483647";
	if (ft_strcmp(nb, intmax) <= 0)
		return (TRUE);
	while (i >= 0)
	{
		if (ft_strncmp(&nb[i], &intmax[i], 1) > 0)
		{
			printf("TESTED 1 : >%c< // >%c< // %d\n", nb[i], intmax[i], ft_strncmp(&nb[i], &intmax[i], 1));
			j = i - 1;
			while (j >= 0)
			{
				printf("TESTED 2 : >%c< // >%c< // %d\n", nb[j], intmax[j], ft_strncmp(&nb[j], &intmax[j], 1));
				if (ft_strncmp(&nb[j], &intmax[j], 1) < 0)
					return (TRUE);
				j--;
			}
		}
		i--;
	}
	return (TRUE);
}
