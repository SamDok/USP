#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxline 2000
int main()
{
int n,int1,int2;
char line[maxline];
while((n=read(STDIN_FILENO, line,maxline))>0)
{
line[n]=0;
if(sscanf(line,"%d%d",&int1,&int2)==2)
{
sprintf(line,"%d\n",int1+int2);
n=strlen(line);
if(write(STDOUT_FILENO,line,n)!=n)
printf("write error");
}
else
{
if(write(STDOUT_FILENO,"invalid arg\n",13)!=13)
printf("write error");
}}
exit(0);
}

