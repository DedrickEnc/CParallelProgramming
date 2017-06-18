/**
* this program is for using the combined directive parallel
* and for in for loup with the lastprivate and private clause.
**/

#include<stdio.h>
#include<omp.h>

int main(int argc, char const *argv[])
{
int n; //variable for iteration

#pragma omp parallel for lastprivate(n) //telling the compiler that n should have the value of the last iteration at the end
for(n=0; n<10; n++){
 //some code here
}
printf("Using last private The last value of n is: %d \n", n);

#pragma omp parallel for private(n) //with the private clause 
for(n=0; n<10; n++){
 //some code here
}
printf("Using private, The last value of n is: %d \n", n);
return 0;
}
