// multiplication de deux matrice

#include <stdio.h>

int main()
{
    int linA = 2, colA = 2, linB = 2, colB = 3; //init lines a column of matrix A and B
    int A[2][2] = {{2, -3}, {-1, 2}};     //initilization first matrix
    int B[2][3] = {{3, 1, 2}, {1, 0, 2}}; //init second matrix

    int C[linA][colB];
    int i, j, k;

    if (colA == linB)
    {
        printf("%s\n", "the multiplication is possible");

        for (i = 0; i < linA; i++)
        {
            for (j = 0; j < colB; j++)
            {
                C[i][j] = 0;

                for (k = 0; k < colA; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        // just for displaying

        for (i = 0; i < linA; i++)
        {
            for (j = 0; j < colB; j++)
            {
                printf("%d\t", C[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("the multiplication is not possible colA not euqls to linB");        
    }

    return 0;
}
