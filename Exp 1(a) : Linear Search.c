/*ALGORITHM 
1. Start.
2. Input the number of elements n.
3. Input the array arr[0..n-1].
4. Input the search key key.
5. Initialize index variable i = 0.
6. Repeat until i < n:
   a. If arr[i] == key, then
     Return i (key found at index i).
   b. Otherwise, increment i by 1.
7. If end of array is reached without finding key, return -1.
8. Stop */
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
