/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:40:51 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/04/02 15:16:17 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	add_to_philo_list(t_philosopher **list, int number, t_arguments **args)
{
	t_philosopher	*new_philo;
	t_philosopher	*current;
	int				i;
	bool			dead;

	dead = false;
	new_philo = malloc(sizeof(t_philosopher));
	new_philo->id = number;
	new_philo->next = *list;
	new_philo->last_meal = 0;
	new_philo->args = *args;
	pthread_mutex_init(&new_philo->fork, NULL);
	if (!*list)
		*list = new_philo;
	else
	{
		i = -1;
		current = *list;
		while (++i < number - 2)
			current = current->next;
		current->next = new_philo;
	}
}

t_philosopher	*init_philosophers(int philo_number, t_arguments **args)
{
	int				i;
	t_philosopher	*philo_list;

	i = 0;
	philo_list = NULL;
	while (++i <= philo_number)
		add_to_philo_list(&philo_list, i, args);
	return (philo_list);
}
