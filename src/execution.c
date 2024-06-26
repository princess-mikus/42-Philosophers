/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:35:20 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/04/13 14:05:29 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*checker(void *philo)
{
	t_philosopher	*current_ph;
	time_t			current;
	struct timeval	time;

	current_ph = philo;
	ft_usleep(current_ph->args->time_to_die);
	while (current_ph->args->philos_eaten < current_ph->args->philo_number)
	{
		gettimeofday(&time, NULL);
		current = time.tv_sec * 1000 + time.tv_usec / 1000;
		if (current - current_ph->last_meal >= \
		current_ph->args->time_to_die / 1000)
		{
			pthread_mutex_lock(&current_ph->args->sim_status);
			current_ph->args->stop = true;
			break ;
		}
		current_ph = current_ph->next;
	}
	pthread_mutex_unlock(&current_ph->args->sim_status);
	print_event("die", current_ph, time);
	return (NULL);
}

time_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	execute_simulation(t_philosopher **philo_list)
{
	unsigned int	i;
	t_philosopher	*philo;
	pthread_t		watcher;

	i = 0;
	philo = *philo_list;
	philo->args->simulation_start = get_current_time();
	while (i++ < philo->args->philo_number)
	{
		pthread_create(&philo->thread, NULL, routine, philo);
		philo = philo->next;
	}
	pthread_create(&watcher, NULL, checker, philo);
	i = 0;
	while (i++ < philo->args->philo_number)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
	pthread_detach(watcher);
}
