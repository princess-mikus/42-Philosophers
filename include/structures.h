/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:31:12 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/04/02 15:16:02 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>

typedef struct s_arguments
{
	unsigned int		philo_number;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	unsigned int		max_eats;
	unsigned int		philos_eaten;
	bool				stop;
	time_t				simulation_start;
	pthread_mutex_t		print;
}	t_arguments;

typedef struct s_philosopher
{
	unsigned int			id;
	time_t					last_meal;
	pthread_t				thread;
	pthread_mutex_t			fork;
	t_arguments				*args;
	struct s_philosopher	*next;
}	t_philosopher;
