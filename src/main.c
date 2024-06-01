/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:25:59 by jhouyet           #+#    #+#             */
/*   Updated: 2024/06/01 12:56:33 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_join_thread(t_data *data)
{
	int	i;

	i = -1;
	while (data->philo && ++i < data->num_philos)
		pthread_join(data->philo[i].thread, NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;
	int			i;

	if (ft_parse_arguments(argc, argv, &data) != 0)
		return (1);
	ft_init_philo(&data);
	ft_init_fork(&data);
	i = -1;
	while (++i < data.num_philos)
	{
		if (pthread_create(&data.philo[i].thread, NULL, \
		ft_routine_philo, (void *)&data.philo[i]))
			return (ft_exit(&data), 1);
	}
	ft_sleep(&data, 10);
	ft_monitoring(&data);
	ft_join_thread(&data);
	return (ft_exit(&data), 0);
}
