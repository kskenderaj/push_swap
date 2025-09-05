/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:08:34 by kskender          #+#    #+#             */
/*   Updated: 2025/05/29 16:40:18 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

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

void	sort_four(t_data *data)
{
	bring_min_to_top(&data->a);
	pb(&data->a, &data->b, 1);
	sort_three(&data->a);
	pa(&data->a, &data->b, 1);
}

void	sort_five(t_data *data)
{
	bring_min_to_top(&data->a);
	pb(&data->a, &data->b, 1);
	bring_min_to_top(&data->a);
	pb(&data->a, &data->b, 1);
	sort_three(&data->a);
	pa(&data->a, &data->b, 1);
	pa(&data->a, &data->b, 1);
}
