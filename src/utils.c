/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:03:47 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/04/02 13:43:41 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

unsigned int	ft_atoui(const char *str)
{
	unsigned int	size;
	int				i;
	unsigned int	num;

	size = (unsigned int)ft_strlen(str);
	num = 0;
	i = -1;
	while ((unsigned int)++i < size)
	{
		num *= 10;
		num += str[i] - '0';
	}
	return (num);
}

bool	ft_compare(char *str, char *str2)
{
	int		i;

	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] != str2[i])
			return (false);
		i++;
	}
	return (true);
}

void	ft_usleep(unsigned int ms)
{
	time_t			start_time;
	time_t			current_time;
	struct timeval	stime;
	struct timeval	ctime;

	gettimeofday(&stime, NULL);
	start_time = stime.tv_sec * 1000 + stime.tv_usec / 1000;
	current_time = start_time;
	while (current_time - start_time < ms / 1000)
	{
		gettimeofday(&ctime, NULL);
		current_time = ctime.tv_sec * 1000 + ctime.tv_usec / 1000;
		usleep(50);
	}
}
