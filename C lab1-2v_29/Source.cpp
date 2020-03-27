#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	unsigned int n;
	printf("Enter natural number: ");
	scanf("%u", &n);
	int i = 2;
	int Numb = n % 10;
	bool Decr = 1;
	bool Incr = 1;
	bool Similar = 1;
	while (n / (int)pow(10.0, i-1) != 0)
	{
		int NumbI = (int)((double)(n % (int)pow(10.0, i)) / pow(10.0, i-1));
		if (NumbI < Numb)
		{
			Similar = 0;
			Decr = 0;
			Numb = NumbI;
		}
		else if (NumbI > Numb)
		{
			Similar = 0;
			Incr = 0;
			Numb = NumbI;
		}
		
		if (!Decr && !Incr)
		{
			printf("Neither decreasing nor increasing!\n");
			break;
		}

		i++;
	}
	
	if (Similar)
		printf("Neither decreasing nor increasing!\n");
	else
	{
		if (Decr)
			printf("Decreasing!\n");
		else if (Incr)
			printf("Increasing!\n");
	}
	system("pause");
	return 0;

}