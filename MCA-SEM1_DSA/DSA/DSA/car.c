#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car {
    char model[50];
    char manufacturer[50];
    double price;
    int engine_capacity;
    struct car *prev;
    struct car *next;
} CAR;

CAR *head = NULL;

CAR* create_car() 
{
   CAR *new_car = (CAR *)malloc(sizeof(CAR));
   if (new_car == NULL) 
	{
      printf("\nMemory allocation failed!\n");
      return NULL;
   }

   printf("\nEnter car model: ");
   scanf("%s", new_car->model);
   printf("Enter manufacturer: ");
   scanf("%s", new_car->manufacturer);
   printf("Enter price: ");
   scanf("%lf", &new_car->price);
   printf("Enter engine capacity (cc): ");
   scanf("%d", &new_car->engine_capacity);

   new_car->prev = NULL;
   new_car->next = NULL;

   return new_car;
}

void insert_car() 
{
   CAR *new_car = create_car();
   if (new_car == NULL) return;

   if (head == NULL) 
	{
      head = new_car;
   } 
	else 
	{
      CAR *temp = head;
      while (temp->next != NULL) 
		{
         temp = temp->next;
      }
      temp->next = new_car;
      new_car->prev = temp;
   }
   printf("\nCar model added successfully!\n");
}

void display_cars() 
{
   if (head == NULL) 
	{
      printf("\nNo car models in the list.\n");
      return;
   }

   printf("\nCar Models List:\n");
   CAR *temp = head;
   while (temp != NULL) 
	{
      printf("Model: %s\nManufacturer: %s\nPrice: %.2lf\nEngine Capacity: %d cc\n",
      temp->model, temp->manufacturer, temp->price, temp->engine_capacity);
      temp = temp->next;
   }
}

void delete_car() 
{
   if (head == NULL) 
	{
      printf("\nNo car models to delete.\n");
      return;
   }

   char model_to_delete[50];
   printf("\nEnter car model to delete: ");
   scanf("%s", model_to_delete);

   CAR *temp = head;
   while (temp != NULL && strcmp(temp->model, model_to_delete) != 0) 
	{
      temp = temp->next;
   }

   if (temp == NULL) 
	{
      printf("\nCar model not found.\n");
      return;
   }

   if (temp->prev != NULL) 
	{
      temp->prev->next = temp->next;
   } 
	else 
	{
      head = temp->next;
   }
   if (temp->next != NULL) 
	{
      temp->next->prev = temp->prev;
   }

   free(temp);
   printf("\nCar model deleted successfully!\n");
}

void update_price() 
{
   if (head == NULL) 
	{
      printf("\nNo car models to update.\n");
      return;
   }

   char model_to_update[50];
   printf("\nEnter car model to update price: ");
   scanf("%s", model_to_update);

   CAR *temp = head;
   while (temp != NULL && strcmp(temp->model, model_to_update) != 0) 
	{
      temp = temp->next;
   }

   if (temp == NULL) 
	{
      printf("\nCar model not found.\n");
      return;
   }

   printf("\nEnter new price: ");
   scanf("%lf", &temp->price);
   printf("\nCar price updated successfully!\n");
}

void list_by_price_range() 
{
   if (head == NULL) 
	{
      printf("\nNo car models in the list.\n");
      return;
   }

   double min_price, max_price;
   printf("\nEnter minimum price: ");
   scanf("%lf", &min_price);
   printf("Enter maximum price: ");
   scanf("%lf", &max_price);

   printf("\nCar Models within price range %.2lf - %.2lf:\n", min_price, max_price);
   CAR *temp = head;
   int found = 0;
   while (temp != NULL) 
	{
      if (temp->price >= min_price && temp->price <= max_price) 
		{
         printf("Model: %s\nManufacturer: %s\nPrice: %.2lf\nEngine Capacity: %d cc\n",
         temp->model, temp->manufacturer, temp->price, temp->engine_capacity);
         found = 1;
      }
      temp = temp->next;
   }

   if (!found) 
	{
      printf("\nNo car models found in the specified price range.\n");
   }
}

void search_car() 
{
	if (head == NULL) 
	{
      printf("\nNo car models in the list.\n");
      return;
   }

   char model_to_search[50];
   printf("\nEnter car model to search: ");
   scanf("%s", model_to_search);

   CAR *temp = head;
   while (temp != NULL && strcmp(temp->model, model_to_search) != 0) 
	{
      temp = temp->next;
   }

   if (temp == NULL) 
	{
      printf("\nCar model not found.\n");
      return;
   }

   printf("\n\t----Details of Car Model '%s':----\n", model_to_search);
   printf("Manufacturer: %s\nPrice: %.2lf\nEngine Capacity: %d cc\n",
   temp->manufacturer, temp->price, temp->engine_capacity);
}

int main() 
{
	int choice;
   do 
	{
      printf("\nMenu:");
      printf("\n1. Insert new car model");
      printf("\n2. Display all car models");
      printf("\n3. Delete a car model");
      printf("\n4. Update car price");
      printf("\n5. List cars within a price range");
      printf("\n6. Search for a car model");
      printf("\n7. Exit");
      printf("\nEnter your choice: ");
      scanf("%d", &choice);
      switch (choice) 
		{
         case 1:
                	insert_car();
                	break;
         case 2:
                	display_cars();
                	break;
         case 3:
                	delete_car();
                	break;
         case 4:
                	update_price();
                	break;
      	case 5:
                	list_by_price_range();
                	break;
         case 6:
                	search_car();
                	break;
         case 7:
                	while (head != NULL) 
					 	{
                    CAR *temp = head;
                    head = head->next;
                    free(temp);
                	}
                	printf("\nExiting...\n");
                	exit(0);
         default:
                	printf("\nInvalid choice! Please try again.\n");
      }
   } while (1);

   return 0;
}

