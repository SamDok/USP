#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

pthread_t tidP[20],tidC;
sem_t full,empty,mutex;
int counter,m,k,buffersize;
int buffer[100];

void initialize()
{
	sem_init(&full,0,0);
	sem_init(&empty,0,buffersize);
	sem_init(&mutex,0,1);
	counter=0;
}

void write(int item)
{
	buffer[counter++]=item;
}

int read()
{
	return(buffer[--counter]);
}

void * producer (void * param)
{
	srand(time(NULL));
	for(k=0;k<=10;k++)
	{
		m=rand()%100;
		sem_wait(&empty);
		sem_wait(&mutex);
		write(m);
		printf("\nWriter wrote %d",m);
		sem_post(&mutex);
		sem_post(&full);
	}
}

void * consumer (void * param)
{
	int i;
	for(k=0;k<=10;k++)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		i=read();
		printf("\nReader read %d",i);
		sem_post(&mutex);
		sem_post(&empty);
	}
}

int main()
{
	
	buffersize=1;
	int n1,n2,i;
	initialize();

	n1=1;
	for(i=0;i<n1;i++)
		pthread_create(&tidP[i],NULL,producer,NULL);
	pthread_create(&tidC,NULL,consumer,NULL);
	for(i=0;i<n1;i++)
		pthread_join(tidP[i],NULL);
	pthread_join(tidC,NULL);
	exit(0);
}

