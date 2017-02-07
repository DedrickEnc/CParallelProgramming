/**
* This program do the integral process
* folowing the riemman method
**/

#include<stdio.h>
#include<math.h>
#include<omp.h>

double carre (double x){
	return x * x;
}

int main()
{
	float e; //precision

	// the interval length, air with mj as heigth, air with MJ as height, first element of small interval
	// second element of small interval, image of small element of the current interval
	// image of the biggest element of the current interval, born a, born b, 
	//number of rectangle built, number of retctable to add each iteration
	double l, Ii, Is, xb1, xb2, mj, MJ, a, b, n, c;

	int i, comptor = 0;

	//initialization

	a = 0.0; b = 5.0; e = 0.001;  n = 1.0; c = 1.0;

	do{
		Ii = 0; Is = 0; //init Ii and Is in zero
		n = n + c; //increasing the rectangle number
		l = (b - a) / n; //length of each intervall


		for (i = 0; i < n; i++)
		{
			xb1 = a + (i * l);
			xb2 = a + ((i + 1) * l);

			mj = carre(xb1);
			MJ = carre(xb2);

			Ii += ((xb2 - xb1) * mj);
			Is += ((xb2 - xb1) * MJ);
		}

		printf("the iteration %d \n", comptor++);

	}while(fabs(Is - Ii) > e);

	printf("Ii is : %f and Is is : %f \n", Ii, Is);

	return 0;
}

