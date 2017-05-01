#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void timer_handler(int signo)
{
	printf("pid : %d timer recd\n", getpid());
}

int main()
{
	int pid;
	printf("parent pid : %d\n", getpid());
	signal(SIGALRM, timer_handler);
	alarm(5);
	if(execl("/bin/sleep", "sleep", "20", (void*)0) < 0)
	{
		perror("execl"); exit(1);
	}
}

