/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:35:20 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/03/12 15:53:49 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// PhiBROsophers
void	*think(void	*arguments)
{
	int				time_start;
	int				time_end;	
	t_arguments		*args;

	args = arguments;
	time_start = gettimeofday(t_eval, t_zone);
	printf("I'm thinkin' bro\n");
	sleep(args->time_to_sleep);
	time_end = gettimeofday(t_eval, t_zone);
	printf("I stopped thinkin', I thought for %d seconds bro\n", time_end - time_start);
	return (NULL);
}

void	execute_simulation(t_arguments *args, t_philosopher *philo_list)
{
	if (!args)
		return ;
	pthread_create(&philo_list->thread, NULL, think, args);
	pthread_join(philo_list->thread, NULL);
	pthread_create(&philo_list->next->thread, NULL, think, args);
	pthread_join(philo_list->next->thread, NULL);
}
