#include <stdio.h>
#include <stdlib.h>

struct book
{
    int id;
    char bname[50];
    char bauthor[50];
    struct book *next;
} *head = NULL, *temp, *books, *prev=NULL;

void createNode(int n)
{
    // struct book *temp;
    for (int i = 0; i < n; i++)
    {
        books = (struct book *)malloc(sizeof(struct book));
        books->next = NULL;
        printf("Enter the book ID : ");
        scanf("%d", &books->id);
        printf("Enter the book name : ");
        scanf(" %[^\n]", books->bname);
        printf("Enter the book author name : ");
        scanf(" %[^\n]", books->bauthor);

        if (head == NULL)
        {
            head = books;
            temp = head;
        }
        else
        {
            temp->next = books;
            temp = temp->next;
        }
    }
}

void display(int n)
{
    temp = head;
    printf("\nhead->\n");
    while (temp != NULL)
    {
        printf("Book ID: %d\n", temp->id);
        printf("Book ID: %s\n", temp->bname);
        printf("Book ID: %s\n", temp->bauthor);
        temp = temp->next;
    }
    printf("\n->Null\n");
}

void insert(int pos)
{
    books = (struct book *)malloc(sizeof(struct book));
    temp = head;
    printf("Enter the book ID : ");
    scanf("%d", &books->id);
    printf("Enter the book name : ");
    scanf(" %[^\n]", books->bname);
    printf("Enter the book author name : ");
    scanf(" %[^\n]", books->bauthor);

    if(pos==1){
        books->next=head;
        head=books;

        printf("book added at %d position\n",pos);
    }
    int count;
    while(temp!=NULL && count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp==NULL){
        printf("\nBook is added at the end of the list \n");
    }
    else{
        books->next = temp->next;
        temp->next=books;
        printf("Book  inserted at the %d position\n",pos);
    }
}

void delete(int pos){
    temp=head;
    if(pos==1){
        head = temp->next;
        free(temp); 
        return;
    }
    int count;
    while(temp!=NULL && count<pos){
        prev = temp;
        temp=temp->next;
        count++;
    }
    if(temp==NULL){
        printf("nBook is not found\n");
        return;
    }

    prev->next = temp->next;
    printf("Book is deleted from the position %d\n",pos);
    free(temp);

}

int count(){
    temp = head;
    int cnt=0;
    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main()
{
    int n, ch, pos, val;

    while (1)
    {
        printf("\nBook operations :\n");
        printf("\n1.Create Node: ");
        printf("\n2.Display The List: ");
        printf("\n3.Insert Book: ");
        printf("\n4.Delete a Book: ");
        printf("\n5.Count the books: ");
        printf("\n6.Exit: ");
        printf("\nEnter the choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of books you want add : ");
            scanf("%d", &n);
            createNode(n);
            break;
        case 2:
            display(n);
            break;
        case 3:
            printf("Enter the postion of the books you want add : ");
            scanf("%d", &pos);
            insert(pos);
            break;
        case 4:
            printf("Enter the postion of the books you want delete : ");
            scanf("%d", &val);
            delete(val);
            break;
        case 5:
            if(count()){
                printf("Total number of books are present in the library is %d\n", count());
            }
            else{
                printf("Error\n");
            }
            break;
        case 6:
            exit(0);
        }
    }
}