#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct Process 
{ 
    int pid;  // Process ID 
    int bt;   // CPU Burst time required 
    int priority; // Priority of this process
    struct Process *next; //pointer to next 
};
 struct Process *start;
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) ;
 
}


void itinerary(struct Process *start)
{
	struct Process *ptr;
	ptr = start;
	if(start == NULL)
 	printf("\nSchedule is empty" );
	else
	{
 	  printf("\n Current schedule is  :  " );
	  while(ptr != NULL)
 	  {
 		printf( "\t%d[priority=%d]", ptr->pid, ptr->priority );
 		ptr=ptr->next;
 	  }
	}
}



struct Process *delete(struct Process *start)
{
	struct Process *ptr;
	if(start == NULL)
	{
 	  printf("\n No schedule" );
 	  return start ;
	}
	else	
	{
 	  ptr = start;
 	  printf("\n Deleted Process is: %d",ptr->pid);
 	  start = start->next;
 	  free(ptr);
	}
	return start;
}

void run(struct Process *start)
{
    struct Process *ptr=start;
    do{
	printf("The current schedule is : ");
	itinerary(start);
	printf("Executing the highest priority process...");
	delay(ptr->bt);
	printf("The process took ....%d",ptr->bt);
	printf("process executed ");
	start=delete(start);
      }while(ptr->next!=NULL);
}

struct Process *insert(struct Process *start)
{
	int val, pri,burst_time;
	struct Process *ptr, *p;
	ptr = (struct Process*)malloc(sizeof(struct Process));
	printf("\n Enter the processid and its priority and  runtime : ");
	scanf( "%d %d %d", &val, &pri,&burst_time);
	ptr->pid = val;
	ptr->bt=burst_time;
	ptr->priority = pri;
	if(start==NULL || pri < start->priority )
	{
 	   ptr->next = start;
 	   start = ptr;
	}		
	else
	{
 	   p = start;
	   while(p->next != NULL && p->next->priority <= pri)
 	   p = p->next;
 	   ptr->next = p->next;
 	   p->next = ptr;
	}
	return start;
}


void main()
{
    int option;
    clrscr();
    do
    {
	  printf("\n *****MAIN MENU*****");
  	  printf("\n 1. INSERT ");
  	  printf("\n 2. DELETE");
  	  printf("\n 3. ITINERARY");
  	  printf("\n 4. RUN ");
  	  printf("\n 5. END");
  	  printf("\n Enter your option : ");
  	  scanf( "%d", &option);
	  switch(option)
 	  {
   	   	case 1: start=insert(start);
	   		break;
   		case 2: start = delete(start);
	   		break;
   		case 3: itinerary(start);
	   		break;
   		case 4: run(start);
 	   		break;
   		case 5: break;
 		default:printf("\nInvalid Input");
 	  }
    }while(option!=4);
    getch();
}

