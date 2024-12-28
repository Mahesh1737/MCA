#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
   int id;             
   char title[100];     
   struct node *next; 
} NODE;

NODE *head = NULL;

void addBook() 
{
   NODE *temp = (NODE *)malloc(sizeof(NODE));
   if (temp == NULL) 
	{
      printf("\n Memory allocation failed!\n");
      return;
   }

   printf("\n Enter Book ID: ");
   scanf("%d", &temp->id);
   getchar();  
   
   printf(" Enter Book Title: ");
   fgets(temp->title, 100, stdin);
   temp->title[strcspn(temp->title, "\n")] = '\0';  

   temp->next = NULL;

   if (head == NULL) 
	{
      head = temp;
   } 
	else 
	{
      NODE *last = head;
      while (last->next != NULL) 
		{
      	last = last->next;
   	}
     last->next = temp;
   }
   printf("\n Book added successfully.\n");
}

void displayBooks() 
{
   if (head == NULL) 
	{
      printf("\n No books in the library.\n");
      return;
   }

   printf("\n Books in the library:\n");
   NODE *temp = head;
   while (temp != NULL) 
	{
      printf(" ID: %d, Title: %s\n", temp->id, temp->title);
      temp = temp->next;
   }
}

void searchBook() 
{
   if (head == NULL) 
	{
      printf("\n No books in the library to search.\n");
      return;
   }

   int searchId;
   printf("\n Enter the Book ID to search: ");
   scanf("%d", &searchId);

   NODE *temp = head;
   while (temp != NULL) 
	{
      if (temp->id == searchId) 
		{
   	  printf("\n Book Found: ID: %d, Title: %s\n", temp->id, temp->title);
        return;
      }
      temp = temp->next;
   }
   printf("\n Book with ID %d not found.\n", searchId);
}

void removeBook() 
{
   if (head == NULL) 
	{
      printf("\n No books in the library to remove.\n");
      return;
   }

   int removeId;
   printf("\n Enter the Book ID to remove: ");
   scanf("%d", &removeId);

   NODE *temp = head, *prev = NULL;

   if (temp != NULL && temp->id == removeId) 
	{
      head = temp->next;
      free(temp);
      printf("\n Book with ID %d removed successfully.\n", removeId);
      return;
   }

   while (temp != NULL && temp->id != removeId) 
	{
      prev = temp;
      temp = temp->next;
   }

   if (temp == NULL) 
	{
      printf("\n Book with ID %d not found.\n", removeId);
      return;
   }

   prev->next = temp->next;
   free(temp);
   printf("\n Book with ID %d removed successfully.\n", removeId);
}

void countBooks() 
{
	int count = 0;
   NODE *temp = head;

   while (temp != NULL) 
	{
      count++;
      temp = temp->next;
   }

   printf("\n Total number of books: %d\n", count);
}

void freeList() 
{
   NODE *current = head;
   while (current != NULL) 
	{
      NODE *next = current->next;
      free(current);
      current = next;
   }
   head = NULL;
   printf("\n All books have been removed and memory is freed.\n");
}

int main() 
{
   int choice;
   do 
	{
      printf("\n=== Library Menu ===");
      printf("\n 1. Add Book");
      printf("\n 2. Display Books");
      printf("\n 3. Search Book");
      printf("\n 4. Remove Book");
   	printf("\n 5. Count Books");
      printf("\n 6. Exit");
      printf("\n Enter your choice: ");
      scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                removeBook();
                break;
            case 5:
                countBooks();
                break;
            case 6:
                freeList();
                printf("\n Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\n Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}

