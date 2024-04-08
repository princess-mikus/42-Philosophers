/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:30:02 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/04/02 13:43:47 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*one_case(void *philo)
{
	struct timeval	event;
	t_philosopher	*current;

	current = philo;
	gettimeofday(&event, NULL);
	print_event("fork", current, event);
	ft_usleep(current->args->time_to_die);
	gettimeofday(&event, NULL);
	print_event("die", current, event);
	return (NULL);
}

void	one_sim(t_philosopher **philo_list)
{
	t_philosopher	*philo;

	philo = *philo_list;
	if (philo->args->philo_number == 1)
	{
		pthread_create(&philo->thread, NULL, one_case, philo);
		pthread_join(philo->thread, NULL);
		return ;
	}
}
