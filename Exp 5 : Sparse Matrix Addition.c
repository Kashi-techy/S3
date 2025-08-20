//PROGRAM :
#include <stdio.h>

struct Element{
    int row, col, value;
};

void readSparse(struct Element mat[], int n, const char *name){
    printf("Enter elements for %s (row col value):\n", name);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &mat[i].row, &mat[i].col, &mat[i].value);
}

void printSparse(struct Element mat[], int size, const char *name){
    printf("\n%s in Triplet Form:\n", name);
    printf("%d %d %d\n", rows, cols, size)
    for (int i = 0; i < size; i++)
        printf("%3d %3d %5d\n", mat[i].row, mat[i].col, mat[i].value);
}

int addSparse(struct Element A[], int n1, struct Element B[], int n2, 
              struct Element result[], int rows, int cols){
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2){
        int posA = A[i].row * cols + A[i].col;
        int posB = B[j].row * cols + B[j].col;

        if(posA < posB) 
           result[k++] = A[i++];
        else if (posA > posB) result[k++] = B[j++];
        else{
            int sum = A[i].value + B[j].value;
            if (sum) result[k++] = (struct Element){A[i].row, A[i].col, sum};
            i++; j++;
        }
    }
    while (i < n1) 
     result[k++] = A[i++];
    while (j < n2) 
     result[k++] = B[j++];
    return k; // number of elements in result
}

int main(){
    int rows1, cols1, rows2, cols2, n1, n2;

    printf("Enter rows & columns of Matrix A: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter number of non-zero elements in Matrix A: ");
    scanf("%d", &n1);

    struct Element A[n1];
    readSparse(A, n1, "Matrix A");

    printf("\nEnter rows & columns of Matrix B: ");
    scanf("%d %d", &rows2, &cols2);

    if (rows1 != rows2 || cols1 != cols2){
        printf("Matrix dimensions must match for addition!\n");
        return 1;
    }

    printf("Enter number of non-zero elements in Matrix B: ");
    scanf("%d", &n2);
    struct Element B[n2];
    readSparse(B, n2, "Matrix B");

    struct Element result[n1 + n2];
    int k = addSparse(A, n1, B, n2, result, rows1, cols1);
    printSparse(result, k, "Matrix A + B");

    return 0;
}

/*OUTPUT :
Enter number of rows and columns of Matrix A: 3 3
Enter number of non-zero elements in Matrix A: 4
Enter elements for Matrix A (row col value):
0 0 6
0 1 7
2 0 8
1 1 8

Enter number of rows and columns of Matrix B: 3 3
Enter number of non-zero elements in Matrix B: 3
Enter elements for Matrix B (row col value):
0 0 8
0 1 5
2 0 1

Matrix A + B in Triplet Form:
Row Col Value
  0   0    14
  0   1    12
  2   0     9
  1   1     8


Enter rows & columns of Matrix A: 3 3
Enter number of non-zero elements in Matrix A: 5
Enter elements for Matrix A (row col value):
0 0 1
0 2 4
1 1 3
2 0 8
2 2 9

Enter rows & columns of Matrix B: 3 3
Enter number of non-zero elements in Matrix B: 3
Enter elements for Matrix B (row col value):
0 0 3
2 1 8
2 2 1

Matrix A + B in Triplet Form:
Row Col Value
  0   0     4
  0   2     4
  1   1     3
  2   0     8
  2   1     8
  2   2    10
*/
