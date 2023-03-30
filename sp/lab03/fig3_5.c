#include "apue.h"
#include <fcntl.h>
#include <unistd.h>
#include "error.c"
#define	BUFFSIZE	4096


int main(void)
{
		int		n;
		char	buf[BUFFSIZE];
		int fd;
		fd=open("/dev/null",O_WRONLY);

		while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
				if (write(fd, buf, n) != n)
						err_sys("write error");
				fsync(fd);
		if (n < 0)
				err_sys("read error");
		close(fd);

		exit(0);
}

