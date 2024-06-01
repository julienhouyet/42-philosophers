/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:31:14 by jhouyet           #+#    #+#             */
/*   Updated: 2024/05/02 08:35:41 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_sleep(t_data *data, time_t finish)
{
	time_t	morning;

	morning = ft_get_current_time(data) + finish;
	while (data->dead != 1)
	{
		if (ft_get_current_time(data) >= morning)
			break ;
		usleep(200);
	}
}

time_t	ft_get_current_time(t_data *data)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)) - data->time_start);
}
