/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:30:48 by kskender          #+#    #+#             */
/*   Updated: 2025/05/22 18:50:58 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static int ft_isspace(int c)
// {
// 	return (c == ' ' || (c >= '\t' && c <= '\r'));
// }

// static const char *parse_sign(const char *str, int *sign)
// {
// 	*sign = 1;
// 	if (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			*sign = -1;
// 		str++;
// 	}
// 	return (str);
// }

// static int check_overflow(int digit, int sign, long result)
// {
// 	if (sign == 1 && result > (LONG_MAX - digit) / 10)
// 		return (1);
// 	if (sign == -1 && result < (LONG_MIN + digit) / -10)
// 		return (1);
// 	return (0);
// }

// long ft_strtol(const char *str, char **endptr)
// {
// 	long result;
// 	int sign;
// 	int digit;

// 	result = 0;
// 	while (ft_isspace(*str))
// 		str++;
// 	str = parse_sign(str, &sign);
// 	if (*str < '0' || *str > '9')
// 	{
// 		if (endptr)
// 			*endptr = (char *)str;
// 		return (0);
// 	}
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		digit = *str - '0';
// 		if (check_overflow(result, digit, sign))
// 			result = result * 10 + (*str - '0');
// 		str++;
// 	}
// 	if (endptr)
// 		*endptr = (char *)str;
// 	return (result * sign);
// }

long ft_atol(char *str)
{
	long num;
	int sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}
