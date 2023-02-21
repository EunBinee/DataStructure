#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>   //strlen을 위해서

void reverse(char* p, char* q);

int main()
{
	char s1[100], s2[100], * p, * q;
	printf("문자열 입력: ");
	scanf("%s", s1);

	p = &s1;
	q = &s2;

	reverse(p, q);
	printf("역순 문자열 : %s", s2);

	return 0;
}
void reverse(char* p, char* q)
{
	strcpy(q, p);  //*p의 값을 *q에 복사.
	int size = strlen(q);  //size를 구하기

	int j = size - 1;   //q[j]처럼 인덱스로 쓰일 j

	for (int i = 0; i < size / 2; i++)
	{
		char temp = q[i];   //역순으로 바꾸는 것은 swap을 이용.
		q[i] = q[j];
		q[j] = temp;

		j--;  //인덱스를 줄여줍니다.
	}	

}