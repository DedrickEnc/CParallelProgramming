/**
* this program is for using the single directive
**/

#include<stdio.h>
#include<omp.h>

int main(int argc, char const *argv[])
{
int n; //variable for iteration
int sum = 0, sum2 = 0;

#pragma omp parallel for //telling the compiler to execute the following bloc in parallel

for(n=0; n<10; n++){
 printf("iteration %d performed by the thread : %d \n", n, omp_get_thread_num());
 sum+=n;
}
printf("The sum parallel is: %d \n", sum);

#pragma omp parallel
{
 #pragma omp single //telling the compiler that only one thread will execute this block
  {
   for(n=0; n<10; n++){
    printf("iteration %d performed by the thread : %d \n", n, omp_get_thread_num());
    sum2+=n;
   }
   printf("The sum single is: %d \n", sum2); 
  }
} 

return 0;
}
