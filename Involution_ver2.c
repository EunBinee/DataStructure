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
	scanf("%lf", &x);  //�ؼ��� �޽��ϴ�.
	printf("\n");
	printf("Input an exponential : ");printf("Input an exponential : ");
	scanf("%d", &n);  //������ �޽��ϴ�.
	printf("\n");

	start_Time = clock();  //�ð��� ����մϴ�.
	printf("Using Recursion\n");
	printf("%.0lf to the power of %d is %.0lf\n", x, n, Involution_Recursion(x, n));  //��ȯ�� �̿��� �Լ�
	end_Time = clock();
	time = (float)(end_Time - start_Time) / CLOCKS_PER_SEC;//�ð��� ����մϴ�.
	printf("duration : %f\n\n", time);
	
	start_Time = 0;
	end_Time = 0;

	start_Time = clock();  //�ð��� ����մϴ�.
	printf("Using Iteration\n");
	printf("%.0lf to the power of %d is %.0lf\n", x, n, Involution_Iteration(x, n));  //�ݺ��� �̿��� �Լ�
	end_Time = clock();
	time = (float)(end_Time - start_Time) / CLOCKS_PER_SEC;  //�ð��� ����մϴ�.
	printf("duration : %f\n\n", time);
	return 0;
}
double Involution_Recursion(double x, int n) //��ȯ
{
	if (n == 0)
		return 1;
	else if ((n % 2) == 0) //¦���� ���
		return Involution_Recursion(x * x, n / 2);
	else if ((n % 2 != 0))//Ȧ���� ���
		return x * Involution_Recursion(x * x, (n - 1) / 2);
}
double Involution_Iteration(double x, int n)  //�ݺ�
{
	double invol = 1.0f;
	for (int i = 1; i <= n; i++)
		invol *= x;

	return invol;
}