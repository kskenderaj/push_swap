/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operators.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:58:16 by kskender          #+#    #+#             */
/*   Updated: 2025/05/29 16:37:28 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack **a, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*a || !(*a)->next)
		return ;
	second_last = NULL;
	last = *a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *a;
	last->prev = NULL;
	(*a)->prev = last;
	*a = last;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*b || !(*b)->next)
		return ;
	second_last = NULL;
	last = *b;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *b;
	last->prev = NULL;
	(*b)->prev = last;
	*b = last;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		write(1, "rrr\n", 4);
}
