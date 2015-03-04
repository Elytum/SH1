#include <stdlib.h>
#include <stdio.h>

void ignore( int sig )
{            
    write (0, "A\n", 2); // Print a new line
    // This function does nothing except ignore ctrl-c
}

int main()
{           
	char input[1];

    // For ctrl-c
	signal(SIGINT, ignore);
//    signal( SIGINT, ignore );
    read(1, input, 1);
	printf("Leaving\n");
    return 0;
}
