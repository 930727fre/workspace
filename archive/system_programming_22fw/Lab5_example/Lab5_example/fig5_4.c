#include "apue.h"
#include "error.c"

int loop = 0;

int main(void)
{

	int c;
	
	while( (c = getc(stdin)) != EOF )
	{
		loop++;
		if(putc(c,stdout) == EOF)
			err_sys("output error");
	}	
	if(ferror(stdin))
		err_sys("input error");

	printf("%d", loop);
	exit(0);
}
