#include <stdio.h>
#include <math.h>

void main()
{
	int a,b,c;
	float x1,x2;
	printf("This program solves quadratic eqations (only on real numbers field)\n");
	printf("Enter a,b,c:\n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	if (a == 0) // linear equation
	{
		if (b == 0)
		{
			if (c == 0)
			{
				printf("Infinite solutions!\n");
				return;
			}
			else
			{
				printf("No solutions!\n");
				return;
			}
		}
		else
		{
			x1 = x2 = (-(float)c/b);
		}
	}
	else
	{
		float d = b*b - 4*a*c;
		if (d >= 0)
		{
			float sqrt_d = sqrt(d);
			x1 = (float)((-b + sqrt_d)/(2*a));
			x2 = (float)((-b - sqrt_d)/(2*a));
		}
		else
		{
			printf("No real solutions!\n");
			return;
		}
	}
	if (x1 == x2)
	{
		printf("x = %f\n", x1);
	}
	else
	{
		printf ("x1 = %f, x2 = %f\n", x1, x2);
	}
}
