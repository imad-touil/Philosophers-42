/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:07:06 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/16 01:52:56 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	myturn(void)
{
	while (1337)
	{
		printf("My Turn!\n");
		sleep(1);
	}
}

void	urturn(void)
{
	while (1337)
	{
		printf("Your Turn!\n");
		sleep(2);
	}
}
	

int	main(void)
{
	myturn();
	urturn();
}
