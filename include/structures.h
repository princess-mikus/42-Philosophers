/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:31:12 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/03/12 15:17:41 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

typedef struct	s_philosopher
{
	unsigned int			id;
    pthread_t				thread;
    struct s_philosopher	*next;
}	t_philosopher;

typedef struct	s_arguments
{
	unsigned int		philo_number;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	unsigned int		max_eats;
}	t_arguments;
