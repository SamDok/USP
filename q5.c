#include <signal.h>
#include <stdio.h>
#include <unistd.h>
struct sigaction new_sig;

void gotit(int sig)
{
printf("Got the signal!!!\n");
new_sig.sa_handler = SIG_DFL;
sigaction(SIGINT,&new_sig,0);
}

int main()
{
new_sig.sa_flags=0;
sigemptyset(&new_sig.sa_mask);
sigaddset(&new_sig.sa_mask, SIGINT);
new_sig.sa_handler = gotit;

sigaction(SIGINT,&new_sig,0);

while(1)
{
printf("Hello World\n");
sleep(1);
}
}

