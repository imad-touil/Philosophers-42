/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:38:42 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/19 00:21:08 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(int	id)
{
	printf("timestamp_in_ms %d is eating |---| ", id);
}

void	*routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	eating(philo->id);
	// taking_forks();
	// sleeping();
	// thinking();
	printf("Heloo, Routine From philoID: %d\n", philo->id);
	sleep(1);
	return (NULL);
}

void	init_table(int ac, char **av, t_table *table, t_philo *philo)
{
	int	i;
	int	num;

	num = ft_atoi(av[1]);
	table->phil_nbr = num;
	i = -1;
	while (++i < num)
	{
		philo[i].id = i;
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		pthread_join(philo[i].thread, NULL);
	}
	printf("From init_table\n");
	ac = num;
}
