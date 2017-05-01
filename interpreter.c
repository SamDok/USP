display.c

#include <stdio.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	int i;
	for(i=0;i<argc;i++)
	{
		printf("%s\n",argv[i]);
	}
	return 0;
}

driver.c

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	execl("interpreter","arg1","arg2","arg3",(char*)0);
	return 0;
}
textinterpreter

#! /home/guest1/echoarg my2

output:
cs6a17@msritcse:~/unix$ gcc display.c -o echoarg
cs6a17@msritcse:~/unix$ chmod 777 textinterpreter
cs6a17@msritcse:~/unix$ gcc driver.c
cs6a17@msritcse:~/unix$ ./a.out

