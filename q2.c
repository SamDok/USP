#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int n,fd[2];
    char buf[30];
    pid_t pid;
    if(pipe(fd)==-1)
    {
    printf("error\n");
    exit(1);
    }
    pid=fork();
    if(pid<0)
        printf("fork error\n");

    if(pid>0)       /*parent */
    {
        close(fd[0]);
        write(fd[1],"hola!\n",7);
    }
    else
    {
        close(fd[1]);           /*child*/
        n=read(fd[0],buf,7);
        write(STDOUT_FILENO,buf,n);
        if(islower(buf[0]))
        {
            buf[0]=toupper(buf[0]);
            printf("Capitalized Letter is %c\n", buf[0]);
        }
        printf("%s", buf);
        write(STDOUT_FILENO,buf,n);
    }
    exit(0);
}

