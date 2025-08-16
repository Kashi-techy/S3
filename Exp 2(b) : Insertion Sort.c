// PROGRAM
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

void insertionSort(int arr[],int n){
   int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
     // Move elements greater than key one position ahead
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}

/*OUTPUT
Enter the number of elements : 4
Enter 4 elements : 78 69 13 24
The Sorted Array is : 13 24 69 78
*/
