#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
int main()
{
char msg[25]="";
mkfifo("fifo1",0600);
int fd;
fd=open("fifo1",O_RDONLY);
printf("\nMessage sent from client is \n");
while(read(fd,msg,25))
{
printf("%s",msg);
}
}

