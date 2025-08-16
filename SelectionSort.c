#include <stdio.h>

void swap(int *a, int *b){
  int t = *a; 
  *a = *b; 
  *b = t; 
}

void inputArray(int arr[],int n){
    printf("Enter %d elements : ", n);
    for(int i = 0; i < n; i++) 
         scanf("%d", &arr[i]);
}

void selectionSort(int arr[],int n){
    int i,j,min_idx;
    
    for(i=0;i<n-1;i++){
        min_idx = i;
        // Find the minimum element in the unsorted part
        for(j=i+1;j<n;j++){
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum with the first element
        swap(&arr[i], &arr[min_idx]); 
        }
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
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
