/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 08:18:02 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/23 13:50:10 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	release_fork(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_unlock(&table->forks[philo->left_fork]);
	pthread_mutex_unlock(&table->forks[philo->right_fork]);
}

void	take_fork(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&table->forks[philo->left_fork]);
		print_status(philo, " has taken a fork");
		pthread_mutex_lock(&table->forks[philo->right_fork]);
		print_status(philo, " has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&table->forks[philo->right_fork]);
		print_status(philo, " has taken a fork");
		pthread_mutex_lock(&table->forks[philo->left_fork]);
		print_status(philo, " has taken a fork");
	}
}
