/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:21:58 by kskender          #+#    #+#             */
/*   Updated: 2025/05/22 18:31:42 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ra(t_stack **a, int print)
{
	t_stack *first;
	t_stack *last;

	if (!*a || !(*a)->next)
		return;
	first = *a;
	last = find_last_node(*a);
	*a = first->next;
	(*a)->prev = NULL;
	first->prev = last;
	first->next = NULL;
	last->next = first;
	if (print)
		write(1, "ra\n", 3);
}

void rb(t_stack **b, int print)
{
	t_stack *first;
	t_stack *last;

	if (!*b || !(*b)->next)
		return;
	first = *b;
	last = find_last_node(*b);
	*b = first->next;
	(*b)->prev = NULL;
	first->prev = last;
	first->next = NULL;
	last->next = first;
	if (print)
		write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
}
