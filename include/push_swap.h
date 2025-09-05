/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:08:51 by kskender          #+#    #+#             */
/*   Updated: 2025/06/03 18:11:00 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
}					t_data;

/* Parsing */
void				parse_args(t_data *data, int argc, char **argv);
void				validate_args(t_data *data, char *args);
void				add_to_stack(t_stack **stack, int value);
int					has_duplicate(t_stack *stack, int num);
void				free_split(char **split);
long				ft_atol(char *str);

/* Stack Utils */
t_stack				*stack_last(const t_stack *stack);
void				free_stack(t_stack **stack);
int					stack_size(t_stack *stack);
void				exit_error(t_data *data);
int					is_sorted(t_stack *stack);
t_stack				*find_last_node(t_stack *head);
void				stack_new(int value);
int					find_min(t_stack **a);

/* Operations */
void				sa(t_stack **a, int print);
void				sb(t_stack **b, int print);
void				ss(t_stack **a, t_stack **b, int print);
void				pa(t_stack **a, t_stack **b, int print);
void				pb(t_stack **a, t_stack **b, int print);
void				ra(t_stack **a, int print);
void				rb(t_stack **b, int print);
void				rr(t_stack **a, t_stack **b, int print);
void				rra(t_stack **a, int print);
void				rrb(t_stack **b, int print);
void				rrr(t_stack **a, t_stack **b, int print);

/* Sorting */
int					find_minimum(t_stack *stack);
void				bring_min_to_top(t_stack **a);
void				sort_two(t_stack **a);
void				sort_three(t_stack **a);
void				sort_four(t_data *data);
void				sort_five(t_data *data);
void				sort_big(t_stack **a, t_stack **b);

#endif
