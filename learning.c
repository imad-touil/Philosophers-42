// #include <pthread.h>
// #include <stdio.h>

// void *print_hello(void *arg) {
// 	(void)arg;
//     printf("Hello from the thread!\n");
//     return NULL;
// }

// int main() {
//     pthread_t thread;
//     pthread_create(&thread, NULL, print_hello, NULL);
//     // pthread_join(thread, NULL);  // Wait for the thread to finish
//     printf("Thread has finished\n");
//     return 0;
// }


// #include <pthread.h>
// #include <stdio.h>
// #include <unistd.h>

// void *do_work(void *arg) {
// 	(void)arg;
//     sleep(1);
//     printf("Detached thread work done\n");
//     return NULL;
// }

// int main() {
//     pthread_t thread;
//     pthread_create(&thread, NULL, do_work, NULL);
//     pthread_detach(thread);  // No need to join
//     printf("Main thread ends (may finish before detached thread)\n");
//     sleep(2); // Give time to detached thread
//     return 0;
// }


#include <pthread.h>
#include <stdio.h>

int counter = 0;
pthread_mutex_t lock;

void *increment(void *arg) {
	(void)arg;
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    printf("Final counter value: %d\n", counter);
    return 0;
}

