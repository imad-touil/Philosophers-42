/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:52:35 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/24 16:44:22 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect);
	philo->t_last_meal = get_time_ms();
	philo->meal_counter++;
	print_status(philo, " is eating");
	philo->t_last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->table->protect);
	usleep(philo->table->tt_eat * 1000);
}
