/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:09:01 by souaouri          #+#    #+#             */
/*   Updated: 2024/08/15 11:44:59 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <errno.h>
# include <sys/time.h>


typedef struct s_addresses
{
	void				*content;
	struct s_addresses	*next;
}						t_addresses;

typedef struct s_philo t_philo;
typedef struct s_times t_times;

struct s_philo
{
	pthread_t			thread;
	int					id;
	int					is_full;
	int					num_of_meals;
	size_t				time_of_last_meals;
	pthread_mutex_t		first_fork;
	pthread_mutex_t		sec_fork;
	pthread_mutex_t		lock_philo;
	t_times				*table;
};

struct s_times
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_must_eat;
	int				all_isfull;
	pthread_mutex_t	struct_times;
	pthread_mutex_t	print;
	long			start;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	int				dead;
	int				cheker;
};

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"


void	ft_putstr_fd(char *str, int fd);
long	ft_atoi_long(char *str);

// errors
void	parsing_error(char *str);
int	mutex_error(char *str);
int	thread_error(char *str);


void	*ft_Life_cycle(void	*content);

// util
size_t 	my_gettime(void);
void	ft_printf(t_times *times, char *str, int id);
void	ft_usleep(t_times *times, int time);
// void	protect_mutex(t_mtx *mutex, t_code code);
// void	protect_threads(pthread_t *thread, void *data,
		//  void *(*func)(void *),  t_code code);


void    *my_alloc(size_t size, int free);

# endif