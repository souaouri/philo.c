/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:57:45 by souaouri          #+#    #+#             */
/*   Updated: 2024/08/11 12:17:53 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	parsing_error(char *str)
{
	ft_putstr_fd(RED"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n"RESET, 2);
	exit (EXIT_FAILURE);
}

int	mutex_error(char *str)
{
	ft_putstr_fd(RED"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n"RESET, 2);
	return (1);
}

int	thread_error(char *str)
{
	ft_putstr_fd(RED"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n"RESET, 2);
	return (1);
}