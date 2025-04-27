/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:52:35 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/27 10:47:35 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect);
	philo->t_last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->table->protect);
	print_status(philo, " is eating");
	usleep(philo->table->tt_eat * 1000);
	pthread_mutex_lock(&philo->table->protect);
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->table->protect);
}
