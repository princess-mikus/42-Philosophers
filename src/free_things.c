/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:20:44 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/03/15 13:05:39 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_things(t_arguments *arguments, t_philosopher *philo_list)
{
	unsigned int	i;
	t_philosopher	*next;

	i = 0;
	while (++i <= arguments->philo_number)
	{
		next = philo_list->next;
		free(philo_list);
		philo_list = next;
	}
	free(arguments);
}