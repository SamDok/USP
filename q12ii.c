#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
(void)signal(SIGINT,SIG_IGN);
int count=0;
while(1)
{
printf("Hello World\n");
count++;
if(count>10)
(void)signal(SIGINT,SIG_DFL);
sleep(1);
}
}

