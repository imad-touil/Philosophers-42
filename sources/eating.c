/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:52:35 by imatouil          #+#    #+#             */
/*   Updated: 2025/06/28 15:03:31 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect);
	philo->t_last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->table->protect);
	print_status(philo, "is eating");
	percise_sleep(philo->table->tt_eat);
	pthread_mutex_lock(&philo->table->protect);
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->table->protect);
}
