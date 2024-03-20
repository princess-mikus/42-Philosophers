/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:35:20 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/03/20 11:43:06 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	mutex;

// PhiBROsophers
void	*think(void	*arguments)
{
	struct timeval	t_eval_start;
	struct timeval	t_eval_end;
	time_t			time_start;
	time_t			time_end;
	t_arguments		*args;

	args = arguments;
	printf("I'm thinkin' bro\n");
	gettimeofday(&t_eval_start, NULL); // START OF THE FUNCTION
	usleep(args->time_to_sleep * 1000);
	gettimeofday(&t_eval_end, NULL);
	time_start = t_eval_start.tv_sec * 1000 + t_eval_start.tv_usec / 1000;
	time_end = t_eval_end.tv_sec * 1000 + t_eval_end.tv_usec / 1000;
	printf("I stopped thinkin', I thought for %ld miliseconds bro\n",  time_end - time_start);
	return (NULL);
}

void	execute_simulation(t_arguments *args, t_philosopher *philo_list)
{
	unsigned int	i;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (args->max_eats == 0 || i++ <= args->max_eats)
	{
		pthread_create(&philo_list->thread, NULL, think, args);
		pthread_join(philo_list->thread, NULL);
		philo_list = philo_list->next;
	}
	pthread_mutex_destroy(&mutex);
}
