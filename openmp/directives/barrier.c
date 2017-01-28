/**
* this program is for illustrating the directive barrier and atomic
**/

#include<stdio.h>
#include<omp.h>

int doSum (int i){
 int sum = 0, ii;

 /**
 * every thread will handle some interaction (ii) independantly
 * but sum and i must be shared by every thread,
 * I can also put lastprivate(ii) instead of private
 **/ 
 #pragma omp parallel for private(ii) shared(sum, i)
 for (ii = 0; ii < i; ii++){
  #pragma omp atomic update //to update the sum properly
  sum+=ii; 
 } 

 //every thread must synchronize here, other wise the first thread will execute the return statement and interrupt the processing
 #pragma omp barrier 
 return sum;
}

int main(int argc, char const *argv[])
{

int i, sum = 0;

//calling the doSum function
int res = doSum(10);

for (i = 0; i < 10; i++){
  sum+=i; 
 } 



//printing the result
printf("the sum in parallel is %d \n", res);
printf("the sum in sequential is %d \n", sum);

return 0;
}
