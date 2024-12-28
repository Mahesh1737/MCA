#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int low, int high)
{
    int temp;
    int i = low + 1;
    int j = high;
    int pivot = a[low];

    do
    {

        while (i <= high && a[i] <= pivot)
        {
            i++;
        }
        while (j >= low && a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int part = partition(a, low, high);
        quickSort(a, low, part - 1);
        quickSort(a, part + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
    return 0;
}