/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_protect_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:43:10 by souaouri          #+#    #+#             */
/*   Updated: 2024/08/11 12:39:53 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../philo.h"

// void	mutex_checker(int status, t_code code)
// {
// 	if (EINVAL == status && (LOCK == code || UNLOCK == code))
// 		mutex_error("The value specified by mutex is invalid.");
// 	if (EINVAL == status && INIT == code)
// 		mutex_error("The value specified by attr is invalid.");
// 	if (EDEADLK == status)
// 		mutex_error("A deadlock would occur if the thread blocked waiting for mutex.");
// 	if (EPERM == status)
// 		mutex_error("The current thread does not hold a lock on mutex.");
// 	if (EBUSY == status)
// 		mutex_error(" Mutex is locked.");
// 	if (ENOMEM == status)
// 		mutex_error("The process cannot allocate enough memory to create another mutex.");
// }

// void	thread_checker(int status, t_code code)
// {
// 	if (EAGAIN == status)
// 		thread_error("The system lacked the necessary resources to create another thread");
// 	if (EPERM == status)
// 		thread_error("The caller does not have appropriate permission");
// 	if (EINVAL == status && code == CREATE)
// 		thread_error("The value specified by attr is invalid.");
// 	if (EINVAL == status && (code == JOIN || code == DETACH))
// 		thread_error("The implementation has detected that the value specified by thread does not refer to a joinable thread.");
// 	if (ESRCH == status)
// 		thread_error("No thread could be found corresponding to that specified by the given thread ID, thread.");
// 	if (EDEADLK == status)
// 		thread_error("A deadlock was detected or the value of thread specifies the calling thread");
// }

// void	protect_mutex(t_mtx *mutex, t_code code)
// {
// 	if (LOCK == code)
// 		mutex_checker(pthread_mutex_lock(mutex), code);
// 	else if (UNLOCK == code)
// 		mutex_checker(pthread_mutex_unlock(mutex), code);
// 	else if (INIT == code)
// 		mutex_checker(pthread_mutex_init(mutex, NULL), code);
// 	else if (DESTROY == code)
// 		mutex_checker(pthread_mutex_destroy(mutex), code);
// 	else
// 		mutex_error("mutex error !!");
// }

// void	protect_threads(pthread_t *thread, void *data, void *(*func)(void *), t_code code)
// {
// 	if (CREATE == code)
// 		thread_checker(pthread_create(thread, NULL, func, data), code);
// 	else if (JOIN == code)
// 		thread_checker(pthread_join(*thread, NULL), code);
// 	else if (DETACH == code)
// 		thread_checker(pthread_mutex_detach(*thread), code);
// 	else
// 		mutex_error("thread error !!");
// }
