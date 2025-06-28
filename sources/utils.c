/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:36:10 by imatouil          #+#    #+#             */
/*   Updated: 2025/06/28 16:05:10 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	clean_up()
// {
	
// }

void	percise_sleep(int time)
{
	long long	t;

	t = get_time_ms();
	while (get_time_ms() - t < time)
		usleep(100);
}

int	is_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect);
	if (philo->table->sim_end == 1)
	{
		pthread_mutex_unlock(&philo->table->protect);
		return (1);
	}
	if (get_time_ms() - philo->t_last_meal > philo->table->tt_die)
	{
		philo->table->sim_end = 1;
		printf("%lld %d died\n", get_time_ms() - philo->table->start_time,
			philo->id);
		pthread_mutex_unlock(&philo->table->protect);
	}
	pthread_mutex_unlock(&philo->table->protect);
	return (0);
}

int	check_death(t_table *table)
{
	pthread_mutex_lock(&table->protect);
	if (table->sim_end)
	{
		pthread_mutex_unlock(&table->protect);
		return (1);
	}
	pthread_mutex_unlock(&table->protect);
	return (0);
}

void	monitor(t_table *table)
{
	int		i;

	while (!check_death(table))
	{
		i = -1;
		while (++i < table->phil_nbr && !check_death(table))
			is_died(&table->philos[i]);
	}
	usleep(1000);
}
