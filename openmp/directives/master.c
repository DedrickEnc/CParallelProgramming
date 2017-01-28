/**
* this program is for using the directive parallel
* and master.
**/

#include<stdio.h>
#include<omp.h>

int main(int argc, char const *argv[])
{
int n, n0; //variable for iteration

//telling the compiler that he should execute the following for loop by the master thread

n0 = omp_get_wtime(); //second passed from a fixed moment until now

#pragma omp parallel
{
#pragma omp master
 {
  printf("The thread should be the master which is : %d \n", omp_get_thread_num());
  n = omp_get_wtime() - n0;
 }

 //outside the directive master, this instruction will be executed by many thread in parallel
 printf("the time passed is %d executed by the thread %d \n", n, omp_get_thread_num());
}
return 0;
}
