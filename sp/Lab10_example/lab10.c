#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

void put_pull_rod(int signum);
void fish_eating();
void exit_game(int signum);

int fishNum = 0;	// counting fish number
int boolean = 0;	// used as a boolean

int main(void){

	struct sigaction sig_put_pull_rod;
	sig_put_pull_rod.sa_handler = put_pull_rod;
	
	struct sigaction sig_exit_game;
	sig_exit_game.sa_handler = exit_game;

	//write your code here
    
	return 0;
}


void put_pull_rod(int signum){	
}

void fish_eating(){
}

void exit_game(int signum){
	printf("\nTotally caught fishes: %d\n", fishNum);
	exit(0);
}

