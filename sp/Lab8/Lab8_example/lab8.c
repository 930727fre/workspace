#include <stdio.h>
#include "apue.h"



void accumulation(int d_sum);

int main()
{
	printf("hi");
	FILE* sum;
	int total_sum=0, temp;
	pid_t pid[5];
	int year=5, week=52, day=7;
	char str[100];
	printf("hi");
	sum = fopen("sum.txt", "w");
	fprintf(sum, "%d\n", 0);
	fclose(sum);

	/**********************************************************/
	//Implement your code.
	for(int i=0;i<year;i++){
		pid[i]=fork();
		printf("hi");		
		if(pid[i]<0){
			err_sys("fork error");
		}
		else if(pid[i]==0){
			total_sum=0;
			printf("hi");			
			for(int j=0;j<week;j++){
				printf("hi");
				sprintf(str,"%d-%d.txt",i,j);
				FILE*  fp=fopen("str","r");
				for(int k=0;k<day;k++){
					for(int l=0;l<16;l++){
						fscanf(fp, "%d",&temp);
						printf("%d\n",temp);
						total_sum+=temp;
					}
				}
			}
			accumulation(temp);
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
