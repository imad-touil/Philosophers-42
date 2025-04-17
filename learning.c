/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 06:17:11 by imatouil          #+#    #+#             */
/*   Updated: 2025/04/17 06:47:19 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ******** Purpose ************
// The Purpose of this test is to learn about the power of||
// pthread_mutex_lock and pthread_mutex_unlock ||

// #include <pthread.h>
// #include <stdio.h>
// #include <unistd.h>

// typedef struct s_test
// {
// 	pthread_mutex_t	lock;
// 	int				counter;
// }					t_test;

// // int counter = 0;
// // pthread_mutex_t lock;

// void *increment1(void *arg) {
// 	t_test	*mutex;
// 	mutex = (t_test*)arg;
//     for (int i = 0; i < 10; i++) {
//         pthread_mutex_lock(&mutex->lock);
//         mutex->counter++;
// 		printf("From 1: mutex->counter = %d\n", mutex->counter);
//         pthread_mutex_unlock(&mutex->lock);
// 		sleep(1);
//     }
//     return NULL;
// }
// void *increment2(void *arg) {
// 	t_test	*mutex;
// 	mutex = (t_test*)arg;
//     for (int i = 0; i < 10; i++) {
//         pthread_mutex_lock(&mutex->lock);
//         mutex->counter++;
// 		printf("From 2: mutex->counter = %d\n", mutex->counter);
//         pthread_mutex_unlock(&mutex->lock);
// 		sleep(1);
//     }
//     return NULL;
// }
// void *increment3(void *arg) {
// 	t_test	*mutex;
// 	mutex = (t_test*)arg;
//     for (int i = 0; i < 10; i++) {
//         pthread_mutex_lock(&mutex->lock);
//         mutex->counter++;
// 		printf("From 3: mutex->counter = %d\n", mutex->counter);
//         pthread_mutex_unlock(&mutex->lock);
// 		sleep(1);
//     }
//     return NULL;
// }

// int main() {
//     pthread_t t1, t2, t3;
// 	t_test	mutex;

// 	mutex.counter = 0;
//     pthread_mutex_init(&mutex.lock, NULL);

//     pthread_create(&t1, NULL, increment1, &mutex);
//     pthread_create(&t2, NULL, increment2, &mutex);
//     pthread_create(&t3, NULL, increment3, &mutex);

//     pthread_join(t1, NULL);
//     pthread_join(t2, NULL);
//     pthread_join(t3, NULL);

//     // pthread_mutex_destroy(&mutex.lock);

//     printf("Final counter value: %d\n", mutex.counter);
//     return 0;
// }
