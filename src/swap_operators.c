/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:07:19 by kskender          #+#    #+#             */
/*   Updated: 2025/05/22 18:31:42 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sa(t_stack **a, int print)
{
	t_stack *first;
	t_stack *second;

	if (!*a || !(*a)->next)
		return;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	*a = second;
	if (print)
		write(1, "sa\n", 3);
}

void sb(t_stack **b, int print)
{
	t_stack *first;
	t_stack *second;
	if (!*b || !(*b)->next)
		return;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	second = *b;
	if (print)
		write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		write(1, "ss\n", 3);
}
