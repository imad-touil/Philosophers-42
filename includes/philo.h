/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:40:52 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/13 15:08:10 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <sys/time.h>

typedef struct s_philo
{
	int	phils_nbr;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	eat_time_nbr;
}		t_philo;

int	ft_atoi(char *arg);

#endif