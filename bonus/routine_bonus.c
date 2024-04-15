/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:32:03 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/04/13 14:45:10 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	pthink(t_philosopher *philo)
{
	struct timeval	event;

	gettimeofday(&event, NULL);
	print_event("think", philo, event);
}

void	psleep(t_philosopher *philo)
{
	struct timeval	event;

	gettimeofday(&event, NULL);
	print_event("sleep", philo, event);
	ft_usleep(philo->args->time_to_sleep);
}

void	peat(t_philosopher *philo)
{
	struct timeval	event;

	pthread_mutex_lock(&philo->fork);
	if (philo->args->stop)
		return ;
	gettimeofday(&event, NULL);
	print_event("fork", philo, event);
	if (philo->args->stop)
		return ;
	pthread_mutex_lock(&philo->next->fork);
	gettimeofday(&event, NULL);
	print_event("fork", philo, event);
	gettimeofday(&event, NULL);
	philo->last_meal = print_event("eat", philo, event);
	ft_usleep(philo->args->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	*routine(void *philo)
{
	t_philosopher	*current;
	unsigned int	eats;

	current = philo;
	eats = 0;
	current->last_meal = current->args->simulation_start;
	if (current->id % 2)
		ft_usleep(current->args->time_to_eat);
	while ((current->args->max_eats == 0 || eats < current->args->max_eats) \
	&& !current->args->stop)
	{
		peat(current);
		eats++;
		if ((eats < current->args->max_eats || !current->args->max_eats) \
		&& !current->args->stop)
		{
			psleep(current);
			if (!current->args->stop)
				pthink(current);
		}
	}
	current->args->philos_eaten++;
	return (NULL);
}
