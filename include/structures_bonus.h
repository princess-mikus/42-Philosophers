/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:31:12 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/04/13 14:51:17 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <semaphore.h>

typedef struct s_arguments
{
	unsigned int		philo_number;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	unsigned int		max_eats;
	unsigned int		philos_eaten;
	time_t				simulation_start;
	sem_t				*forks;
	sem_t				*sim_status;
	bool				stop;
}	t_arguments;

typedef struct s_philosopher
{
	unsigned int			id;
	pid_t					pid;
	time_t					last_meal;
	t_arguments				*args;
	struct s_philosopher	*next;
}	t_philosopher;
