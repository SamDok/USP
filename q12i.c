#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void gotit(int sig)
{
printf("Got the signal!!!\n");
(void)signal(SIGINT,SIG_DFL);
}

int main()
{
(void)signal(SIGINT,gotit);

while(1)
{
printf("Hello World\n");
sleep(1);
}
}

