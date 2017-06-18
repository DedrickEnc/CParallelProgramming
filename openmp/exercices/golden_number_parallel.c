/**
* This program is looking for a number called 
* Golden number which is the substration between 
* two different suits, the parallelism with do-while
* is almost impossible, the last section of this program is 
* very unstable
**/

#include<stdio.h>
#include<math.h>
#include<omp.h>

int main()
{
	/* code */

	int j, avderu, deru, nouvu, stop;
	float e, derv, nouvv;
	omp_lock_t lk;

	omp_init_lock(&lk);

	/** initialization **/
	avderu = 1; deru = 2; derv = 2; j = 2;
	stop = 0; e = 0.01;

	do{
		j = j+1;
		nouvu = avderu + deru;
		nouvv = nouvu/deru;

		if(fabs(nouvv - derv) >= e) {
			avderu = deru;
			deru = nouvu;
			derv = nouvv;
		}else{
			stop = 1;
		}

	}while(stop == 1);

	printf("the  term is %f and the iteration is %d \n", nouvv, j);

	//parallel version sections

	/** initialization **/
	avderu = 1; deru = 2; derv = 2; j = 2;
	stop = 0; e = 0.01;

	#pragma omp parallel sections
	{	
		#pragma omp section 
		{
			do{
				// #pragma omp atomic update
				j = j+1;

				nouvu = avderu + deru;
				nouvv = nouvu/deru;

				if(fabs(nouvv - derv) >= e) {
					avderu = deru;
					deru = nouvu;
					derv = nouvv;
				}else{
					// #pragma omp critical
					stop = 1;
				}

			}while(stop == 1);
        }
    }	

	printf("In parallel the term %f and the iteration is %d \n", nouvv, j);

	/** initialization **/
	avderu = 1; deru = 2; derv = 2; j = 2;
	stop = 0; e = 0.01;

	#pragma omp parallel
	{
			do{
				#pragma omp master
				j = j+1;
				printf("iteration %d \n", j);

				// omp_set_lock(&lk);				
				nouvu = avderu + deru;
				nouvv = nouvu/deru;
				// omp_unset_lock(&lk);

				if(fabs(nouvv - derv) >= e) {
					avderu = deru;
					deru = nouvu;
					derv = nouvv;
				}else{
					#pragma omp master
					stop = 1;
				}

			}while(stop == 1);
    }	

	printf("In parallel without section the term %f and the iteration is %d \n", nouvv, j);

	return 0;
}