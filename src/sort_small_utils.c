/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:07:59 by kskender          #+#    #+#             */
/*   Updated: 2025/05/29 16:39:16 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_minimum(t_stack *stack)
{
	int		min;
	int		min_pos;
	int		current_pos;
	t_stack	*current;

	min = stack->value;
	min_pos = 0;
	current_pos = 0;
	current = stack;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (min_pos);
}

void	bring_min_to_top(t_stack **a)
{
	int	min_pos;
	int	size;

	min_pos = find_minimum(*a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a, 1);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos-- > 0)
			rra(a, 1);
	}
}
