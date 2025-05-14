/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:08:51 by kskender          #+#    #+#             */
/*   Updated: 2025/05/14 14:59:57 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int value;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

typedef struct s_stack
{
	t_stack *a;
	t_stack *b;
} t_data;
/* Parsing */
void parse_args(int argc, char **argv);
void validate_args(char **args);

/* Stack Utils */
t_stack *stack_last(t_stack *stack);
void free_stack(t_stack **stack);
int stack_size(t_stack *stack);
void exit_error(t_data *data);
int *create_sorted_array(t_data *data, int size);

/* Operations */
void sa(t_stack **a, int print);
void sb(t_stack **b, int print);
void ss(t_stack **a, t_stack **b, int print);
void pa(t_stack **a, t_stack **b, int print);
void pb(t_stack **a, t_stack **b, int print);
void ra(t_stack **a, int print);
void rb(t_stack **b, int print);
void rr(t_stack **a, t_stack **b, int print);
void rra(t_stack **a, int print);
void rrb(t_stack **b, int print);
void rrr(t_stack **a, t_stack **b, int print);

/* Sorting */
void sort_small(t_stack **a);
void sort_big(t_stack **a, t_stack **b);

#endif
