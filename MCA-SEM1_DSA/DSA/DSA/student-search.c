#include <stdio.h>
#include <string.h>

typedef struct {
    int rollNo;
    char name[50];
    float percentage;
} Student;

int i,j;

void accept(Student students[], int n) {
    for ( i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Name: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }
}

void display(Student students[], int n) {
    for ( i = 0; i < n; i++) {
        printf("\nRoll No: %d, Name: %s, Percentage: %.2f", students[i].rollNo, students[i].name, students[i].percentage);
    }
    printf("\n");
}

void bubble_sort(Student students[], int n) {
    for ( i = 1; i < n; i++) {
        for ( j = 0; j < n - i; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int binary_search(Student students[], int n, int rollNo) {
    int min = 0, max = n - 1;
    while (min <= max) {
        int mid = (min + max) / 2;
        if (students[mid].rollNo == rollNo) {
            return mid;
        } else if (rollNo < students[mid].rollNo) {
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n, rollNo, pos;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[n];
    accept(students, n);
    bubble_sort(students, n);
    printf("\nSorted Student Database:");
    display(students, n);

    printf("\nEnter Roll No to search: ");
    scanf("%d", &rollNo);

    pos = binary_search(students, n, rollNo);

    if (pos != -1) {
        printf("\nStudent found: Roll No: %d, Name: %s, Percentage: %.2f\n", students[pos].rollNo, students[pos].name, students[pos].percentage);
    } else {
        printf("\nStudent with Roll No %d not found.\n", rollNo);
    }

    return 0;
}

