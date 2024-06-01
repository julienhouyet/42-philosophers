/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:27:03 by jhouyet           #+#    #+#             */
/*   Updated: 2024/06/01 12:56:24 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <stdatomic.h>
# include <sys/time.h>

enum	e_action
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIED
};

typedef struct s_data
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	monit;
	pthread_mutex_t	eat;
	int				dead;
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	time_t			time_start;
	int				num_times_each_philosopher_must_eat;
	atomic_int		eat_verif;
	struct s_philo	*philo;
}				t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	atomic_long		last_meal;
	int				left_fork;
	int				right_fork;
	int				num_eat;
	t_data			*data;
}				t_philo;

void	ft_check_death(t_data *data, int i);
void	ft_monitoring(t_data *data);

void	*ft_routine_philo(void *p);
int		ft_init_philo(t_data *data);
void	ft_init_fork(t_data *data);

time_t	ft_get_current_time(t_data *data);
void	ft_sleep(t_data *data, time_t finish);

void	print(int id, t_data *data, int code);
void	*ft_safe_calloc(size_t count, size_t size, char *error_message);
int		ft_atoi(const char *str);

int		ft_parse_arguments(int argc, char **argv, t_data *data);

void	ft_exit(t_data *data);

#endif