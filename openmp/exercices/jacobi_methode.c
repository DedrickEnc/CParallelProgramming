/**
* This implementation is for Jacobi method, the Jacobi methode is a iterative method
* to solve a equation sytem with many variables (AX = b). The goal is to find an approximative 
* solution whith is very near the real solution. During the the processing the serie of vector
* will be generated, and the oteration sill stop when the very accurated vector will be found.
* for that we will need a initial vector
**/

#include <stdio.h>
#include <math.h>

/**
* This function do a test to check if
* the matrix is a diagonal strictement dominant
**/
int jacobiTest(int n, float A[n][n])
{
    int pass = 1;

    int i, j;
    float sum;
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
        {
            if (j != i)
            {
                sum += abs(A[i][j]);
            }
        }

        if (abs(A[i][i]) <= sum)
        {
            pass *= 0; //element absorbant pour *
            break;
        }
    }

    return pass;
}

/**
* This function is testin if the vector x found satify the condition ||Ax-b|| < e
* if so the vector is very near of the solution and the iteration an stop, otherwise
* the fact that the MAXITER is reached, the function will stop
**/
int testArret (int n, float A[n][n], float Xnew[n], float b[n], float e, int nb, int MAXITER)
{
    int i, j, k;
    float AXnew[n];
    float V[n];      //this vector will contains the AXnew - b result
    double norme = 0; // will contain ||AX - b||

    // test if the max number of iteraion have been reached
    if (nb == MAXITER)
    {
        return 1;
    }

    // doing A * Xnew

    for (i = 0; i < n; i++)
    {
        // As Xnew is a vector, is length is 1, so j < 1
        for (j = 0; j < 1; j++)
        {
            AXnew[i] = 0;

            for (k = 0; k < n; k++)
            {
                AXnew[i] += A[i][k] * Xnew[k];
            }
        }
    }

    // now doing AXnew - b
    for (i = 0; i < n; i++)
    {
        V[i] = AXnew[i] - b[i];
    }

    // now doing ||V||
    for (i = 0; i < n; i++)
    {
        norme += (V[i] * V[i]);
    }

    norme = sqrt(norme);

    if(norme < e){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    float A[2][2] = {{3, 1}, {1, 2}}; // the matrix A of the system AX = b
    float b[] = {5, 1};               // the vector b of the system AX = b
    float Xo[] = {1, 1};              // the vector initial to begin iteration
    int n = 2;                        // the dimentsion of the system, A is a square matrix. so number line or column
    float e = 0.0000001;              //the epsillon, tolerence value
    int MAXITER = 100;                //number of ietration
    float Xnew[2];                    // the new vector
    float Xold[2];                   // the old vector
    int i, j;
    int nb = 0; // for iterate in a loop
    float sum; //to calculate a intermediate sum

    if (jacobiTest(n, A) == 1)
    {
        printf("the test pass so the jacobi mthode can provid a solution\n");
        // Xnew <-- Xo
        for (i = 0; i < n; i++)
        {
            Xnew[i] = Xo[i];
        }

        nb = 0;
        while (testArret(n, A, Xnew, b, e, nb, MAXITER) == 0)
        {
            nb += 1;

            // new current Xnew is not a good vector, so it is stored as old
            for(i = 0; i< n; i++){
                Xold[i] = Xnew[i];
            }

            for(i = 0; i< n; i++){
                sum = 0;

                for(j = 0; j< n; j++){
                    if(i != j){
                    sum += A[i][j] * Xold[j];
                    }                    
                }
                Xnew[i] = (b[i] - sum) / A[i][i];                
            }
        }

        for(i=0; i<n; i++){
            printf("%f\t", Xnew[i]);
        }

        printf("\n nombre total iteration %d", nb);
    }
}