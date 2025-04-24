/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 04:22:43 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/24 13:13:10 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect);
	if (get_time_ms() - philo->t_last_meal > philo->table->tt_die)
	{
		philo->table->sim_end = 1;
		printf("%lld %d died\n", get_time_ms() - philo->table->start_time, philo->id);
	}
	if (philo->table->sim_end == 1)
	{
		pthread_mutex_unlock(&philo->table->protect);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->protect);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(philo->table->tt_sleep * 1000);
	if (is_died(philo))
		return (NULL);
	while (1337)
	{
		thinking(philo);
		take_fork(philo);
		if (is_died(philo))
			return (NULL) ;
		eating(philo);
		release_fork(philo);
		if (is_died(philo))
			return (NULL) ;
		sleeping(philo);
		if (is_died(philo))
			return (NULL) ;
	}
	return (NULL);
}

void	start_simulation(t_table *table)
{
	int	i;

	i = -1;
	table->start_time = get_time_ms();
	while (++i < table->phil_nbr)
	{
		pthread_create(&table->philos[i].thread,
			NULL, routine, &table->philos[i]);
	}
	i = -1;
	while (++i < table->phil_nbr)
		pthread_join(table->philos[i].thread, NULL);
	printf("DeBuG🐞, %i\n", table->phil_nbr);
}
