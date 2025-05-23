/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:08:34 by kskender          #+#    #+#             */
/*   Updated: 2025/05/23 15:20:45 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void sort_three(t_stack **a)
{
	int first;
	int second;
	int third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;

	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && second < third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

void push_smallest(t_stack **a, t_stack **b, int count)
{
	int min;
	int pos;
	t_stack *temp;

	while (count--)
	{
		temp = *a;
		min = temp->value;
		pos = 0;
		while (temp)
		{
			if (temp->value < min)
				min = temp->value;
			temp = temp->next;
		}
		temp = *a;
		while (temp->value != min && ++pos)
			temp = temp->next;
		while ((*a)->value != min && pos-- > stack_size(*a) / 2)
			rra(a, 1);
		while ((*a)->value != min)
			ra(a, 1);
		pb(a, b, 1);
	}
}

void sort_small(t_stack **a, t_stack **b)
{
	int size;
	size = stack_size(*a);

	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else
	{
		push_smallest(a, b, size);
	}
}
