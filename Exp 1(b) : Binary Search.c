/*ALGORITHM
1. Start.
2. Input the number of elements n.
3. Input the sorted array arr[0..n-1].
4. Input the search key key.
5. Initialize low = 0, high = n-1.
6. Repeat until low <= high:
   a. Compute mid = (low + high) / 2.
   b. If arr[mid] == key, return mid (key found at index mid).
   c. Else if key < arr[mid], set high = mid - 1 (search left half).
   d. Else, set low = mid + 1 (search right half).
7. If low > high, return -1 (key not found).
8. Stop.*/
#include <stdio.h>

// Recursive binary search function
int binarySearch(int arr[],int low,int high,int key) {
    if (low > high)
        return -1; // Key not found

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key); // Search left half
    else
        return binarySearch(arr, mid + 1, high, key); // Search right half
}

int main() {
    int arr[100], n, key, result;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    printf("Enter %d elements in SORTED order : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the key to be searched : ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, n-1, key);

    if (result == -1)
        printf("Key NOT found.\n");
    else
        printf("Key found at Index [%d].\n", result);

    return 0;
}

/* OUTPUT

Enter the number of elements : 5
Enter 5 elements in SORTED order : 12 27 56 68 95
Enter the key to be searched : 68
Key found at Index [3].

*/
