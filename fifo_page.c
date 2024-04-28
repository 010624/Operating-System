// C program for FIFO page replacement algorithm 
#include <stdio.h> 
int main() 
{ 
 int incomingStream[] = {4, 1, 2, 4, 5}; 
 int pageFaults = 0; 
 int frames = 3; 
 int m, n, s, pages; 
 pages = sizeof(incomingStream)/sizeof(incomingStream[0]); 
 printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3"); 
 int temp[frames]; 
 for(m = 0; m < frames; m++) 
 { 
 temp[m] = -1; 
 } 
 for(m = 0; m < pages; m++) 
 { 
 s = 0; 
 for(n = 0; n < frames; n++) 
 { 
 if(incomingStream[m] == temp[n]) 
 { 
 s++; 
 pageFaults--; 
 } 
 } 
 pageFaults++; 
  
 if((pageFaults <= frames) && (s == 0)) 
 { 
 temp[m] = incomingStream[m]; 
 } 
 else if(s == 0) 
 { 
 temp[(pageFaults - 1) % frames] = incomingStream[m]; 
 } 
  
 printf("\n"); 
 printf("%d\t\t\t",incomingStream[m]); 
 for(n = 0; n < frames; n++) 
 { 
 if(temp[n] != -1) 
 printf(" %d\t\t\t", temp[n]); 
 else 
 printf(" - \t\t\t"); 
 } 
 } 
 printf("\nTotal Page Faults:\t%d\n", pageFaults); 
 return 0; 
}





/* 
If the optimal algorithm is not feasible, perhaps an approximation to the optimal algorithm is
possible. The key distinction between FIFO and OPT algorithm is that FIFO algorithm uses the
time when a page was brought into memory while OPT algorithm uses the time when the page is to
be used for the longest period of time .This approach is also used in LRU algorithm .
LRU replacement associates with each page the time of that pages last use .When a page must be
replaced LRU chooses that page that has not been used for longest period of time . This strategy is
optimal page replacement algorithm looking backward in time, rather than forward.
If we set SR be the reverse of reference string S then page fault rate for LRU algorithm on S is the
same page fault rate on SR   */

