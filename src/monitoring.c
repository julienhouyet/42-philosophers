/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:40:29 by jhouyet           #+#    #+#             */
/*   Updated: 2024/06/01 12:56:46 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_check_death(t_data *data, int i)
{
	if ((ft_get_current_time(data) - data->philo[i].last_meal) > \
	data->time_to_die)
	{
		pthread_mutex_lock(&data->monit);
		if (data->dead == 0)
		{
			printf("%u %d %s\n", (unsigned int)(ft_get_current_time(data) \
			- data->philo[i].last_meal), data->philo[i].id, "died");
			data->dead = 1;
		}
		pthread_mutex_unlock(&data->monit);
		pthread_mutex_unlock(&data->eat);
		return ;
	}
}

void	ft_monitoring(t_data *data)
{
	int	i;

	while (data->dead != 1 && data->eat_verif <= data->num_philos)
	{
		i = -1;
		while (++i < data->num_philos)
		{
			pthread_mutex_lock(&data->eat);
			if (data->eat_verif == data->num_philos)
			{
				pthread_mutex_unlock(&data->eat);
				return ;
			}
			ft_check_death(data, i);
			pthread_mutex_unlock(&data->eat);
		}
	}
	return ;
}
