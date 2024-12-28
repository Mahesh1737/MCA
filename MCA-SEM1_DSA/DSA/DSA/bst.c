#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[50];
    char tele[50];
    struct node *left, *right;
} *new1, *new2, *root = NULL, *t1;

struct node *create()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, struct node *new1)
{
    if (strcmp(root->name, new1->name) < 0)
    {
        if (root->right == NULL)
        {
            root->right = new1;
        }
        else
        {
            insert(root->right, new1);
        }
    }
    else if (strcmp(root->name, new1->name) > 0)
    {
        if (root->left == NULL)
        {
            root->left = new1;
        }
        else
        {
            insert(root->left, new1);
        }
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("Name :%s, Telephone: %s\n", root->name, root->tele);
        inorder(root->right);
    }
}

struct node *search(struct node *root, char *key)
{
    while (root != NULL)
    {

        if (strcmp(root->name, key)==0)
        {
            return root;
        }
        else if (strcmp(root->name , key) > 0)
        {
            return search(root->left, key);
        }
        else if(strcmp(root->name , key) < 0){
            return search(root->right, key);
        }
    }
    return NULL;
}

struct node *delete(struct node *root, char *key){
    if(root==NULL){
        return NULL;
    }
    
    if(strcmp(root->name,key)==0){
        return root;
    }
    else if(strcmp(root->name,key)>0){
        root->left = delete(root->left,key);
    }
    else if(strcmp(root->name,key)<0){
        root->right = delete(root->right,key);
    }
    else{
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else{
            struct node *temp = root->right;
            while(temp->left!=NULL){
                temp= temp->left;
            }
            strcpy(root->name, temp->name);
            strcpy(root->tele, temp->tele);
            root->right = delete(root->right, temp->name);

        }
    }
    return root;
}

int main()
{
    int ch, val, pos, n; 
    char key[50];
    struct node *root = NULL;
    while (1)
    {
        printf("\nBst operations: \n");
        printf("\n1. Create a List: ");
        printf("\n2. Display: ");
        printf("\n3. Insert a node: ");
        printf("\n4. search a node: ");
        printf("\n5. Delete a node: ");
        printf("\n6. Exit : ");
        printf("\nEnter the choice  : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (root != NULL)
            {
                printf("\nBST is already created.");
            }
            else
            {
                printf("\nEnter the number of the records you want add: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++)
                {

                    new1 = create();
                    printf("\nEnter the details to insert: ");
                    printf("\nEnter the name : ");
                    scanf(" %[^\n]", new1->name);
                    printf("\nEnter the Telephone number : ");
                    scanf(" %[^\n]", new1->tele);
                    if (root == NULL)
                    {
                        root = new1;
                    }
                    else
                    {
                        insert(root, new1);
                    }
                }
            }
            break;
        case 2:
            printf("\nInorder  Tracersal: \n");
            inorder(root);
            break;
        case 3:
            if (root == NULL)
            {
                printf("\nBst is not created:\n");
            }
            else
            {
                new2 = create();
                printf("\nEnter the details to insert: ");
                printf("\nEnter the name : ");
                scanf(" %[^\n]", new2->name);
                printf("\nEnter the Telephone number : ");
                scanf(" %[^\n]", new2->tele);
                if (root == NULL)
                {
                    root = new2;
                }
                else
                {
                    insert(root, new2);
                }
            }
            break;
        case 4:
            printf("\nEnter the name your want to search in the list: \n");
            scanf(" %[^\n]", key);
            t1 = search(root, key);
            if (t1!=NULL)
            {
                printf("\n%s element  is found in the list : \n", key);
            }
            else
            {
                printf("Element is  not found in the list\n");
            }
            break;
        case 5:
            printf("\nEnter the node to delete : ");
            scanf(" %[^\n]",key);
            new2 = delete(root, key);
            if(new2){
                printf("%s is deleted\n",key);
            }else{

                printf("%s not found\n",key);
            }
        break;
        case 6:
            exit(0);
        }
    }
}