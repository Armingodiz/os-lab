#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>
#include <math.h>

void printHistogram(int *hist){
    for (int i = 0; i < 25; i++){
        for (int j = 0; j < hist[i]; j++){
            printf("*");
        }
        printf("\n");
    }
}

int do_round(){
    int counter = 0;
    for (int j = 0; j < 12; j++){
        int r = rand() % 101;
        if (r >= 49){
            counter++;
        }
        else{
            counter--;
        }
    }
    return counter;
}

int main(int argc, char *argv[])
{
    int ORDER = atoi(argv[1]);

    clock_t begin = clock();

    srand(time(NULL));

    int hist[25];

    for (int i = 0; i < 25; i++)
    {
        hist[i] = 0;
    }

    for (int i = 0; i < ORDER; i++)
    {
        int counter = do_round();
        hist[counter + 12]++;
    }

    printHistogram(hist);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time: %f seconds\n", time_spent);
    return 0;
}