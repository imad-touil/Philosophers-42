/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 07:50:52 by imatouil          #+#    #+#             */
/*   Updated: 2025/05/02 11:55:17 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping");
	percise_sleep(philo->table->tt_sleep);
}

void	thinking(t_philo *philo)
{
	print_status(philo, "is thinking");
	usleep(100);
}
