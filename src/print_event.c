/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:38:24 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/04/02 15:07:32 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

time_t	print_event(char *event, \
t_philosopher *philo, struct timeval event_time)
{
	static time_t	start = 0;
	time_t			time;

	pthread_mutex_lock(&philo->args->print);
	time = event_time.tv_sec * 1000 + event_time.tv_usec / 1000;
	if (!start)
		start = time;
	if (ft_compare(event, "fork") && !philo->args->stop)
		printf("%ld\t | philosopher %d has taken a fork\n", \
		time - start, philo->id);
	else if (ft_compare(event, "eat") && !philo->args->stop)
		printf("%ld\t | philosopher %d is eating\n", time - start, philo->id);
	else if (ft_compare(event, "sleep") && !philo->args->stop)
		printf("%ld\t | philosopher %d is sleeping\n", time - start, philo->id);
	else if (ft_compare(event, "think") && !philo->args->stop)
		printf("%ld\t | philosopher %d is thinking\n", time - start, philo->id);
	else if (ft_compare(event, "die") && !philo->args->stop)
		printf("%ld\t | philosopher %d has died\n", time - start, philo->id);
	pthread_mutex_unlock(&philo->args->print);
	return (time);
}
