/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:40:52 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/13 19:43:02 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

struct s_philo t_philo;

typedef struct s_table
{
	int			phil_nbr;
	int			tt_die;
	int			tt_eat;
	int			tt_sleep;
	int			eat_time_nbr;
	t_philo		*philos;
	pthread_mutex_t	*forks;
}			t_table;

typedef struct s_philo
{
	int		id;
	int		left_fork;
	int		right_fork;
	long	t_last_meal;
	t_table	table;
}			t_philo;

int	ft_atoi(char *arg);

#endif