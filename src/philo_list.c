/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:34:15 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/03/15 13:02:01 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    add_to_philo_list(t_philosopher **list, int number)
{
    t_philosopher	*new_philo;
	t_philosopher	*current;
	int				i;

	new_philo = malloc(sizeof(t_philosopher));
	new_philo->id = number;
	new_philo->next = *list;
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

t_philosopher    *init_philosophers(int philo_number)
{
	int				i;
	t_philosopher	*philo_list;

	i = 0;
	philo_list = NULL;
	while (++i <= philo_number)
		add_to_philo_list(&philo_list, i);
	return (philo_list);
}