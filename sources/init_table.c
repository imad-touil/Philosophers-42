/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:38:42 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/18 05:55:17 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_table(int ac, char **av, t_table *table, t_philo *philo)
{
	int	i;
	int	num;

	i = -1;
	num = ft_atoi(av[1]);
	while (++i < num)
		philo[i].id = i;
	table->phil_nbr = num;
	num = ac;
	printf("From init_table\n");
}
