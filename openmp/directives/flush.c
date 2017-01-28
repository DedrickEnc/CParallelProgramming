/**
* this program is for using the flush directive
**/

#include<stdio.h>
#include<omp.h>

int main(int argc, char const *argv[])
{
int a, b, tmp;

a = b = 0;

//The following block will be processed in parallel by two threads
#pragma omp parallel num_threads(2)
{

 //if processed by the master thread
 if(omp_get_thread_num() == 0){
  //properly assign value 1 to b
     b = 1;

  //flushing a and b
  #pragma omp flush (a, b)
       tmp = a;

  if(tmp == 0)
  {
    printf("In master, tmp is %d as expected \n", tmp);
  }
 }

 //if processed by the slave thread
 if(omp_get_thread_num() != 0){
  //properly assign value 1 to a
    a = 1;

  //flushing a and b
  #pragma omp flush (a, b)
       tmp = b;

  if(tmp == 0)
  {
    printf("In slave, tmp is %d as expected \n", tmp);
  }
 }
}

return 0;
}
