/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0
# define ERROR -1

#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define BLUE	"\x1B[34m"
#define MAGENTA	"\x1B[35m"
#define CYAN	"\x1B[36m"
#define WHITE	"\x1B[37m"
#define RESET	"\x1B[0m"

# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_pile
{
	size_t		size;
	int			*pile;
}				t_pile;

typedef struct	s_p
{
	t_pile		*p_a;
	t_pile		*p_b;
}				t_p;

//Push_swap
void	push_swap(t_p *piles);

//Sort_int.c
//int		split(int *tab, int start, int end, int pivot);
//int		quicksort(int *tab, int start, int end);
int		split(t_p *piles, int start, int end, int pivot);
int		quicksort(t_p *piles, int start, int end);

//Parsing.c
char	*get_arg(int argc, char **argv, char *arg);
char	**check_arg(char *arg);
int		set_pile(char **arg_tab, t_pile *pile_a, t_pile *pile_b, t_p *piles);
int		check_doublons(t_pile *pile);

//Rotate.c
void	rotate_a(t_pile *pile_a);
void	rotate_b(t_pile *pile_b);
void	rotate_ab(t_pile *pile_a, t_pile *pile_b);

//Reverse_rotate.c
void	r_rotate_a(t_pile *pile_a);
void	r_rotate_b(t_pile *pile_b);
void	r_rotate_ab(t_pile *pile_a, t_pile *pile_b);

//Swap.c
void	swap_a(t_pile *pile_a);
void	swap_b(t_pile *pile_b);
void	swap_ab(t_pile *pile_a, t_pile *pile_b);

//Push.c
void	push_a(t_pile *pile_a, t_pile *pile_b);
void	push_b(t_pile *pile_a, t_pile *pile_b);

//Utils.c
void	swap_int(int *a, int *b);
void	print_tab(t_pile *pile);
void	ft_error(void);

#endif
