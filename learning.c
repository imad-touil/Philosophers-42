#include <pthread.h>
#include <stdio.h>

void *print_hello(void *arg) {
	(void)arg;
    printf("Hello from the thread!\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, print_hello, NULL);
    // pthread_join(thread, NULL);  // Wait for the thread to finish
    printf("Thread has finished\n");
    return 0;
}
