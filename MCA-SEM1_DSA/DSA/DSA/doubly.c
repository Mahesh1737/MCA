#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *prev; 
    struct node *next; 
} NODE;

NODE *head = NULL;

void create() 
{
   int n;
   NODE *last = NULL, *temp;

   printf("\nEnter the number of nodes: ");
   scanf("%d", &n);

   while (n > 0) 
	{
      temp = (NODE *)malloc(sizeof(NODE));
      if (temp == NULL) 
		{
         printf("\nMemory allocation failed!");
         return;
      }

      printf("Enter data: ");
      scanf("%d", &temp->data);

      temp->prev = NULL;
      temp->next = NULL;

      if (head == NULL) 
		{
         head = temp;
      } 
		else 
		{
         last->next = temp;
         temp->prev = last;
      }
      last = temp;
      n--;
   }
}

void display() 
{
   if (head == NULL) 
	{
      printf("\nList is empty!");
      return;
   }

   printf("\nList (Forward): ");
   NODE *temp = head;
   while (temp != NULL) 
	{
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

void delbetween() 
{
   int pos;
   NODE *temp;

   if (head == NULL) 
	{
      printf("\nList is empty!");
      return;
   }

   printf("\nEnter position to remove: ");
   scanf("%d", &pos);

   if (pos <= 0) 
	{
      printf("\nInvalid position!");
      return;
   }

   if (pos == 1) 
	{
      temp = head;
      head = head->next;
      if (head != NULL) 
		{
         head->prev = NULL;
      }
      free(temp);
      printf("\nNode deleted at position 1.\n");
      return;
   }

   temp = head;

   for (int i = 1; i < pos && temp != NULL; i++) 
	{
      temp = temp->next;
   }

   if (temp == NULL) 
	{
      printf("\nPosition out of range!");
      return;
   }

   if (temp->next != NULL) 
	{
      temp->next->prev = temp->prev;
   }
   if (temp->prev != NULL) 
	{
      temp->prev->next = temp->next;
   }

   free(temp);
   printf("\nNode deleted at position %d.\n", pos);
}

void display_reverse() 
{
   if (head == NULL) 
	{
      printf("\nList is empty!");
      return;
   }

   printf("\nList (Reverse): ");
   NODE *temp = head;

   while (temp->next != NULL) 
	{
      temp = temp->next;
   }

   while (temp != NULL) 
	{
      printf("%d ", temp->data);
      temp = temp->prev;
   }
   printf("\n");
}

int main() 
{
   int ch;

   do 
	{
      printf("\n1. Create");
      printf("\n2. Display (Forward)");
      printf("\n3. Display (Reverse)");
      printf("\n4. Delete");
      printf("\n5. Exit");
      printf("\nEnter choice: ");
      scanf("%d", &ch);

      switch (ch) 
		{
         case 1:
      	        	create();
         	   	break;
         case 2:
                display();
                break;
         case 3:
                display_reverse();
                break;
         case 4:
                delbetween();
                break;
         case 5:
               while (head != NULL) 
					{
                  NODE *temp = head;
                  head = head->next;
                  free(temp);
               }
               printf("\nExiting...\n");
               exit(0);
         default:
                printf("\nInvalid choice! Please try again.\n");
      }
   }while (1);

   return 0;
}

