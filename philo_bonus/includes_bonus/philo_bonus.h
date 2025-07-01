/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:29:42 by imatouil          #+#    #+#             */
/*   Updated: 2025/06/30 16:43:54 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>
# include <pthread.h>

# define RED "\e[31m"
# define RESET "\e[0m"
# define USAGE "Usage: \n./philo <nbr_philo> <time_to_die> \
<time_to_eat> <time_to_sleep> [eat_count]\n"

typedef struct s_philo
{
	int				id;
	pid_t			pid;
	long			last_meal;
	int				meals_counter;
	struct t_table	*table;
}					t_philo;

typedef struct s_table
{
	int			philo_count;
	int			tt_die;
	int			tt_eat;
	int			tt_sleep;
	int			eat_count;
	long long	start_time;
	int			stop;
	t_philo		*philos;
	sem_t		*forks;
	sem_t		*write_lock;
	sem_t		*meal_check;
}			t_table;

#endif