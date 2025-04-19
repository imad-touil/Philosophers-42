/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:38:42 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/19 07:48:47 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time_ms(void)
{
	long			ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

static void	init_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->phil_nbr)
		pthread_mutex_init(&table->forks[i], NULL);
	i = -1;
	while (++i < table->phil_nbr)
	{
		table->philos[i].id = i;
		table->philos[i].t_last_meal = get_time_ms();
		table->philos[i].table = table;
		table->philos[i].left_fork = i;
		table->philos[i].right_fork = (1 + i) % table->phil_nbr;
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
	if (!table->philos)
	{
		free(table->forks);
		return (perror("Failed On Table Phils"), 1);
	}
	init_philos(table);
	printf("Good Luck\n");
	return (0);
}
