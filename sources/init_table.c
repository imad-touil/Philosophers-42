/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:38:42 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/18 07:39:16 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	(void)arg;
	// think();
	// eat();
	// sleep();
	sleep(2);
	printf("Heloo, Routine From philoID: %d\n", 3);
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
		pthread_create(&philo[i].thread, NULL, routine, NULL);
		pthread_join(philo[i].thread, NULL);
	}
	printf("From init_table\n");
	ac = num;
}
