#include "apue.h"
#include "error.c"

int loop = 0;

int main(void)
{

	char *c;
	
	while( (fgets(c,100, stdin)) != NULL)
	{
		loop++;
		// if(fputs(c,stdout) == EOF)
		// 	err_sys("output error");
	}	
	if(ferror(stdin))
		err_sys("input error");

	printf("%d", loop);
	exit(0);
}