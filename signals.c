#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int count_alarm = 0;
int count_seconds = 0;

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{ 
  printf("Turing was right!\n");
  alarm(1);
  count_alarm++;


}
void ctrlc_handlr(int signum) {
    printf("\nTotal alarms occurred: %d\n", count_alarm);
    printf("Seconds executed: %d\n", count_seconds);
    exit(0);
}
int main(int argc, char * argv[])
{
    signal(SIGALRM,handler); //register handler to handle SIGALRM
    signal(SIGINT, ctrlc_handlr);
    alarm(1); // Schedule the first alarm after 1 second

    while(1)
    {
    printf("Hello World!\n");
    sleep(1); //1 second 
    count_seconds++;
    
    } 
}
