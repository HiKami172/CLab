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

	double InscrRad = a / (2 * pow(3, 0.5)); //radius of circle inscribed in triangle of given side length
	double SmallTrian = r * 2 * pow(3, 0.5); //side length of triangle, which describes circle of given radius

	if (r > InscrRad)
		printf("No circles can be cut out!\n"); //given circle is larger than triangle
	else if (r == InscrRad)
		printf("Only one circle can be cut out!\n"); //given circle is inscribed in triangle
	else
	{
		int i = 2;
		while (SmallTrian*i <= a) //counting, in how many times given triangle's side length is greater than inscribed triangle's side length
			i++;
		i--; //we got number of small triangles, we can place near given triangle's side
		printf("%d circles can be cut out!\n", i * i); 
	}

	system("pause");
	return 0;
}