// C program for the above approach
#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty = 10, x = 0;
void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nProducer produces"
           "item %d",
           x);
           
    ++mutex;
}
void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes "
           "item %d",
           x);
    x--;
    ++mutex;
}
int main()
{
    int n, i;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");
#pragma omp critical

    for (i = 1; i > 0; i++) {

        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n) {
        case 1:
            if ((mutex == 1)
                && (empty != 0)) {
                producer();
            }
            else {
                printf("Buffer is full!");
            }
            break;

        case 2:
            if ((mutex == 1)
                && (full != 0)) {
                consumer();
            }

            else {
                printf("Buffer is empty!");
            }
            break;
        case 3:
            exit(0);
            break;
        }
    }
}





/*

Semaphore : A semaphore S is an integer variable that can be accessed only through two standard 
operations :
wait() - The wait() operation reduces the value of semaphore by 1
signal() - The signal() operation increases its value by 1.
Semaphores are of two types:
Binary Semaphore – This is similar to mutex lock but not the same thing. It can have only 
two values – 0 and 1. Its value is initialized to 1. It is used to implement the solution of 
critical section problem with multiple processes.
Counting Semaphore – Its value can range over an unrestricted domain. It is used to 
control access to a resource that has multiple instances.    */
