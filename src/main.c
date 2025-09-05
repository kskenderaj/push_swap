/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:37:13 by kskender          #+#    #+#             */
/*   Updated: 2025/05/29 16:37:18 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	free_if_sorted(t_data *data)
{
	if (is_sorted(data->a))
	{
		free_stack(&data->a);
		free_stack(&data->b);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		size;

	if (argc < 2)
		return (0);
	data.a = NULL;
	data.b = NULL;
	parse_args(&data, argc, argv);
	if (free_if_sorted(&data))
		return (0);
	size = stack_size(data.a);
	if (size == 2)
		sort_two(&data.a);
	else if (size == 3)
		sort_three(&data.a);
	else if (size == 4)
		sort_four(&data);
	else if (size == 5)
		sort_five(&data);
	else
		sort_big(&data.a, &data.b);
	free_stack(&data.a);
	free_stack(&data.b);
	return (0);
}
