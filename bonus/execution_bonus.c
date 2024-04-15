/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:35:20 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/04/13 15:55:36 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
	pid_t			pid;
	t_philosopher	*philo;
	i = 0;
	philo = *philo_list;
	philo->args->simulation_start = get_current_time();
	while (i++ < philo->args->philo_number)
	{
		pid = fork();
		if (!pid)
		{
			philo->pid = pid;
			routine(philo);
			return (0);
		}
		philo = philo->next;
	}
	waitpid(-1, NULL, 0);
	i = 0;
	while (i++ < philo->args->philo_number)
	{
		kill(philo->pid, SIGTERM);
		philo = philo->next;
	}
	free_things(philo->args, philo);
}
