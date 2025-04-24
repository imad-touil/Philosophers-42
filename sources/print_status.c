/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:54:49 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/24 16:46:27 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_status(t_philo *philo, char *status)
{
	// pthread_mutex_lock(&philo->table->protect);
	if (!philo->table->sim_end)
		printf("%lld %d %s\n", get_time_ms() - philo->table->start_time, philo->id, status);
	// pthread_mutex_unlock(&philo->table->protect);
}
