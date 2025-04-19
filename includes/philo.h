/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:40:52 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/19 04:04:56 by imatouil         ###   ########.fr       */
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

# define RED "\e[31m"
# define RESET "\e[0m"
# define USAGE RED "Usage: \n./philo <nbr_philo> <time_to_die> \
<time_to_eat> <time_to_sleep> [eat_count]\n" RESET

typedef struct s_table
{
	int				phil_nbr;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				eat_count;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
}			t_table;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			left_fork;
	int			right_fork;
	long		t_last_meal;
	t_table		*table;
}				t_philo;

int	ft_atoi(char *arg);
int	init_table(int ac, char **av, t_table *table);

#endif