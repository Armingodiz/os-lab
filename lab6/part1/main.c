#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

// student num = 9831055 ==> count = 5
#define count 5
#define threads_count 5

int buffer = 0;
pthread_mutex_t lock;

void *reader(void *vargp)
{
    int* temp = (int *)vargp;
    int id = *temp;
    while (1){
        if (buffer >= count)
            break;   
        pthread_mutex_lock(&lock);
        printf("\nPID Reader: %d, buffer count: %d", id, buffer);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
}

void *writer(void *vargp){
    int* temp = (int *)vargp;
    int id = *temp;
    while (1){
        if (buffer >= count)
            break;
        pthread_mutex_lock(&lock);
        buffer++;
        printf("\nPID Writer: %d, buffer count: %d", id, buffer);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
}

int main()
{
    srand(time(NULL));
    pthread_t tid[threads_count];
    int rand_number;
    for (int i = 0; i < threads_count; i++) {
        if (i%2 == 0)
            pthread_create(&tid[i], NULL, writer, (void *)&tid[i]);
        else 
            pthread_create(&tid[i], NULL, reader, (void *)&tid[i]);
    }
    for (int i = 0; i < threads_count; i++)
        pthread_join(tid[i], NULL);
}