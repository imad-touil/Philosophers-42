/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:26:26 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/19 03:43:43 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isdigit(unsigned char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	valid_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (av[i][0] == '\0')
			return (0);
		else if (av[i][0] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j++]))
				return (0);
		}
		if (ft_atoi(av[i]) == -1)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_table	*tab;
	t_philo	*philo;

	if ((ac != 5 && ac != 6) || !valid_args(ac, av))
		return (printf("%s", USAGE), 0);
	tab = malloc(sizeof(t_table));
	philo = malloc(sizeof(t_philo));
	if (!init_table(ac, av, tab))
		return (1);
	if (ac == 6)
	{
		printf("%d\n", ft_atoi(av[5]));
		int	i = 0;
		while (i < ft_atoi(av[1]))
			printf("philosopher id: %d\n", philo[i++].id);
	}
	return (0);
}
