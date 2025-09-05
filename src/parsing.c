/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:48:21 by kskender          #+#    #+#             */
/*   Updated: 2025/06/03 18:10:41 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (-1);
		str++;
	}
	return (1);
}

int	has_duplicate(t_stack *stack, int num)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->value == num)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	validate_args(t_data *data, char *arg)
{
	long	num;

	if (is_valid(arg) < 0)
		exit_error(data);
	num = ft_atol(arg);
	if (num < INT_MIN || num > INT_MAX)
		exit_error(data);
	if (has_duplicate(data->a, (int)num))
		exit_error(data);
}

void	parse_args(t_data *data, int argc, char **argv)
{
	char	**args;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		if ((argv[1][0] == '-' || argv[1][0] == '+') && argv[1][1] == '\0')
			write(2, "Error\n", 6);
		args = ft_split(argv[i], ' ');
		if (!args || !*args)
			exit_error(data);
		j = 0;
		while (args[j])
		{
			validate_args(data, args[j]);
			add_to_stack(&data->a, ft_atoi(args[j]));
			j++;
		}
		free_split(args);
		i++;
	}
}
