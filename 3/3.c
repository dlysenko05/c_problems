#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535897932384626433
#define _USE_MATH_DEFINES
void main()
{
	double MIN_DOUBLE = 0;
	double MAX_DOUBLE = 1000000000000000;
	int flag = 1;
	int n = -1;
	int m;
	int counter = 1;
	double pi;
	char ch;
	printf("This program calculates the value of pi based on the number of needed digits after the comma.\n");
	printf("%f\n", PI);
	while (flag)
	{
		while (n < MIN_DOUBLE || n > MAX_DOUBLE)
		{
			printf("Please enter number of digits after the comma:\n");
			scanf("%d", &n);
		}
		m = n;
		while ((fabs(pi-PI)) > pow(10,-(n+1)))
		{
			pi = 0;
			for (int i=1; i<=m; i+=2)
			{
				double temp;
				temp = (double) 4/i;
				if (counter % 2 != 0) pi += temp;
				else pi -= temp;
				counter++;
			}
			m+=100000000;
			// printf("%f\n", pi);
		}
		/* if ((pi-PI) > pow(10,-(n+1)))
		{
			pi -= pow(10, -n);
		}
		else
		{
			if ((pi-PI) < pow(10,-(n+1)))
			{
				pi += pow(10, -n);
			}
		}
		*/
		// printf("%f\n", pi);
		double pi_rounded = (double) floor(pow(10,n)*pi)/pow(10,n);
		printf("%.*f\n", n, pi_rounded);
		printf("Do you want to continue? (y or n)\n");
		scanf("%c", &ch);
		if (ch != 'y') flag = 0;
	}
}
