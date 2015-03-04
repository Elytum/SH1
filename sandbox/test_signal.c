#include<stdio.h>
#include<signal.h>  // for handling signal 

void signal_handler() 
{
    printf("Signal Handled here\n");
}

main() 
{
    printf("In main function..\n");

    // SIGINT is signal name create  when Ctrl+c will pressed 
    signal(SIGINT,signal_handler);  

//    sleep(15);

    printf("In main after called from signal_handle \n");

}
