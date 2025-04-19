/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 04:22:43 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/19 06:07:28 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	sleep(1);
	printf("Hello From: %d\n", philo->id);
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
		pthread_join(table->philos[i].thread, NULL);
	}
	printf("DebuG, %i\n", table->phil_nbr);
}
