#include<stdio.h>
#include<stdlib.h>
#define max 10
struct student{
    int roll;
    char name[10];
    float per;
};

void bubble(struct student students[], int n){
    struct student temp;
    for (int i=0;i<n;i++){
        for (int j=0;j<n-i-1;j++){
            if(students[j].per < students[j+1].per){
               temp = students[j];
               students[j] = students[j+1];
               students[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("\nEnter the number of the student : ");
    scanf("%d", &n);

    struct student students[n];

    printf("\nEnter the details of the student : \n");
    for (int i=0;i<n;i++){
        printf("Enter the roll number of the student : ");
        scanf("%d",&students[i].roll);
        printf("Enter the name of the student : ");
        scanf(" %[^\n]",&students[i].name);
        printf("Enter the percentage of the student : ");
        scanf(" %f",&students[i].per);
    }

    printf("\n------------------Details of the student--------------- : \n");
    for (int i=0;i<n;i++){
        printf("\nRoll number of the %d Student : %d",i+1,students[i].roll);
        printf("\nName of the %d student %s",i+1, students[i].name);
        printf("\nPercentage of the %d student %f\n",i+1, students[i].per);
    }

    bubble(students, n);

    printf("\n------------------Details of the student after sort--------------- : \n");
    for (int i=0;i<n;i++){
        printf("\nRoll number of the %d Student : %d",i+1,students[i].roll);
        printf("\nName of the %d student %s",i+1, students[i].name);
        printf("\nPercentage of the %d student %f\n",i+1, students[i].per);
    }

}