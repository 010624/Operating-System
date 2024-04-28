
#include<stdio.h> 
int main() 
{ 
int m,p,s,p1; 
int m1[4],i,f,f1=0,f2=0,fra1,fra2,s1,pos; 
printf("Enter the memory size:"); 
scanf("%d",&m); 
printf("Enter the no of partitions:"); 
scanf("%d",&p); 
s=m/p; 
printf("Each partn size is:%d",s); 
printf("\nEnter the no of processes:"); 
scanf("%d",&p1); 
pos=m; 
for(i=0;i<p1;i++) 
{ 
if(pos<s) 
{ 
printf("\nThere is no further memory for process%d",i+1); m1[i]=0; 
break; 
} 
else 
{ 
printf("\nEnter the memory req for process%d:",i+1); scanf("%d",&m1[i]); 
if(m1[i]<=s) 
{ 
printf("\nProcess is allocated in partition%d",i+1); fra1=s-m1[i]; 
printf("\nInternal fragmentation for process is:%d",fra1); f1=f1+fra1; 
pos=pos-s; 
} 
else 
{ 
printf("\nProcess not allocated in partition%d",i+1); s1=m1[i]; 
while(s1>s) 
{ 
s1=s1-s; 
pos=pos-s; 
} 
pos=pos-s; 
fra2=s-s1; 
f2=f2+fra2; 
printf("\nExternal Fragmentation for this process is:%d",fra2); }
} 
} 
printf("\nProcess\tallocatedmemory"); 
for(i=0;i<p1;i++) 
printf("\n%5d\t%5d",i+1,m1[i]); 
f=f1+f2; 
printf("\nThe tot no of fragmentation is:%d",f); 
return 0; 
}




/*
–> MFT (Multiprogramming with a Fixed number of Tasks) is one of the old memory
management techniques in which the memory is partitioned into fixed size partitions and
each job is assigned to a partition. The memory assigned to a partition does not change.
Memory is divided into several fixed-size partitions.Each partition may contain exactly one
process/task.Boundaries for partitions are set at boot time and arenot movable.An input
queue per partition.The degree of multiprogramming is bound by the number of partitions. */

