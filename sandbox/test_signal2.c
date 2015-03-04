#include <stdio.h>
#include <stdlib.h>

void sighandler(int signum)
{
    printf("Caught signal %d, coming out...\n", signum);
//  exit(1);
}

int main()
{
	signal(SIGINT, sighandler);
	printf("Going to sleep for a second...\n");
	sleep(10);

	return(0);
}
