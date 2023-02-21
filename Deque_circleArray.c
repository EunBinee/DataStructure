#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef int element;
typedef struct QueueType
{
	int front, rear;
	int capacity;
	element* array;
}DequeType;

DequeType* CreateDeque();
int isFull(DequeType* D);
void add_rear(DequeType* D, element item);
void add_front(DequeType* D, element item);
int isEmpty(DequeType* D);
element delete_rear(DequeType* D);
element delete_front(DequeType* D);
void printQ(DequeType* D);
int main(void)
{
	DequeType* myD = CreateDeque();
	for (int i = 0; i < 6; i++)
	{
		//¦��
		add_rear(myD, i);
		printf("add_rear ���� >> ");
		printQ(myD);
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		//¦��
		delete_rear(myD);
		printf("delete_rear ���� >> ");
		printQ(myD);
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		//¦��
		add_front(myD, i);
		printf("add_front ���� >> ");
		printQ(myD);
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		//¦��
		delete_front(myD);
		printf("delete_front ���� >> ");
		printQ(myD);
	}

	return 0;
}

DequeType* CreateDeque()
{
	DequeType* D;
	D = (DequeType*)malloc(sizeof(DequeType));
	if (!D)
	{
		//���� ť�� �����Ҵ翡 �����ߴٸ�!
		return NULL;
	}

	int size;
	printf("SIZE�� �����ּ���(�Է�) : ");
	scanf("%d", &size);
	printf("\n");
	D->capacity = size; //Queue�� ũ��

	D->front = -1; //�ʱⰪ
	D->rear = -1;
	D->array = (element*)malloc(sizeof(element) * D->capacity);
	if (!D->array)
	{
		//���� ť���� �迭�� �����Ҵ翡 �����ߴٸ�!
		return NULL;
	}

	return D;
}
int isFull(DequeType* D)
{
	return ((D->rear+1) % D->capacity == D->front);
}

void add_rear(DequeType* D, element item)
{
	if (isFull(D))
	{
		printf("[[Overflow]] ");
	}
	else
	{
		D->rear = (D->rear + 1) % D->capacity;
		D->array[D->rear] = item;

		if (D->front == -1)
		{
			//���� ù �������� ���, -1��
			//�� ���
			D->front = D->rear;
		}
	}
}
void add_front(DequeType* D, element item)
{
	if (isFull(D))
	{
		printf("[[Overflow]] ");
	}
	else
	{
		if (D->rear == -1|| D->front == -1)
		{
			//���� ù �������� ���, -1��
			D->front = (D->front + 1) % D->capacity;
			D->array[D->front] = item;
			D->rear = D->front;
		}
		else
		{
			D->front = ((D->front - 1) + D->capacity) % D->capacity;
			D->array[D->front] = item;
		}
	}
}

int isEmpty(DequeType* D)
{
	return (D->front == D->rear); //���� �ΰ��� ���ٸ� ���� �����.
}

element delete_rear(DequeType* D)
{
	int pre = D->rear; //���� rear�� ���� ����
	if (isEmpty(D))
	{
		printf("[[is empty]] ");

		D->rear = -1;
		D->front = -1;
	}
	else
	{
		//������ ����°� �ƴ� ���� ����.

		D->rear = (((D->rear - 1) + D->capacity) % D->capacity);
		
		//if (D->rear == 0)
		//{
		//	//���� rear�� 0�ΰ��
		//	D->rear = (((D->rear - 1) + D->capacity) % D->capacity);
		//}
		//else
		//	D->rear = ((D->rear - 1) + D->capacity) % D->capacity;
	}

	return D->array[pre];
}

element delete_front(DequeType* D)
{
	int pre = D->front;
	if (isEmpty(D))
	{
		printf("[[is empty]] ");
		D->rear = -1;
		D->front = -1;
	}
	else
	{
		if (D->front == D->rear)
		{
			//���� D�� front�� rear�� ���ٸ�, -1�� ��ȯ
			D->rear = -1;
			D->front = -1;
		}
		else
			D->front = (D->front + 1) % D->capacity;
	}

	return D->array[pre];
}

void printQ(DequeType* D)
{
	printf("front: %d, rear: %d, Circular Queue: [ ", D->front, D->rear);
	if (D->front == -1)
	{
		//���� -1�̸� ���� �����ΰ���.
	}
	else
	{
		int i = D->front;

		while (i % (D->capacity) != D->rear % (D->capacity))
		{
			printf("%d ", D->array[i % (D->capacity)]);
			i++;
		}
		printf("%d ", D->array[(D->rear)]);

	}
	
	printf("]\n");
}
