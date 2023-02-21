#include <stdio.h>

int Fibonacci(int n);

int main()
{
	//피보나치 수열
	//printf("%d", Fibonacci(6));
	printf("%d", Fib(6));

	return 0;
}

int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int Fib(int n)
{

	int p = 0;
	int pp = 1;
	int result = 0;

	for (int i = 2; i <= n; i++)
	{
		result = p + pp;
		p = pp;
		pp = result;
	}
	return result;
}