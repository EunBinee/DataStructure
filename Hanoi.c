#include <stdio.h>


void hanoi(int n, char from, char temp, char to)
{
	if (n == 1)
		printf("%d�� %c���� %c�ű�ϴ�.\n", n, from, to);
	else
	{
		hanoi(n - 1, from, to, temp);
		printf("%d�� %c���� %c�ű�ϴ�.\n", n, from, to);
		hanoi(n - 1, temp, from, to);
	}

}

int main()
{
	hanoi(12, 'A', 'B', 'C');
	return 0;
}