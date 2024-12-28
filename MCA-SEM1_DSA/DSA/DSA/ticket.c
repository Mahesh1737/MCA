#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
   int tickets[MAX];
   int front, rear, size;
} cq;

void init(cq *q)
{
   q->front = 0;
  	q->rear = -1;
   q->size = 0;
}

int isEmpty(cq *q) 
{
   return q->size == 0;
}

int isFull(cq *q)
{
   return q->size == MAX;
}

void enqueue(cq *q)
{
   if (isFull(q))
	{
      printf("\nQueue is Full! Cannot add more tickets.\n");
   }
	else 
	{
      int ticketNumber;
      printf("\nEnter Ticket Number to Add: ");
      scanf("%d", &ticketNumber);
      q->rear = (q->rear + 1) % MAX;
      q->tickets[q->rear] = ticketNumber;
      q->size++;
      printf("Ticket %d added to the queue.\n", ticketNumber);
   }
}

void dequeue(cq *q)
{
   if(isEmpty(q))
	{
      printf("\nQueue is Empty! No tickets to process.\n");
   } 
	else
	{
      int ticket = q->tickets[q->front];
      printf("Processing Ticket %d\n", ticket);
      q->front = (q->front + 1) % MAX;
      q->size--;
   }
}

void display(cq *q)
{
	int index,i;
   if (isEmpty(q)) 
	{
      printf("\nQueue is Empty! No tickets to display.\n");
   } 
	else 
	{
      printf("\nCurrent Tickets in the Queue:\n");
      for ( i = 0; i < q->size; i++) 
	  {
         index = (q->front + i) % MAX;
         printf("Ticket %d\n", q->tickets[index]);
     }
   }
}

int main() 
{
   cq queue;
   int choice;
   init(&queue);

   do 
	{
   	printf("\nCustomer Support Ticket System\n");
      printf("1. Submit a Ticket\n");
      printf("2. Process a Ticket\n");
      printf("3. Display Tickets\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch (choice) 
	  {
         case 1:
               enqueue(&queue);
               break;
         case 2:
	            dequeue(&queue);
               break;
         case 3:
               display(&queue);
               break;
         case 4:
               printf("Exiting !!!!\n");
               exit(0);
         default:
               printf("Invalid choice! Please try again.\n");
      }
   } while (1);

   return 0;
}

