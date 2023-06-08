#include <stdio.h>
#include "apue.h"


void accumulation(int d_sum);

int main()
{
	FILE* sum;
	int total_sum=0, temp;
	pid_t pid[5];
	int year=5, week=52, day=7;
	char str[100];
	sum = fopen("sum.txt", "w");
	fprintf(sum, "%d\n", 0);
	fclose(sum);

	/**********************************************************/
	//Implement your code.
	TELL_WAIT();
	for(int i=0;i<year;i++){
		pid[i]=fork();	
		if(pid[i]<0){
			err_sys("fork error");
		}
		else if(pid[i]==0){
			total_sum=0;
			for(int j=0;j<week;j++){
				if(j+1<10){
					sprintf(str,"%d-0%d.txt",i+1,j+1);
				}
				else{
					sprintf(str,"%d-%d.txt",i+1,j+1);					
				}
				
				FILE*  fp=fopen(str,"r");
				for(int k=0;k<day;k++){
					for(int l=0;l<96;l++){
						fscanf(fp, "%d",&temp);
						total_sum+=temp;
					}
				}
				fclose(fp);
			}
			accumulation(total_sum);
			TELL_PARENT(getppid());
		}
		else{
			WAIT_CHILD();
		}
	}

	/**********************************************************/

	sum = fopen("sum.txt", "r");
	fscanf(sum, "%d", &total_sum);
	printf("Day_Average = %d\n",total_sum/(year*week*day));
	fclose(sum);

	return 0;
}

void accumulation(int d_sum)    //Accumulating the daily sum to "sum.txt".
{
	FILE* sum;
	int tmp=0;

	sum = fopen("sum.txt", "r+");
	fscanf(sum, "%d", &tmp);

	tmp += d_sum;

	rewind(sum);
	fprintf(sum, "%d", tmp);
	fclose(sum);

	return;
}
