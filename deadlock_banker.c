#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t room;
sem_t chopstick[5];

void * philosopher(void *);
void eat(int);
int main()
{
int i,a[5];
pthread_t tid[5];

sem_init(&room,0,4);

for(i=0;i<5;i++)
sem_init(&chopstick[i],0,1);

for(i=0;i<5;i++){
a[i]=i;
pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]);
}
for(i=0;i<5;i++)
pthread_join(tid[i],NULL);
}

void * philosopher(void * num)
{
int phil=*(int *)num;

sem_wait(&room);
printf("\nPhilosopher %d has entered room",phil);
sem_wait(&chopstick[phil]);
sem_wait(&chopstick[(phil+1)%5]);

eat(phil);
sleep(2);
printf("\nPhilosopher %d has finished eating",phil);

sem_post(&chopstick[(phil+1)%5]);
sem_post(&chopstick[phil]);
sem_post(&room);
}

void eat(int phil)
{
printf("\nPhilosopher %d is eating",phil);
}




/*
Several data structures must be maintain to implement the Bankers algorithm. These data 
structures encode the state of the resource-allocation system. Let n be the no. of process in the 
system and m be the no. of resources type. We need the following data structures:
1. Available: A vector of length n indicates the no. of available resources of each type. If 
[available] = k, there are k instances of resource type Rj available. 
2. Max: An n x m matrix defines the maximum demand of each process. If max [i, j] = k, 
then Pi may request almost k instances of resource type 
Rj. 
3. Allocation: An n x m matrix defines the no. of resources of each type currently allocated to each process. 
If allocation [i, j] = k, then process Pi is currently allocated k instance of resource type Rj. 
4. Need: An n x m matrix indicates the remaining resource need of each process. If need [i,j] = k,
then Pi may need k more instances of resource type Rj to complete this task. 
Need [i, j] = max [i, j] – allocation [i, j] 
*/
