// PROGRAM :
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

void bubbleSort(int arr[],int n){
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(arr[j]>arr[j+1]) 
               swap(&arr[j], &arr[j + 1]);
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
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}
 //OUTPUT :
Enter the number of elements : 5
Enter 5 elements : 8 7 3 5 6
The Sorted Array is : 3 5 6 7 8 

Enter the number of elements : 5
Enter 5 elements : 97 93 81 80 74
The Sorted Array is : 74 80 81 93 97
