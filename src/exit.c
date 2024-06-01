/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:30:54 by jhouyet           #+#    #+#             */
/*   Updated: 2024/05/02 08:32:00 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		if (i == 0)
		{
			pthread_mutex_destroy(&data->print);
			pthread_mutex_destroy(&data->monit);
			pthread_mutex_destroy(&data->eat);
		}
		if (&data->fork[i])
			pthread_mutex_destroy(&data->fork[i]);
	}
	if (data->fork)
		free(data->fork);
	if (data->fork)
		free(data->philo);
}
