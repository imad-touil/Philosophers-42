/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:26:26 by imatouil          #+#    #+#             */
/*   Updated: 2025/05/01 18:09:28 by imatouil         ###   ########.fr       */
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

	if (ac != 5 && ac != 6)
		return (printf("%s%s%s", RED, USAGE, RESET), 0);
	else if (!valid_args(ac, av))
		return (printf("%sInvalid Arguments\n%s", RED, RESET), 0);
	tab = malloc(sizeof(t_table));
	if (init_table(ac, av, tab))
		return (1);
	start_simulation(tab);
	return (0);
}

// TODO make it to write Just ../includes/philo.h <headers>
// TODO Data race; 
// TODO Sleep Function 
