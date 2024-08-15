/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:15:24 by souaouri          #+#    #+#             */
/*   Updated: 2024/08/15 11:25:04 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return ;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

size_t my_gettime(void)
{
	struct timeval time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_printf(t_times *times, char *str, int id)
{
	if (times->dead)
		return ;
	pthread_mutex_lock(&times->print);
	printf ("%ld\t%d\t%s\n",my_gettime() - times->start, id, str);
	pthread_mutex_unlock(&times->print);
}

void	ft_usleep(t_times *times, int time)
{
	size_t	start;
	
	start = my_gettime();
	while (my_gettime() - start < (size_t)time && !times->dead)
		usleep(500);
}