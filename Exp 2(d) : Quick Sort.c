#include <stdio.h>

void swap(int *a,int *b){
  int t = *a; 
  *a = *b; 
  *b = t; 
}

int partition(int arr[],int low,int high){
    int pivot=arr[high]; // Choosing last element as pivot
    int i=low-1;       // Index of smaller element
    
    for(int j=low; j<=high-1; j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i + 1],&arr[high]); // Place pivot at correct position
    return(i+1);
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr, low, high); // pi is partitioning index

        quickSort(arr,low,pi - 1);  // Sort elements before partition
        quickSort(arr,pi + 1,high); // Sort elements after partition
    }
}

void inputArray(int arr[],int n){
    printf("Enter %d elements : ", n);
    for(int i = 0; i < n; i++) 
         scanf("%d", &arr[i]);
}


void printArray(int arr[],int n){
    printf("The Sorted Array is : ");
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
}

int main() {
    int arr[20], n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    inputArray(arr, n);
    quickSort(arr,0,n-1);
    printArray(arr, n);
    return 0;
}

/* OUTPUT

Enter the number of elements : 6
Enter 6 elements : 78 92 61 34 28 98
The Sorted Array is : 28 34 61 78 92 98 
*/
