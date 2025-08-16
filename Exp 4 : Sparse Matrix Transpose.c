//PROGRAM :
#include <stdio.h>

struct Element 
{
    int row, col, value;
};

// Swap function
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{
    int rows, cols, no_nonzero;

    printf("Enter the no of rows : ");
    scanf("%d", &rows);

    printf("Enter the no of columns : ");
    scanf("%d", &cols);

    printf("Enter the no of non-zero elements : ");
    scanf("%d", &no_nonzero);

    struct Element org[no_nonzero];
    struct Element transposed[no_nonzero];

    printf("Enter each element as : row column value\n");
    for (int i = 0; i < no_nonzero; i++) 
    {
        scanf("%d %d %d", &org[i].row, &org[i].col, &org[i].value);
    }

    int k = 0;

    // Transpose logic using swap
    for (int c = 0; c < cols; c++){
        for (int i = 0; i < no_nonzero; i++){
            if (org[i].col == c){
                transposed[k] = org[i];      // copy element
                swap(&transposed[k].row, &transposed[k].col);  // swap row & col
                k++;
            }
        }
    }

    printf("\nTransposed Sparse Matrix in Triplet form:\n");
    printf("Row Column Value\n");
    for (int i = 0; i < no_nonzero; i++) 
        printf("%3d %6d %5d\n", transposed[i].row, transposed[i].col, transposed[i].value);
    return 0;
}


/*OUTPUT :
Enter the no of rows : 3 
Enter the no of cols : 3
Enter the no of non-zero elements : 4
Enter each element as : row column value
0 0 5
0 2 8
1 1 3
2 0 6

Transposed Sparse Matrix in Triplet form:
Row Column Value
  0      0     5
  0      2     6
  1      1     3
  2      0     8

Enter the no of rows : 3
Enter the no of columns : 4
Enter the no of non-zero elements : 4
Enter each element as : row column value
0 0 4
1 1 5
2 1 8
3 0 9

Transposed Sparse Matrix in Triplet form:
Row Column Value
  0      0     4
  0      3     9
  1      1     5
  1      2     8

*/
