/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:03:47 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/03/12 14:15:55 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_strlen(const char *str)
{
    int	size;

	size = 0;
	while(str[size])
		size++;
	return (size);
}

unsigned int ft_atoui(const char *str)
{
	unsigned int	size;
	int	i;
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