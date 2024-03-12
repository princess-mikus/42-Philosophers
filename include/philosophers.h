/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:23:11 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/03/12 15:52:02 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

t_philosopher	*init_philosophers(int philo_number);

void	        execute_simulation(t_arguments *args, t_philosopher *philo_list);

void			free_things(t_arguments *arguments, t_philosopher *philo_list);

/* UTILS */
unsigned int	ft_atoui(const char *str);
size_t			ft_strlen(const char *str);