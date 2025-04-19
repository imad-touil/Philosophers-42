/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:38:42 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/19 04:11:30 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	// eating(philo->id);
	// taking_forks();
	// sleeping();
	// thinking();
	printf("Heloo, Routine From philoID: %d\n", philo->id);
	sleep(1);
	return (NULL);
}

long	get_time_ms()
{
	long	ms;
	struct	timeval tv;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

static void init_philos(t_table table)
{
	int	i;

	i = -1;
	while (++i < table.phil_nbr)
		pthread_mutex_init(&table.forks[i], NULL);
	i = -1;
	while (++i)
	{
		table.philos[i].id = i;
		table.philos[i].t_last_meal = get_time_ms();
	}
}

int	init_table(int ac, char **av, t_table *table)
{
	table->phil_nbr = ft_atoi(av[1]);
	table->tt_die = ft_atoi(av[2]);
	table->tt_eat = ft_atoi(av[3]);
	table->tt_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->eat_count = ft_atoi(av[5]);
	else
		table->eat_count = -1;
	if (table->phil_nbr > 200)
		return (printf("%sEnter Valid Philosophers Numbers%s\n", RED, RESET), 1);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->phil_nbr);
	if (!table->forks)
		return (perror("Failed On Table Forks"), 1);
	table->philos = malloc(sizeof(t_philo) * table->phil_nbr);
	{
		free(table->forks);
		return (perror("Failed On Table Phils"), 1);
	}
	return (0);
}
