/**
* this program is for using the combined directive parallel
* and for in for loup without the lastprivate clause.
**/

#include<stdio.h>
#include<omp.h>

int main(int argc, char const *argv[])
{
#pragma omp parallel sections //telling the compiler to split the following code block to different threads
{
/** I will put my sections here **/

#pragma omp section //section 1
{
 printf("section1 executed by thread %d \n", omp_get_thread_num());
}

#pragma omp section //section 2
{
 printf("section2 executed by thread %d \n", omp_get_thread_num());
}

}
return 0;
}
