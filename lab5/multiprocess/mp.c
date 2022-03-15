#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_PROC 100

typedef struct{
    int histArr[25];
} Hist;

Hist *sharedHist;

int segment_id;
int root_pid;
int current_pid;

void printHistogram(int *hist){
    for (int i = 0; i < 25; i++){
        for (int j = 0; j < hist[i]; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int ORDER = atoi(argv[1]);

    clock_t begin = clock();
    srand(time(0));
    segment_id = shmget(IPC_PRIVATE, sizeof(Hist), IPC_CREAT | 0666);

    root_pid = getpid();
    
    for(int i = 0; i < MAX_PROC ; i++){
        if (getpid() == root_pid)
            current_pid = fork();
        else
            break;
    }

    sharedHist = (Hist *)shmat(segment_id, NULL, 0);

    if (getpid() != root_pid){
        int count, sample;
        for(int i = 0; i< ORDER/MAX_PROC; i++){
            count = 0;
            for(int j = 0; j< 12; j++){
                sample = rand()%101;
                if (sample >= 49)
                    count++;
                else
                    count--;
            }
            sharedHist->histArr[count + 12]++;
        }
        exit(0);
    }
    else{
        for(int i = 0; i < MAX_PROC; i++){
            wait(NULL);
        }
    }

    printHistogram(sharedHist->histArr);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time: %f seconds\n", time_spent);
    return 0;
}