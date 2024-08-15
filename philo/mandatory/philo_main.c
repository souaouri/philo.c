/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:10:06 by souaouri          #+#    #+#             */
/*   Updated: 2024/08/15 11:52:03 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_times(t_times *time, char **argv)
{
	time->num_of_philo = ft_atoi_long(argv[1]);
	time->time_to_die = ft_atoi_long(argv[2]);
	time->time_to_eat = ft_atoi_long(argv[3]);
	time->time_to_sleep = ft_atoi_long(argv[4]);
	if (argv[5])
		time->num_of_times_must_eat = ft_atoi_long(argv[5]);
	else
		time->num_of_times_must_eat = -1;
}

void	philo_and_fork_data(t_times *time)
{
	int	i;

	i = 0;
	while (i < time->num_of_philo)
	{
		if (pthread_mutex_init(&time->forks[i], NULL))
			mutex_error("///");
		i++;
	}
	i = 0;
	while (i < time->num_of_philo)
	{
		time->philos[i].table = time;
		time->philos[i].id = i + 1;
		time->philos[i].is_full = 0;
		time->philos[i].num_of_meals = 0;
		time->philos[i].time_of_last_meals = 0;
		if (pthread_mutex_init(&time->philos[i].lock_philo, NULL))
			mutex_error("///");
		time->philos[i].first_fork = time->forks[i];
		time->philos[i].sec_fork = time->forks[(i + 1) % time->num_of_philo];
		i++;
	}
}

int	ft_eating(t_philo *philo)
{
	t_times *times;

	times = philo->table;
	pthread_mutex_lock(&times->forks[philo->id - 1]);
	ft_printf(philo->table, "is taken a fork", philo->id);
	if (philo->table->num_of_philo == 1)
	{
		ft_usleep(philo->table, philo->table->time_to_die);
		return (0);
	}
	pthread_mutex_lock(&times->forks[philo->id % times->num_of_philo]);
	ft_printf(philo->table, "is taken a fork", philo->id);
	ft_printf(philo->table, "is eating", philo->id);
	philo->num_of_meals++;
	if (philo->num_of_meals == times->num_of_times_must_eat)
	{
		philo->is_full = 1;
		pthread_mutex_unlock(&times->forks[philo->id - 1]);
		pthread_mutex_unlock(&times->forks[philo->id % times->num_of_philo]);
		return (1);
	}
	pthread_mutex_lock(&philo->lock_philo);
	philo->time_of_last_meals = my_gettime();
	pthread_mutex_unlock(&philo->lock_philo);
	ft_usleep(philo->table ,philo->table->time_to_eat);
	pthread_mutex_unlock(&times->forks[philo->id - 1]);
	pthread_mutex_unlock(&times->forks[philo->id % times->num_of_philo]);
	return (0);
}

void	*moni_routine(void *content)
{
	t_times	*time;
	t_philo	*philo;
	int		i;
	
	time = (t_times*)content;
	philo = time->philos;
	while (!time->start)
		usleep (1000);
	while (1)
	{
		i = -1;
		while (++i < time->num_of_philo)
		{
			if (my_gettime() - (&philo[i])->time_of_last_meals >= (size_t)time->time_to_die)
			{
				if (!(&philo[i])->is_full)
				{
					ft_printf(time, "is died", (&philo[i])->id);
					time->dead = 1;
					return (NULL);
				}
			}
		}
		if (time->all_isfull)
			break ;	
	}
	return (NULL);
}

void	the_monitoring(t_times *times)
{
	pthread_t trm;
	if (pthread_create(&trm, NULL, moni_routine, times))
	{
		printf ("pthread_creat() failed\n");
	}
	if (pthread_detach(trm))
	{
		printf("pthread_detach() failed \n");
	}
}

void	*ft_Life_cycle(void	*content)
{
	t_philo	*philo;
	t_times *time;

	philo = (t_philo *)content;
	time = philo->table;
	philo->time_of_last_meals = my_gettime();
	if (philo->id == 2)
		time->start = my_gettime();
	if (philo->id % 2 != 0)
	{
		ft_printf(philo->table, "is thinking", philo->id);
		ft_usleep(philo->table, philo->table->time_to_eat);
	}
	while (1)
	{
		if (ft_eating(philo))
			break;
		ft_printf(philo->table, "is sleeping", philo->id);
		ft_usleep(philo->table ,philo->table->time_to_sleep);
		ft_printf(philo->table, "is thinking", philo->id);
		if (time->dead)
			break ;
	}
	return (NULL);
}

void	creat_thread(t_times *time)
{
	int	i;

	i = 0;
	while (i < time->num_of_philo)
	{
		pthread_create(&time->philos[i].thread, NULL, ft_Life_cycle, &time->philos[i]);
		i++;
	}
	i = 0;
	while (i < time->num_of_philo)
	{
		pthread_join(time->philos[i].thread, NULL);
		i++;
	}
	time->all_isfull = 1;
}

void	discover_the_table(t_times *times, char **argv)
{
	int	i;

	i = 0;
	take_times(times ,argv);
	if (pthread_mutex_init(&times->print, NULL) || pthread_mutex_init(&times->struct_times, NULL))
		mutex_error("///");
	times->start = 0;
	times->dead = 0;
	times->all_isfull = 0;
	times->cheker = 0;
	times->philos = malloc(sizeof(t_philo) * times->num_of_philo);
	times->forks = malloc(sizeof(pthread_mutex_t) * times->num_of_philo);
	philo_and_fork_data(times);
	the_monitoring(times);
	creat_thread(times);
}

int	main(int argc, char **argv)
{
	t_times	time;
	if (argc != 5 && argc != 6)
		parsing_error("Please enter the correct number of arguments");
	discover_the_table(&time, argv);
}
