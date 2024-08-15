/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:54:28 by souaouri          #+#    #+#             */
/*   Updated: 2024/08/09 17:54:01 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_out_of_range(long num)
{
	if ((num > INT_MAX))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	is_valid(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str && str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str && str[i] == '+')
		i++;
	if (str && str[i] == '-')
		parsing_error("please enter a positive parametre");
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			parsing_error("The parameter must contain numbers only");
		i++;
	}
}

long ft_atoi_long(char *str)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	if (!str)
		return (0);
	is_valid(str);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		if (check_out_of_range(num))
			parsing_error("parametre is out of the range");
		i++;
	}
	return (num);
}
