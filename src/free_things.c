/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:20:44 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/03/12 14:22:25 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_list(t_philosopher *list)
{
	t_philosopher	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
}

void	free_things(t_arguments *arguments, t_philosopher *philo_list)
{
	free(arguments);
	free_list(philo_list);
}