#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
int main()
{
char msg[100]="";
int fd;
fd=open("fifo1",O_WRONLY);
printf("\nEnter the message to be sent to server:");
scanf("%s",msg);
write(fd,msg,strlen(msg));
}

