#include<stdio.h> 
void main()  
{ 
int m=0,m1=0,m2=0,p,count=0,i; 
printf("enter the memory capacity:"); 
scanf("%d",&m); 
printf("enter the no of processes:");
//he concept of MVT and MFT memory management  techniques. 
scanf("%d",&p); 
for(i=0;i<p;i++) 
{ 
printf("\nenter memory req for process%d: ",i+1); 
scanf("%d",&m1); 
count=count+m1; 
if(m1<=m) 
{ 
if(count==m) 
printf("there is no further memory remaining:"); 
printf("the memory allocated for process%d is: %d ",i+1,m); m2=m-m1; 
printf("\nremaining memory is: %d",m2); 
m=m2; 
} 
else 
{ 
printf("memory is not allocated for process%d",i+1); 
} 
printf("\nexternal fragmentation for this process is:%d",m2); } 
} 




/*
–>MVT (Multiprogramming with a Variable number of Tasks) is the memory management
technique in which each job gets just the amount of memory it needs. That is, the
partitioning of memory is dynamic and changes as jobs enter and leave the system. MVT
is a more “efficient” user of resources. In MVT there is no internal fragmentation. Due to
variable size process this method is more flexible than MFT. Such that there is no size
limitation with the for the processes. */
