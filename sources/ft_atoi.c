/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:05:04 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/23 13:14:25 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *arg)
{
	int					i;
	unsigned long long	r;

	i = 0;
	r = 0;
	if (arg[i] == '+')
	{
		if (!arg[1])
			return (-1);
		i++;
	}
	while (arg[i])
	{
		r = r * 10 + arg[i] - 48;
		if (r > INT_MAX)
			return (-1);
		i++;
	}
	return (r);
}
