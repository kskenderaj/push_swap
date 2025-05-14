/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:34:33 by kskender          #+#    #+#             */
/*   Updated: 2025/05/13 13:33:06 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void assign_indexes(t_stack *a)
{
	t_stack *ptr;
	t_stack *current;
	int i;

	ptr = a;
	while (ptr)
	{
		current = a;
		i = 0;
		while (current)
		{
			if (ptr->value > current->value)
				i++;
			current = current->next;
		}
		ptr->index = i;
		ptr = ptr->next;
	}
}

int stack_size(t_stack *stack)
{
	int size;
	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int get_max_bits(t_stack *stack)
{
	int size;
	int max_bits;

	size = stack_size(stack);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

void radix_sort(t_stack **a, t_stack **b)
{
	int max_bits;
	int size;
	int i;
	int j;

	assign_indexes(*a);
	max_bits = 0;
	size = stack_size(*a);
	while ((size - 1) >> max_bits)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((*a)->index >> i) & 1)
				pb(a, b);
			else
				ra(a);
		}
		while (*b)
			pa(a, b);
	}
}
