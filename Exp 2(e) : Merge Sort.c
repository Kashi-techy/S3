#include <stdio.h>

void inputArray(int arr[], int n){
    printf("Enter %d elements : ", n);
    for (int i = 0; i < n; i++) 
      scanf("%d", &arr[i]);
}

void printArray(int arr[],int n){
    printf("The Sorted Array is : ");
    for (int i = 0; i < n; i++) 
      printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int left, int mid, int right){
    int n1=mid-left+1, n2=right-mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) 
      L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) 
      R[j] = arr[mid + 1 + j];

    int i=0, j=0, k=left;
    while(i<n1 && j<n2)
     arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i<n1) 
     arr[k++] = L[i++];
    while (j<n2) 
     arr[k++] = R[j++];
}

void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right - left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid + 1,right);
        merge(arr,left,mid,right);
    }
}

int main() {
    int arr[20], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    inputArray(arr, n);
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}

/*
OUTPUT
Enter the number of elements: 5
Enter 5 elements : 85 92 36 47 66
The Sorted Array is : 36 47 66 85 92 
*/
