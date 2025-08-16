#include <stdio.h>

int linearSearch(int arr[],int n,int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i; // Key found at index i
    }
    return -1; // Key not found
}

int main() {
    int arr[100], n, key, result;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    printf("Enter %d elements : ",n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the key to be searched : ");
    scanf("%d", &key);

    result = linearSearch(arr, n, key);

    if (result == -1)
        printf("Key NOT found.\n");
    else
        printf("Key FOUND at Index [%d]\n", result);

    return 0;
}

/* OUTPUT

Enter the number of elements : 5
Enter 5 elements : 98 47 56 23 31
Enter the key to be searched : 31
Key FOUND at Index [4]
*/
