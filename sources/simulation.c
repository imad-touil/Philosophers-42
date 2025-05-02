/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 04:22:43 by imatouil          #+#    #+#             */
/*   Updated: 2025/05/01 18:20:45 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	routine_helper(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	percise_sleep(philo->table->tt_sleep);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->phil_nbr == 1)
	{
		routine_helper(philo);
		return (NULL);
	}
	philo->t_last_meal = get_time_ms();
	if (philo->id % 2 == 0)
		percise_sleep(philo->table->tt_eat);
	while (!check_death(philo->table))
	{
		take_fork(philo);
		eating(philo);
		release_fork(philo);
		if (philo->table->eat_count != -1 && 
			philo->meal_counter >= philo->table->eat_count)
			break ;
		thinking(philo);
		percise_sleep(philo->table->tt_sleep);
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
	monitor(table);
	i = -1;
	while (++i < table->phil_nbr)
		pthread_join(table->philos[i].thread, NULL);
}
