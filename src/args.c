/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:52:12 by jhouyet           #+#    #+#             */
/*   Updated: 2024/06/01 12:56:00 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_is_numeric(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_numeric(argv[i]))
		{
			printf("Error: Argument %d is not a valid number\n", i);
			return (1);
		}
		if (ft_atoi(argv[i]) <= 0 && i != 6)
		{
			printf("Error: Argument %d must be a positive number\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_parse_arguments(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		return (printf("Error: Wrong number of arguments\n"));
	if (ft_validate_args(argc, argv) != 0)
		return (1);
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->eat_verif = 0;
	data->dead = 0;
	if (argc == 6)
		data->num_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		data->num_times_each_philosopher_must_eat = -1;
	data->time_start = 0;
	return (0);
}
