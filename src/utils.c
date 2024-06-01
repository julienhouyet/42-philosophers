/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:31:16 by jhouyet           #+#    #+#             */
/*   Updated: 2024/05/02 08:36:04 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	print(int id, t_data *data, int code)
{
	if (code == EAT)
	{
		pthread_mutex_lock(&data->eat);
		data->philo[id - 1].last_meal = ft_get_current_time(data);
		pthread_mutex_unlock(&data->eat);
	}
	pthread_mutex_lock(&data->print);
	if (code == EAT && !data->dead)
	{
		if (data->philo[id].num_eat == \
		data->num_times_each_philosopher_must_eat)
			data->eat_verif++;
		printf("%ld %d %s\n", ft_get_current_time(data), id, \
		"is eating");
	}
	if (code == FORK && !data->dead)
		printf("%ld %d %s\n", ft_get_current_time(data), id, \
		"has taken a fork");
	if (code == SLEEP && !data->dead)
		printf("%ld %d %s\n", ft_get_current_time(data), id, \
		"is sleeping");
	if (code == THINK && !data->dead)
		printf("%ld %d %s\n", ft_get_current_time(data), id, \
		"is thinking");
	pthread_mutex_unlock(&data->print);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = s;
	i = 0;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*b;
	size_t	s;
	size_t	verif;

	verif = count * size;
	if (size != verif / count)
		return (0);
	s = (count * size);
	b = malloc(count * size);
	if (b != NULL)
	{
		ft_bzero(b, s);
		return (b);
	}
	else
		return (0);
}

void	*ft_safe_calloc(size_t count, size_t size, char *error_message)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
	{
		perror("Error allocating memory for : ");
		printf("%s", error_message);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	long int		result;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
		if (result * neg < INT_MIN)
			return (0);
		if (result * neg > INT_MAX)
			return (-1);
	}
	return ((int)result * neg);
}
