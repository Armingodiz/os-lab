#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void reverse_chars(char *str){
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
}

int main(){
    int pipe1[2], bytes1;
    int pipe2[2], bytes2;
    pid_t pid;
    char buff[80];
    char message[50] = {
        "Hi, My name is Armin",
    };
    pipe(pipe1);
    pipe(pipe2);
    if ((pid = fork()) == -1){ // handle fork err
        perror("fork");
        exit(1);
    }
    if (pid != 0){
        // Parent process
        close(pipe1[1]); // closes write side 
        close(pipe2[0]); // closes read side 
        bytes1 = read(pipe1[0], buff, sizeof(buff));
        buff[bytes1] = '\0';
        reverse_chars(buff);
        write(pipe2[1], buff, (strlen(buff) + 1));
        buff[0] = '\0';
    }else{
        // Child process
        close(pipe1[0]); // closes read side 
        close(pipe2[1]); // closes write side
        printf("message sent to pipe1: %s\n", message);
        write(pipe1[1], message, (strlen(message) + 1));
        char temp[80];
        bytes2 = read(pipe2[0], temp, sizeof(temp));
        temp[bytes2] = '\0';
        printf("message recived from pipe2: %s\n", temp);
        exit(0);
    }
    return (0);
}