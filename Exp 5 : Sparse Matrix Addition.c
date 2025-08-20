//PROGRAM :
#include <stdio.h>

struct Element {
    int row;
    int col;
    int value;
};

void readSparse(struct Element mat[], int n, const char *name){
    printf("Enter elements for %s (row col value):\n", name);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &mat[i].row, &mat[i].col, &mat[i].value);
}

void printSparse(struct Element mat[], int size, const char *name, int rows, int cols){
    printf("\n%s in Tuple Form:\n", name);
    // First row: rows, cols, no of non-zero elements
    printf("%d %d %d\n", rows, cols, size);

    // Then print all non-zero elements

    for (int i = 0; i < size; i++)
        printf("%d %d %d\n", mat[i].row, mat[i].col, mat[i].value);
}
int addSparse(struct Element A[], int n1, struct Element B[], int n2, 
              struct Element result[], int rows, int cols){
    int i=0,j=0,k=0;
    while (i < n1 && j < n2){
        int posA = A[i].row * cols + A[i].col;
        int posB = B[j].row * cols + B[j].col;

        if(posA < posB) 
           result[k++] = A[i++];
        else if (posA > posB) 
           result[k++] = B[j++];
        else{
            int sum = A[i].value + B[j].value;
            if (sum) 
                result[k++] = (struct Element){A[i].row, A[i].col, sum};
            i++; j++;
        }
    }
    while (i < n1) 
        result[k++] = A[i++];
    while (j < n2) 
        result[k++] = B[j++];
    return k; // number of elements in result
}

int main() {
    int rows1, cols1, rows2, cols2, n1, n2;

    // Input matrix 1
    printf("Enter number of rows, columns and number of non-zero elements of Matrix A: ");
    scanf("%d %d %d", &rows1, &cols1, &n1);


    struct Element A[n1];
    readSparse(A, n1, "Matrix A");

    // Input matrix 2
    printf("Enter number of rows, columns and number of non-zero elements of Matrix B : ");
    scanf("%d %d %d", &rows2, &cols2, &n2);


    struct Element B[n2];
    readSparse(B, n2, "Matrix B");

    // Resultant matrix
    struct Element result[n1 + n2];
    int k = addSparse(A, n1, B, n2, result, rows1, cols1);

    // Pass rows1 and cols1 to printSparse to print the header row
    printSparse(result, k, "Matrix A + B", rows1, cols1);


    return 0;
}

/*OUTPUT :
Enter number of rows, columns and number of non-zero elements of Matrix A: 3 3 4
Enter elements for Matrix A (row col value):
0 0 6
0 1 7
2 0 8
1 1 8
Enter number of rows, columns and number of non-zero elements of Matrix B : 3 3 3
Enter elements for Matrix B (row col value):
0 0 8
0 1 5
2 0 1

Matrix A + B in Tuple Form:
3 3 4
0 0 14
0 1 12
2 0 9
1 1 8

*/
