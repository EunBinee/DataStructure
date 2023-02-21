#include <stdio.h>
#include <time.h>

int Factorial(int num); //Factorial 코드
int Iteration(int num); //Interation 코드

int main(void)
{
	int start_time = 0, end_time = 0;
	float time = 0.0f;
	
	start_time = clock();
	
	int num = 0;
	int tempnum = 17; //몇 번 곱할 건가요?

	//팩토리얼 구하는 곳!!
	num = Factorial(tempnum);
	printf("Use Interation\n%d! = %d\n\n", tempnum, num);
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("duration : %f", time);

	//Iteration
	start_time = clock();
	num = Iteration(tempnum);
	printf("Use Interation\n%d! = %d\n\n", tempnum, num);

	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;

	printf("duration : %f", time);
	
	return 0;
}

int Factorial(int num)
{
	if (num == 1)
		return 1;
	else
		return num * Factorial(num - 1);
}
int Iteration(int num)
{
	int a = 1;
	for (int i = 1; i <= num; i++)
		a *= i;
	return a;
}