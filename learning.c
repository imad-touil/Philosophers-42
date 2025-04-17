/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:07:06 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/17 04:13:06 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*myturn(void *arg)
{
	(void)arg;
	// while (1337)
	// {
	// 	printf("My Turn!\n");
	// 	sleep(1);
	// }
	return (NULL);
}

void	urturn()
{
	// (void)arg;
	// while (1337)
	for (int i = 0; i < 4; i++)
	{
		printf("Your Turn!\n");
		sleep(2);
	}
	// return (NULL);
}
	

int	main(void)
{
	pthread_t	thread;
	
	// myturn();
	pthread_create(&thread, NULL, myturn, NULL);
	pthread_join(thread, NULL);
	urturn();
	pthread_detach(thread);
}
