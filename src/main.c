/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:37:13 by kskender          #+#    #+#             */
/*   Updated: 2025/05/22 18:59:48 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_data data;
	int size;

	if (argc < 2)
		return (0);
	data.a = NULL;
	data.b = NULL;
	parse_args(&data, argc, argv);
	if (is_sorted(data.a))
	{
		free_stack(&data.a);
		free_stack(&data.b);
		return (0);
	}
	size = stack_size(data.a);
	if (size <= 3)
		sort_two(&data.a);
	else
		sort_big(&data.a, &data.b);
	free_stack(&data.a);
	free_stack(&data.b);
	return (0);
}
