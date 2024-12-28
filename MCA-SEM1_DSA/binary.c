#include<stdio.h>
#include<stdlib.h>

struct student{
    int roll;
    char name[10];
    float per;
};

// void bubble(struct student students[], int n){
//     struct student temp;
//     for (int i=0;i<n;i++){
//         for (int j=0;j<n-i-1;j++){
//             if(students[j].per < students[j+1].per){
//                temp = students[j];
//                students[j] = students[j+1];
//                students[j+1] = temp;
//             }
//         }
//     }
// }

int binary(struct student students[], int n, int key){
    int low=0, high=n-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(students[mid].roll == key){
            return mid;
        }
        else if(students[mid].roll <= key){
            low = mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("\nEnter the number of the student : ");
    scanf("%d", &n);

    struct student students[n];
    int key;
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
        printf("\nRoll number of the Student : %d",students[i].roll);
        printf("\nName of the student %s", students[i].name);
        printf("\nPercentage of the student %f\n",students[i].per);
    }
    printf("\nEnter the roll no of the student to search: ");
    scanf("%d",&key);
    int bin = binary(students, n, key);
    
    if(bin!=-1){
        printf("\nRoll number of the Student : %d",students[bin].roll);
        printf("\nName of the student %s",students[bin].name);
        printf("\nPercentage of the student %f\n",students[bin].per);

    }
    else{
        printf("Student not found\n");
    }
    return 0;
}