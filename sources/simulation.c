/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 04:22:43 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/23 13:56:53 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		usleep(philo->table->tt_sleep);
		// print_status(philo, " is sleeping");
	}
	// while (1337)
	// {
		thinking(philo);
		take_fork(philo);
		eating(philo);
		release_fork(philo);
		// sleeping();
	// }
	return (NULL);
}

void	start_simulation(t_table *table)
{
	int	i;

	i = -1;
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
