#include <stdio.h>
#define MAX 100

// Function to create a sparse matrix
int createSparseMatrix(int matrix[MAX][MAX], int rows, int cols, int sparse[MAX][3]) {
    int k = 1;
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                sparse[0][2]++;
                k++;
            }
        }
    }
    return k;
}

// Function to display a sparse matrix
void displaySparseMatrix(int sparse[MAX][3]) {
    int nonZeroElements = sparse[0][2];

    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= nonZeroElements; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

// Function for simple transpose of a sparse matrix
void simpleTransposeSparseMatrix(int original[MAX][3], int transpose[MAX][3]) {
    int nonZeroElements = original[0][2];
    transpose[0][0] = original[0][1];
    transpose[0][1] = original[0][0];
    transpose[0][2] = nonZeroElements;

    int k = 1;
    for (int i = 0; i < original[0][1]; i++) {
        for (int j = 1; j <= nonZeroElements; j++) {
            if (original[j][1] == i) {
                transpose[k][0] = original[j][1];
                transpose[k][1] = original[j][0];
                transpose[k][2] = original[j][2];
                k++;
            }
        }
    }
}

// Function for fast transpose of a sparse matrix
void fastTransposeSparseMatrix(int original[MAX][3], int transpose[MAX][3]) {
    int rowTerms[MAX] = {0}, startingPos[MAX];
    int numRows = original[0][0];
    int numCols = original[0][1];
    int numNonZero = original[0][2];

    transpose[0][0] = numCols;
    transpose[0][1] = numRows;
    transpose[0][2] = numNonZero;

    for (int i = 1; i <= numNonZero; i++) {
        rowTerms[original[i][1]]++;
    }

    startingPos[0] = 1;
    for (int i = 1; i < numCols; i++) {
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    for (int i = 1; i <= numNonZero; i++) {
        int colIndex = original[i][1];
        int position = startingPos[colIndex];
        transpose[position][0] = original[i][1];
        transpose[position][1] = original[i][0];
        transpose[position][2] = original[i][2];
        startingPos[colIndex]++;
    }
}

// Main function with menu-driven implementation
int main() {
    int rows, cols, choice;
    int matrix[MAX][MAX];
    int sparse[MAX][3], transpose[MAX][3];

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    createSparseMatrix(matrix, rows, cols, sparse);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Sparse Matrix\n");
        printf("2. Simple Transpose\n");
        printf("3. Fast Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nSparse Matrix:\n");
                displaySparseMatrix(sparse);
                break;
            case 2:
                simpleTransposeSparseMatrix(sparse, transpose);
                printf("\nSimple Transposed Sparse Matrix:\n");
                displaySparseMatrix(transpose);
                break;
            case 3:
                fastTransposeSparseMatrix(sparse, transpose);
                printf("\nFast Transposed Sparse Matrix:\n");
                displaySparseMatrix(transpose);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
