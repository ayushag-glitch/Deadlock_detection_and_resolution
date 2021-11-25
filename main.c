#include <pthread.h>

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

#include <time.h>

#include "utils.h"


int main(int argc, char * argv[]) {
    
    resource_count = atoi(argv[1]);
    if (argc != 5+resource_count) {
        printf("Check Number of Arguements\n");

        exit(-1);
    }
    resource = (int * ) malloc(sizeof(int) * resource_count);
    resource_remain = (int * ) malloc(sizeof(int * ) * resource_count);
    remaining_request = (int ** ) malloc(sizeof(int * ) * resource_count);
    for (int i = 0; i < resource_count; i++) {
        resource[i] = atoi(argv[i+2]);
        
    }
    for(int i=0; i<resource_count; i++){
        resource_remain[i] = resource[i];
    }
    thread_count = atoi(argv[2+resource_count]);
    deadlock_check_time = atoi(argv[3+resource_count]);
    resolution_method = atoi(argv[4+resource_count]);
    deadlock_count = 0;
    resources_in_use = (int ** ) malloc(sizeof(int * ) * thread_count);
    pthread_t * threads = (pthread_t * ) malloc(thread_count * sizeof(pthread_t));
    for (int i = 0; i < thread_count; ++i) {
        remaining_request[i] = (int * ) malloc(resource_count * sizeof(int));
    }
    for (int i = 0; i < thread_count; ++i) {
        resources_in_use[i] = (int * ) malloc(resource_count * sizeof(int));
    }
    
    time( & start_time);

    pthread_t deadlock_thread;
    pthread_create( & deadlock_thread, NULL, dead_thread_init, threads);
    int * y = (int * ) malloc(sizeof(int));

    for (int i = 0; i < thread_count; i++) {
        * y = i;
        pthread_create( & threads[i], NULL, thread_init, y);
    }
    pthread_join(deadlock_thread, NULL);
    return 0;

}