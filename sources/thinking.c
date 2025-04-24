/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 07:50:52 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/24 16:35:34 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->table->tt_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	print_status(philo, "is thinking");
}
