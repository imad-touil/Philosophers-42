/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 04:22:43 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/19 05:30:30 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	// eating(philo->id);
	// taking_forks();
	// sleeping();
	// thinking();
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
		pthread_create(&table->philos[i].thread, NULL, routine, &table->philos[i]);
		
	}
	i = -1;
	while (++i < table->phil_nbr)
	{
		printf("%d\n", i);
		pthread_join(table->philos[i].thread, NULL);
	}
	printf("DebuG, %i", table->phil_nbr);
}