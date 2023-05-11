#include "apue.h"
#include "error.c"

int count = 0;

int main(void)
{

	int c;
    setvbuf(stdin,)
	while( (c = getc(stdin)) != EOF )
	{
		count++;
		if(putc(c,stdout) == EOF)
			err_sys("output error");
	}	
	if(ferror(stdin))
		err_sys("input error");

	printf("%d", count);
	exit(0);
}