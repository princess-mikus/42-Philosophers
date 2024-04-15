/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   philosophers.h									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: fcasaubo <fcasaubo@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/03/12 14:23:11 by fcasaubo		  #+#	#+#			 */
/*   Updated: 2024/04/02 13:34:18 by fcasaubo		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "structures_bonus.h"
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <signal.h>

t_philosopher	*init_philosophers(int philo_number, t_arguments **args);
void			one_sim(t_philosopher **philo_list);
void			execute_simulation(t_philosopher **philo_list);
time_t			print_event(char *event, t_philosopher *philo, \
				struct timeval event_time);
void			free_things(t_arguments *arguments, t_philosopher *philo_list);
void			*routine(void *philo);

/* UTILS */
unsigned int	ft_atoui(const char *str);
size_t			ft_strlen(const char *str);
bool			ft_compare(char *str, char *str2);
void			ft_usleep(unsigned int ms);
