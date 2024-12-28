#include <stdio.h>
#include <string.h>

typedef struct {
    int salesID;
    char customerName[50];
    char productName[50];
    int quantitySold;
    float totalSaleAmount;
} Sale;

int i,j;

void accept(Sale sales[], int n);
void display(Sale sales[], int n);
void merge_sort(Sale sales[], int low, int high);
void merge(Sale sales[], int low, int mid, int high);

int main() {
    int n;
    printf("Enter the number of sales records: ");
    scanf("%d", &n);

    Sale sales[n];
    accept(sales, n);

    printf("\nSales data before sorting:\n");
    display(sales, n);

    merge_sort(sales, 0, n - 1);

    printf("\nSales data after sorting (by total sale amount in descending order):\n");
    display(sales, n);

    return 0;
}

void accept(Sale sales[], int n) {
    for ( i = 0; i < n; i++) {
        printf("\nEnter details for sale %d:\n", i + 1);
        printf("Sales ID: ");
        scanf("%d", &sales[i].salesID);
        printf("Customer Name: ");
        scanf(" %[^\n]s", sales[i].customerName);
        printf("Product Name: ");
        scanf(" %[^\n]s", sales[i].productName);
        printf("Quantity Sold: ");
        scanf("%d", &sales[i].quantitySold);
        printf("Total Sale Amount: ");
        scanf("%f", &sales[i].totalSaleAmount);
    }
}

void display(Sale sales[], int n) {
    for ( i = 0; i < n; i++) {
        printf("Sales ID: %d, Customer: %s, Product: %s, Quantity: %d, Total Sale: %.2f\n",
               sales[i].salesID, sales[i].customerName, sales[i].productName,
               sales[i].quantitySold, sales[i].totalSaleAmount);
    }
}

void merge_sort(Sale sales[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(sales, low, mid);
        merge_sort(sales, mid + 1, high);
        merge(sales, low, mid, high);
    }
}

void merge(Sale sales[], int low, int mid, int high) {
     i = low;
	  j = mid + 1;
	  int k = 0;
    Sale temp[high - low + 1];

    while (i <= mid && j <= high) {
        if (sales[i].totalSaleAmount >= sales[j].totalSaleAmount) {
            temp[k++] = sales[i++];
        } else {
            temp[k++] = sales[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = sales[i++];
    }

    while (j <= high) {
        temp[k++] = sales[j++];
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        sales[i] = temp[k];
    }
}

