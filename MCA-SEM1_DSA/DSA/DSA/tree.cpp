#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100


typedef struct tree {
    char name[MAX_NAME_LENGTH];
    long phoneNumber;
    struct tree *left, *right;
} TREE;


TREE* insert(TREE *root, char name[], int phoneNumber);
TREE* deleteNode(TREE *root, char name[]);
TREE* minValueNode(TREE *root);
void search(TREE *root, char name[]);
void printPhoneList(TREE *root);
void menu();

TREE *root = NULL;

int main() {

    menu();

    return 0;
}


void menu() {
    char name[MAX_NAME_LENGTH];
    int  choice;
    long phoneNumber;

    do {
        printf("\n1: Insert Name and Phone Number\n");
        printf("2: Search by Name\n");
        printf("3: Insert New Name\n");
        printf("4: Delete Existing Name\n");
        printf("5: Print Entire Phone List\n");
        printf("0: EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Phone Number: ");
                scanf("%ld", &phoneNumber);
                root = insert(root, name, phoneNumber);
                break;

            case 2:
                printf("Enter Name to Search: ");
                scanf("%s", name);
                search(root, name);
                break;

            case 3:
                printf("Enter Name to Insert: ");
                scanf("%s", name);
                printf("Enter Phone Number: ");
                scanf("%d", &phoneNumber);
                root = insert(root, name, phoneNumber);
                break;

            case 4:
                printf("Enter Name to Delete: ");
                scanf("%s", name);
                root = deleteNode(root, name);
                break;

            case 5:
                printf("\nPhone List:\n");
                printPhoneList(root);
                break;

            case 0:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(1);
}


TREE* insert(TREE *root, char name[], long phoneNumber) {
    if (root == NULL) {
        root = (TREE*)malloc(sizeof(TREE));
        strcpy(root->name, name);
        root->phoneNumber = phoneNumber;
        root->left = root->right = NULL;
    } else if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, phoneNumber);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name, phoneNumber);
    } else {
        printf("The name already exists in the phonebook.\n");
    }
    return root;
}


TREE* deleteNode(TREE *root, char name[]) {
    if (root == NULL) {
        return root;
    }


    if (strcmp(name, root->name) < 0) {
        root->left = deleteNode(root->left, name);
    }

    else if (strcmp(name, root->name) > 0) {
        root->right = deleteNode(root->right, name);
    }

    else {

        if (root->left == NULL) {
            TREE *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TREE *temp = root->left;
            free(root);
            return temp;
        }


        TREE *temp = minValueNode(root->right);


        strcpy(root->name, temp->name);
        root->phoneNumber = temp->phoneNumber;


        root->right = deleteNode(root->right, temp->name);
    }
    return root;
}


TREE* minValueNode(TREE *root) {
    TREE *current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


void search(TREE *root, char name[]) {
    if (root == NULL) {
        printf("Name not found!\n");
        return;
    }

    if (strcmp(name, root->name) == 0) {
        printf("Found: %s, Phone: %ld\n", root->name, root->phoneNumber);
    } else if (strcmp(name, root->name) < 0) {
        search(root->left, name);
    } else {
        search(root->right, name);
    }
}


void printPhoneList(TREE *root) {
    if (root == NULL) {
        return;
    }
    printPhoneList(root->left);
    printf("%s: %ld\n", root->name, root->phoneNumber);
    printPhoneList(root->right);
}

