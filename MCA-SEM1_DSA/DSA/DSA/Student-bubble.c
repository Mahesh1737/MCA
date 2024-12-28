#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct {
    char name[50];
    float marks;
} Student;

int i,j;

void generate_students(Student students[], int n) {
    srand(time(NULL));
    for ( i = 0; i < n; i++) {
        sprintf(students[i].name, "Student_%d", i + 1);
        students[i].marks = (float)(rand() % 101);
    }
}

void display_students(Student students[], int n) {
    for ( i = 0; i < n; i++) {
        printf("%s: %.2f\n", students[i].name, students[i].marks);
    }
}

void bubble_sort_students(Student students[], int n) {
    for ( i = 1; i < n; i++) {
        for ( j = 0; j < n - i; j++) {
            if (students[j].marks < students[j + 1].marks) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    Student students[n];
    generate_students(students, n);

    printf("\nBefore Sorting:\n");
    display_students(students, n);

    bubble_sort_students(students, n);

    printf("\nTop 10 Toppers:\n");
    for ( i = 0; i < (n < 10 ? n : 10); i++) {
        printf("%s: %.2f\n", students[i].name, students[i].marks);
    }

    return 0;
}

