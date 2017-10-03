/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	add_buffer(t_p *piles, char *instruction)
{
	if (ft_strlen(piles->buffer) + ft_strlen(instruction) + 1 > 256)
	{
		print_buffer(piles);
		ft_memset(piles->buffer, '\0', 256);
		ft_strcat(piles->buffer, instruction);
	}
	else
		ft_strcat(piles->buffer, instruction);
}

void print_buffer(t_p *piles)
{
	write(1, piles->buffer, ft_strlen(piles->buffer));
}
