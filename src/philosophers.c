/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:31:11 by jhouyet           #+#    #+#             */
/*   Updated: 2024/06/01 12:57:20 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	eat(t_philo *philo, int id)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork[philo->left_fork]);
	print(philo->id, data, FORK);
	if (data->num_philos == 1)
	{
		ft_sleep(data, data->time_to_die);
		printf("%u %d %s\n", (unsigned int)(ft_get_current_time(data)), id, \
		"\033[0;31mdied\033[0m");
		data->dead = 1;
		pthread_mutex_unlock(&(data->fork[philo->left_fork]));
		return ;
	}
	pthread_mutex_lock(&data->fork[philo->right_fork]);
	print(philo->id, data, FORK);
	print(philo->id, data, EAT);
	data->philo[id - 1].num_eat++;
	ft_sleep(data, data->time_to_eat);
	pthread_mutex_unlock(&(data->fork[philo->left_fork]));
	pthread_mutex_unlock(&(data->fork[philo->right_fork]));
}

void	*ft_routine_philo(void *p)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)p;
	data = philo->data;
	if (philo->id % 2 == 0)
		ft_sleep(data, data->time_to_eat / 2);
	while (data->dead != 1 || data->eat_verif >= data->num_philos)
	{
		eat(philo, philo->id);
		if (philo->num_eat == data->num_times_each_philosopher_must_eat)
			data->eat_verif++;
		print(philo->id, data, SLEEP);
		ft_sleep(data, data->time_to_sleep);
		print(philo->id, data, THINK);
		if (data->eat_verif >= data->num_philos)
			return (NULL);
	}
	return (NULL);
}

void	ft_init_fork(t_data *data)
{
	int	i;

	data->fork = ft_safe_calloc(data->num_philos, sizeof(pthread_mutex_t), \
	"Callo Fork");
	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (ft_exit(data));
	}
	if (pthread_mutex_init(&(data->print), NULL))
		return (ft_exit(data));
	if (pthread_mutex_init(&(data->monit), NULL))
		return (ft_exit(data));
	if (pthread_mutex_init(&(data->eat), NULL))
		return (ft_exit(data));
	data->dead = 0;
}

int	ft_init_philo(t_data *data)
{
	int	i;

	i = -1;
	data->philo = ft_safe_calloc(data->num_philos, sizeof(t_philo), \
	"Calloc Philo");
	while (++i < data->num_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].last_meal = 0;
		data->philo[i].num_eat = 0;
		data->philo[i].left_fork = i;
		if (data->num_philos > 1)
			data->philo[i].right_fork = (i + 1) % data->num_philos;
		data->philo[i].data = data;
	}
	data->time_start = ft_get_current_time(data);
	return (0);
}
