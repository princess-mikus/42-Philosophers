/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:20:44 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/04/13 14:52:03 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	free_things(t_arguments *arguments, t_philosopher *philo_list)
{
	unsigned int	i;
	t_philosopher	*next;

	i = 0;
	while (++i <= arguments->philo_number)
	{
		pthread_mutex_destroy(&philo_list->forks);
		next = philo_list->next;
		free(philo_list);
		philo_list = next;
	}
	pthread_mutex_destroy(&arguments->sim_status);
	free(arguments);
}
