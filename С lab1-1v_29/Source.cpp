#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double a, r;
	printf("Enter triangle's side's length: ");
	scanf("%lf", &a);
	printf("Enter circle's radius: ");
	scanf("%lf", &r);

	double InscrRad = a / (2 * pow(3, 0.5));
	double SmallTrian = r * 2 * pow(3, 0.5);

	if (r > InscrRad)
		printf("No circles can be cut out!\n");
	else if (r == InscrRad)
		printf("Only one circle can be cut out!\n");
	else
	{
		int i = 2;
		while (SmallTrian*i <= a)
			i++;
		i--;
		printf("%d circles can be cut out!\n", (int)pow((float)i, 2));

	}

	system("pause");
	return 0;
}