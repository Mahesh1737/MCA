#include<stdio.h>
#include<stdlib.h>

struct sales{
    int s_id;
    char cust_name[10];
    char prod_name[10];
    int quantSold;
    int tot_sale;
};

void merge(struct sales sale[], int low, int high, int mid){
    int i= low;
    int j= mid+1;
    int k=0;
    struct sales temp[high-low+1];
    
    while(i<=mid && j<=high){
         if(sale[i].tot_sale < sale[j].tot_sale){
            temp[k++] = sale[i++];
         }
         else{
            temp[k++] = sale[j++];
         }
    }
    while(i<=mid){
        temp[k++] = sale[i++];
    }
    while(j<=high){
        temp[k++] = sale[j++];
    }

    for (int i=low, k=0; i<=high; i++, k++){
        sale[i] = temp[k];
    }
}


void mergeSort(struct sales sale[], int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(sale, low, mid);
        mergeSort(sale, mid+1, high);
        merge(sale, low, high, mid);
    }
}


int main(){
    int n;
    printf("Enter the numder of product : ");
    scanf("%d",&n);

    struct sales sale[n];

    for(int i=0;i<n;i++){
        printf("\nEnter the details of the %d products: \n",i);
        printf("\nEnter the sale ID: ");
        scanf("%d",&sale[i].s_id);
        printf("\nEnter the Customer name: ");
        scanf(" %[^\n]",sale[i].cust_name);
        printf("\nEnter the product name: ");
        scanf(" %[^\n]",sale[i].prod_name);
        printf("\nEnter the Quantity sold: ");
        scanf("%d",&sale[i].quantSold);
        printf("\nEnter the total sale: ");
        scanf("%d",&sale[i].tot_sale);
    }

    printf("\n---------------------Product detail before sort--------------------------------: \n");
    for(int i=0;i<n;i++){
        printf("\nDetails of the %d products: \n",i+1);
        printf("\nSale ID: %d",sale[i].s_id);
        printf("\nCustomer name: %s",sale[i].cust_name);
        printf("\nProduct name: %s",sale[i].prod_name);
        printf("\nQuantity sold: %d",sale[i].quantSold);
        printf("\nTotal sale: %d", sale[i].tot_sale);
    }
    
    mergeSort(sale, 0, n-1);
    
    printf("\n--------------------------Product detail after sort-------------------------- : \n");
    for(int i=0;i<n;i++){
        printf("\nDetails of the %d products: \n",i+1);
        printf("\nSale ID: %d",sale[i].s_id);
        printf("\nCustomer name: %s",sale[i].cust_name);
        printf("\nProduct name: %s",sale[i].prod_name);
        printf("\nQuantity sold: %d",sale[i].quantSold);
        printf("\nTotal sale: %d", sale[i].tot_sale);
    }
}
