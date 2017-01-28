/**
* this program is for using the ordered directive
**/

#include<stdio.h>
#include<omp.h>

int main(int argc, char const *argv[])
{
 float intermediate = 0, sum;
int i;

 #pragma omp parallel for ordered private(intermediate) 
	 for(i=0; i<10; i++){
	  #pragma omp ordered
	   {
	    sum = intermediate +sum;
	    
	   }

	 } 

return 0;
}
