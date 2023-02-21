#include<stdio.h>

double Involution(double x, int n);
int main()
{
	double x = 2.0;
	int n = 10;
	double result;
	result = Involution(x, n);  //x^n
	printf("%.1lf", result);
	return 0;
}
double Involution(double x, int n)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return Involution(x * x, n / 2);
	else
		return x * Involution(x * x, (n - 1) / 2);
}