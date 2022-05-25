#include<stdio.h>

struct Process {
  int arrival;
  int burst;
  int start;
  int end;
} processes[100];

int main(){
    int n, passedTime = 0;
    printf("Enter number of the process\n");
    scanf("%d", &n);
    printf("Enter Arrival time and Burst time of the process\n");
    printf("arrival time\tburst time\n");
    for(int i = 0; i < n; i++){
        scanf("%d%d",&processes[i].arrival, &processes[i].burst);
    }
    for(int i = 0; i < n; i++){
        if(processes[i].arrival > passedTime){
             passedTime += processes[i].arrival - passedTime;
        }
        processes[i].start = passedTime;
        processes[i].end = passedTime + processes[i].burst;
        passedTime += processes[i].burst;
    }
    
    printf("Process \t\t start time \t\t end time\n");
    for(int i = 0; i < n; i++){
        printf("%d\t\t\t  %d\t\t\t %d\n", i, processes[i].start, processes[i].end);
    }
    return 0;
} 
