#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

void put_pull_rod(int signum);
void fish_eating();
void exit_game(int signum);
void alrm_handler(int signum);


int fishNum = 0;	// counting fish number
int boolean = 0;	// used as a boolean

int main(void){

	struct sigaction sig_put_pull_rod;
	memset(&sig_put_pull_rod, 0, sizeof sig_put_pull_rod);
	sig_put_pull_rod.sa_handler = put_pull_rod;
	
	struct sigaction sig_exit_game;
	memset(&sig_exit_game, 0, sizeof sig_exit_game);
	sig_exit_game.sa_handler = exit_game;

	//write your code here
	struct sigaction sig_alrm;
	memset(&sig_alrm, 0, sizeof sig_alrm);
	sig_alrm.sa_handler = alrm_handler;
	srand(time(NULL));
	if(sigaction(SIGINT,&sig_put_pull_rod, NULL)==-1){
		perror("put_pull_rod sigaction fault\n");
	}
	if(sigaction(SIGTSTP,&sig_exit_game, NULL)==-1){
		perror("sig_exit_rod sigaction fault\n");
	}
	if(sigaction(SIGALRM, &sig_alrm,NULL)==-1){
		printf("sig_alrm sigaction fault\n");
	}
	printf("Fishing rod is ready!\n");	
	while(1){
		pause();
		printf("\nput the fishing rod\n");
		printf("Bait into water, waiting fish...\n");		
		int sec = rand()%2+1;
		int remaining = alarm(sec);
		pause();
		// printf("remaining = %d\n",remaining);
		if(remaining>0){
			printf("Pull the fishing rod\n");
			continue;
		}
		printf("A fish is biting, pull the fishing rod\n");
		remaining = alarm(4);
		pause();
		printf("remaining = %d\n",remaining);
		if(remaining>0){
			printf("Catch a fish!!\n");
			fish_eating();
		}
		else{
			boolean=0;
			printf("The bait was eaten!!\n");
		}			
	}
    
	return 0;
}


void put_pull_rod(int signum){
	if(boolean==0){
		boolean=1;
	}
	else{
		boolean=0;
	}
}

void fish_eating(){
	fishNum++;
	printf("Totally caught fishes: %d\n", fishNum);

}

void exit_game(int signum){
	printf("\nTotally caught fishes: %d\n", fishNum);
	exit(0);
}

void alrm_handler(int signum){
	// printf("ihef\n");
}