#include <pthread.h>

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

#include <time.h>


int * resource;
int * resource_remain;
int ** remaining_request, ** resources_in_use;
int deadlock_check_time, resource_count, thread_count, resolution_method, deadlock_count;



pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
time_t curr_time, start_time;

void * thread_init(void * arg) {
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    int thread_num = * (int * ) arg;
    while (1) {
        int fulfilled=0;
        int to_fulfill=0;
        printf("A worker thread is started/reinitiated \n");
        for (int i = 0; i < resource_count; i++){ 
            remaining_request[thread_num][i] = rand() % (resource[i]+1);
            if(remaining_request[thread_num][i]) to_fulfill++;
        }
        while (fulfilled<to_fulfill) {
            int resource_num = rand() % resource_count;
            if (!remaining_request[thread_num][resource_num]) {
                continue;
            }
            float sleep_time  = ((float) rand() / RAND_MAX )* deadlock_check_time;
            sleep(sleep_time);
            
            pthread_mutex_lock( & mutex);
            if (resource_remain[resource_num] >= remaining_request[thread_num][resource_num]) {
                resources_in_use[thread_num][resource_num] = resources_in_use[thread_num][resource_num] + remaining_request[thread_num][resource_num];
                resource_remain[resource_num] = resource_remain[resource_num] - remaining_request[thread_num][resource_num];
                remaining_request[thread_num][resource_num] = 0;
                fulfilled++;
            } 
            else {
                resources_in_use[thread_num][resource_num] =resources_in_use[thread_num][resource_num] + resource_remain[resource_num];
                remaining_request[thread_num][resource_num] =remaining_request[thread_num][resource_num] - resource_remain[resource_num];
                resource_remain[resource_num] = 0;
            }
            pthread_mutex_unlock( & mutex);
            
            if (fulfilled == to_fulfill) {
                printf("Worker thread %d resources fulfilled\n", thread_num);
                float sleep_time = deadlock_check_time * (0.7 + ((0.8 * ((float) rand() / RAND_MAX))));
                sleep(sleep_time);
                pthread_mutex_lock( & mutex);
                for (int j = 0; j < resource_count; j++) {
                    resources_in_use[thread_num][j] = 0;
                    resource_remain[j] =resource_remain[j] + resources_in_use[thread_num][j];
                }
                pthread_mutex_unlock( & mutex);
                printf("Worker thread %d moving to next\n", thread_num);
                break;
            }
        }
    }
    pthread_mutex_unlock( & mutex);
}

int deadlock_checker(int arr1[], int completed[]) {
    int complete_count = 0;
    for (int i = 0; i < resource_count; i++) {
        arr1[i] = resource_remain[i];
    }
    for (int i = 0; i < thread_count; i++) {
        int j;
        for (j = 0; j < resource_count; j++) {
            if (remaining_request[i][j] > arr1[j])
                break;
        }
        if (j == resource_count) {
            for (int k = 0; k < resource_count; k++) {
                arr1[k] += resources_in_use[i][k];
            }
            completed[i] = 1;
            complete_count++;
        }
    }
    return complete_count;
}

void * dead_thread_init(void * args) {
    pthread_t * thread = (pthread_t * ) args;
    while (1) {
        time( & curr_time);
        int arr1[resource_count];
        int completed[thread_count];
        int complete_temp[thread_count];
        int complete_count = 0;

        memset(completed, 0, sizeof(completed));
        sleep(deadlock_check_time);
        pthread_mutex_lock( & mutex);

        complete_count = deadlock_checker(arr1, completed);
        if (complete_count < thread_count-1) {
            deadlock_count++;
            printf("\nA deadlock is found. Number of times deadlock detected: %d\n Time is: %ld.\nThe threads in deadlock are: ", deadlock_count, curr_time-start_time);
            for (int i = 0; i < thread_count; i++) {
                if (!completed[i]) {
                    printf("%d ", i);
                }
            }
            if (resolution_method == 1) {
                printf("\nAttempting to resolve by method 1\n");
                for (int i = 0; i < thread_count; i++) {
                    if (!completed[i]) {
                        for (int j = 0; j < resource_count; j++) {
                            resource_remain[j] += resources_in_use[i][j];
                            resources_in_use[i][j] = 0;
                        }
                        pthread_cancel(thread[i]);
                        int * thread_num = (int * ) malloc(sizeof(int));
                        * thread_num = i;
                        pthread_create( & thread[i], NULL, thread_init, thread_num);
                    }
                }
            }
            else{
                printf("\nAttempting to resolve by method 2\n");
                int total_resources[thread_count];
                memset(total_resources, 0, sizeof(total_resources));
                int replace[thread_count];
                memset(replace, 0, sizeof(replace));

                for (int i = 0; i < thread_count; i++) {
                    // int temp=0;
                    for (int j = 0; j < resource_count; j++) {
                        total_resources[i]+= resources_in_use[i][j];
                    }
                    // total_resources[i]=temp;
                }

                do {
                    int max_res = 0;
                    for (int i = 1; i < thread_count; i++) {
                        if (total_resources[i] > total_resources[max_res])
                            max_res = i;
                    }
                    // if(max_res==0) break;
                    printf("Thread eliminated %d\n", max_res);
                    replace[max_res] = 1;
                    total_resources[max_res] = 0;

                    for (int j = 0; j < resource_count; j++) {
                        resource_remain[j] =resource_remain[j] + resources_in_use[max_res][j];
                        resources_in_use[max_res][j] = 0;
                    }
                    pthread_cancel(thread[max_res]);
                    int * thread_num = (int * ) malloc(sizeof(int));
                    * thread_num = max_res;
                    pthread_create( & thread[max_res], NULL, thread_init, thread_num);
                    memset(complete_temp, 0, sizeof(complete_temp));
                    complete_count = deadlock_checker(arr1, complete_temp);
                    printf("Complete count %d\n", complete_count);
                } while (complete_count < thread_count);
            }
        } 
        else {
            printf("No deadlock found at time %ld\n", curr_time-start_time);
        }
        pthread_mutex_unlock( & mutex);
    }
}
