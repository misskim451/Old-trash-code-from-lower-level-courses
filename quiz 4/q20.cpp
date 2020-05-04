#include <iostream>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <errno.h>
using namespace std;

void signal_handler(int signo){
    printf("Got SIGUSR1\n");
}

int main(){
  //    signal(SIGUSR1, signal_handler);
    int pid = fork();
    if(pid==0){
        for(int i=0; i<5; ++i){
            kill(getppid(), SIGUSR1);
            sleep(1);
        }
    }else{
        wait(0);
    }
}
