#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>   //strlen�� ���ؼ�

void reverse(char* p, char* q);

int main()
{
	char s1[100], s2[100], * p, * q;
	printf("���ڿ� �Է�: ");
	scanf("%s", s1);

	p = &s1;
	q = &s2;

	reverse(p, q);
	printf("���� ���ڿ� : %s", s2);

	return 0;
}
void reverse(char* p, char* q)
{
	strcpy(q, p);  //*p�� ���� *q�� ����.
	int size = strlen(q);  //size�� ���ϱ�

	int j = size - 1;   //q[j]ó�� �ε����� ���� j

	for (int i = 0; i < size / 2; i++)
	{
		char temp = q[i];   //�������� �ٲٴ� ���� swap�� �̿�.
		q[i] = q[j];
		q[j] = temp;

		j--;  //�ε����� �ٿ��ݴϴ�.
	}	

}