#include <stdio.h> 
void fcfs_disk_scheduling(int queue[], int head, int n) 
{ 
 //Resultant variable which are used to store information of number of time or  operation 
 double seek_time = 0.0; 
 int distance = 0; 
 // Loop controlling variable 
 int i = 0; 
  
 printf("\n Starting Head : %d ", head); 
 printf("\n Queue Sequence : ");
 //Display given queue elements 
 for (i = 0; i < n; i++) 
 { 
 printf(" %d", queue[i]); 
 } 
  
 for (i = 0; i < n; i++) 
 { 
 //Get distance  
 distance = queue[i] - head; 
 if (distance < 0) 
 { 
 //When distance is negative then convert into it absolute value distance = -distance; 
 } 
 // Update head data into current track value  head = queue[i]; 
 // Add current distance into seek  seek_time += distance; 
 } 
 //Display result 
 printf("\n Total Seek Time : %lf", seek_time);  printf("\n Average Seek Time : %lf\n", seek_time / n); } 
int main() 
{ 
 // Request queue elements 
 int queue[] = { 
 64, 
 12, 
 42, 
 19, 
 62, 
 32, 
 16, 
 86 
 }; 
 //Get the number of elements in request queue  
 int n = sizeof(queue) / sizeof(queue[0]); 
 //Initial head position 
 int head = 25; 
 fcfs_disk_scheduling(queue, head, n); 
 return 0; 
} 






/*
10)
Disk Scheduling is the process of deciding which of the cylinder request is in the
ready queue is to be accessed next.The access time and the bandwidth can be
improved by scheduling the servicing of disk I/O requests in good order.The access
time has two major components: Seek time and Rotational Latency.Seek time is the
time for disk arm to move the heads to the cylinder containing the desired sector.
FirstComeFirstServe(FCFS)
FCFS is the simplest disk scheduling algorithm. As the name suggests, this algorithm
entertains requests in the order they arrive in the disk queue. The algorithm looks very fair
and there is no starvation (all requests are serviced sequentially) but generally, it does not
provide the fastest service.     */

