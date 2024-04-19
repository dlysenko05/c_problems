#include <stdio.h>
#include <math.h>

void main()
{
	int n=1, counter=0;
	char ch = 'c';
	printf("This program prints all prime numbers <= n.\n");
	while (n)
	{
		printf("Choose mode: standard or optimal ('s' or 'o'):\n");
		ch = getchar(); // can we use scanf() here? It works but is there any difference in this case?
		// scanf("%c", &ch);
		getchar(); // "eating" the previous newline
		if (ch == 's' || ch == 'o') n = 0;
	}
	while (n <= 2)
	{
		printf("Enter n (n > 2):\n");
		scanf("%d", &n);
	}

	if (ch == 'o') printf("2\n");
	for (int i=2; i<=n; i++)
	{
		if (ch == 's')
		{
			for (int j=1; j<=i; j++)
			{
				// if (i%j == 0) counter += 1;
				float div = (double) i/j;
				if ((div - (i/j)) == 0) counter += 1;
			}
			if (counter == 2) printf("%d\n", i);
		}
		else // Eratosthenes' sieve
		{
			for (int j=2; j<=(int)sqrt(i)+1; j++)
			{
				if (i%j == 0) counter += 1;
			}
			if (counter == 0) printf("%d\n", i);
		}
		counter = 0;
	}
}
