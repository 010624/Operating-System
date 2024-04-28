 #include<stdio.h> 
int main() 
{ 
 int i, limit, total = 0, x, counter = 0, time_quantum; 
 int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];  float average_wait_time, average_turnaround_time; 
 printf("Enter Total Number of Processes:"); 
 scanf("%d", &limit); 
 x = limit; 
 for(i = 0; i < limit; i++) 
 {
 printf("Enter Details of Process[%d]\t", i + 1); 
 printf("Arrival Time:\t"); 
 scanf("%d", &arrival_time[i]); 
 printf("Burst Time:\t"); 
 scanf("%d", &burst_time[i]); 
 temp[i] = burst_time[i]; 
 } 
 printf("Enter Time Quantum:\t"); 
 scanf("%d", &time_quantum); 
 printf("nProcess IDttBurst Timet Turnaround Timet Waiting Timen");  for(total = 0, i = 0; x != 0;) 
 { 
 if(temp[i] <= time_quantum && temp[i] > 0) 
 { 
 total = total + temp[i]; 
 temp[i] = 0; 
 counter = 1; 
 } 
 else if(temp[i] > 0) 
 { 
 temp[i] = temp[i] - time_quantum; 
 total = total + time_quantum; 
 } 
 if(temp[i] == 0 && counter == 1) 
 { 
 x--; 
 printf("Process[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total -  arrival_time[i], total - arrival_time[i] - burst_time[i]); 
 wait_time = wait_time + total - arrival_time[i] - burst_time[i];  turnaround_time = turnaround_time + total - arrival_time[i];  counter = 0; 
 } 
 if(i == limit - 1) 
 { 
 i = 0; 
 } 
 else if(arrival_time[i + 1] <= total) 
 { 
 i++; 
 } 
 else 
 { 
 i = 0; 
 } 
 }
 average_wait_time = wait_time * 1.0 / limit; 
 average_turnaround_time = turnaround_time * 1.0 / limit; 
 printf("Average Waiting Time:\t%f", average_wait_time); 
 printf("Avg Turnaround Time:\t%f", average_turnaround_time);  return 0; 
} 






/*

 this scheduling is based on the priority of the processes. The
process which have the higher priority will get the CPU first. whereas jobs with equal priorities are
carried out on a round-robin or FCFS basis.
This scheduling is of two types:-
1. Non preemptive
2. Preemptive
characteristics:-
1. It schedules the process based on the priority of the processes.
2. Lower the number higher the priority.
3. If the two or more processes have the same priority then we schedules on the basis of FCFS.
4. Major problem with priority scheduling is problem of starvation.
 */
