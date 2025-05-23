/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:34:33 by kskender          #+#    #+#             */
/*   Updated: 2025/05/23 12:57:16 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void assign_indexes(t_stack *stack)
{
	t_stack *ptr;
	t_stack *current;
	int value;
	int count;

	ptr = stack;
	while (ptr)
	{
		current = stack;
		count = 0;
		value = ptr->value;
		while (current)
		{
			if (ptr->value > current->value)
				count++;
			current = current->next;
		}
		ptr->index = count;
		ptr = ptr->next;
	}
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

void sort_big(t_stack **a, t_stack **b)
{
	int max_bits;
	int size;
	int i;
	int j;

	assign_indexes(*a);
	max_bits = get_max_bits(*a);
	size = stack_size(*a);
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a, 1);
			else
				pb(a, b, 1);
		}
		while (*b != NULL)
			pa(a, b, 1);
	}
}
