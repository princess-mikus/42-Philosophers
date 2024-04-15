/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:10:09 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/04/13 15:47:15 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_table(t_philosopher *philo_list)
{
	t_philosopher	*current;

	current = philo_list;
	while (current)
	{
		printf("PHILOSOPHER: %d\n", current->id);
		current = current->next;
	}
	printf("\n");
}

t_arguments	*parse_input(int argc, char	**argv)
{
	int			i;
	int			k;
	t_arguments	*arguments;

	i = 0;
	arguments = malloc(sizeof(t_arguments));
	while (argv[++i])
	{
		k = -1;
		while (argv[i][++k])
			if (argv[i][k] < '0' || argv[i][k] > '9')
				return (free(arguments), NULL);
	}
	arguments->philo_number = ft_atoui(argv[1]);
	arguments->time_to_die = ft_atoui(argv[2]) * 1000;
	arguments->time_to_eat = ft_atoui(argv[3]) * 1000;
	arguments->time_to_sleep = ft_atoui(argv[4]) * 1000;
	arguments->max_eats = 0;
	arguments->stop = false;
	arguments->philos_eaten = 0;
	sem_init(arguments->sim_status, 1, 0);
	sem_init(arguments->forks, 1, arguments->philo_number);
	if (argc == 6)
		arguments->max_eats = ft_atoui(argv[5]);
	return (arguments);
}

int	main(int argc, char **argv)
{
	t_arguments		*arguments;
	t_philosopher	*philo_list;

	if (argc < 5 || argc > 6)
		return (0);
	arguments = parse_input(argc, argv);
	if (arguments == NULL)
		return (0);
	philo_list = init_philosophers(arguments->philo_number, &arguments);
	if (arguments->philo_number == 1)
		one_sim(&philo_list);
	else
		execute_simulation(&philo_list);
	free_things(arguments, philo_list);
}
