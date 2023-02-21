#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>

double Involution_Recursion(double x, int n);
double Involution_Iteration(double x, int n);

int main()
{
	int start_Time = 0, end_Time = 0;
	float time = 0.0f;
	double x;
	int n;
	printf("Input a base : ");
	scanf("%lf", &x);  //밑수를 받습니다.
	printf("\n");
	printf("Input an exponential : ");printf("Input an exponential : ");
	scanf("%d", &n);  //지수를 받습니다.
	printf("\n");

	start_Time = clock();  //시간을 계산합니다.
	printf("Using Recursion\n");
	printf("%.0lf to the power of %d is %.0lf\n", x, n, Involution_Recursion(x, n));  //순환을 이용한 함수
	end_Time = clock();
	time = (float)(end_Time - start_Time) / CLOCKS_PER_SEC;//시간을 계산합니다.
	printf("duration : %f\n\n", time);
	
	start_Time = 0;
	end_Time = 0;

	start_Time = clock();  //시간을 계산합니다.
	printf("Using Iteration\n");
	printf("%.0lf to the power of %d is %.0lf\n", x, n, Involution_Iteration(x, n));  //반복을 이용한 함수
	end_Time = clock();
	time = (float)(end_Time - start_Time) / CLOCKS_PER_SEC;  //시간을 계산합니다.
	printf("duration : %f\n\n", time);
	return 0;
}
double Involution_Recursion(double x, int n) //순환
{
	if (n == 0)
		return 1;
	else if ((n % 2) == 0) //짝수의 경우
		return Involution_Recursion(x * x, n / 2);
	else if ((n % 2 != 0))//홀수의 경우
		return x * Involution_Recursion(x * x, (n - 1) / 2);
}
double Involution_Iteration(double x, int n)  //반복
{
	double invol = 1.0f;
	for (int i = 1; i <= n; i++)
		invol *= x;

	return invol;
}