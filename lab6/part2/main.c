#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define time_quentum 2
#define philosopher_count 5

pthread_t philosophers[philosopher_count];
pthread_mutex_t chopstick[philosopher_count];

void eat(int id){
    printf("\nPhilosopher %d is hungry !", id);
    pthread_mutex_lock(&chopstick[id]);
    pthread_mutex_lock(&chopstick[(id + 1) % philosopher_count]);
    printf("\nPhilosopher %d is eating using chopstick[%d] and chopstrick[%d] !!", id, id, (id + 1) % PHILOSOPHER);
    pthread_mutex_unlock(&chopstick[id]);
    pthread_mutex_unlock(&chopstick[id + 1 % philosopher_count]);
    sleep(1);
}
void think(int id){
    printf("\nPhilosopher %d is thinking !!", id);
    sleep(2);
}
void* philosopher(void* vargp){
    int* temp = (int *)vargp;
    int id = *temp;
    int i = 0;
    while (i < time_quentum){
        think(id);
        eat(id);
        i++;
    }
}
int main(){
    for (int i = 0; i < philosopher_count; i++)
        pthread_create(&philosophers[i], NULL, philosopher, (void *)&i);

    for (int i = 0; i < philosopher_count; i++)
        pthread_join(philosophers[i], NULL);
}