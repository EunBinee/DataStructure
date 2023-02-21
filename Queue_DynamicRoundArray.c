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
}QueueType;

QueueType* CreateQueue();

int isFull(QueueType* Q);
void enQueue(QueueType* Q, element item);

int isEmpty(QueueType* Q);
element deQueue(QueueType* Q);

void deleteQueue(QueueType* Q);
void printQ(QueueType* Q);

int randomInt();

int main(void)
{
	QueueType* myQ = CreateQueue();

	for (int i = 0; i < 10; i++)
	{
		enQueue(myQ, i);
		printQ(myQ);
	}
	for (int i = 0; i < 15; i++)
	{
		deQueue(myQ);
		printQ(myQ);
	};

	deleteQueue(myQ);
	return 0;
}
//======================================
//Q���� �Լ�
QueueType* CreateQueue()
{
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	if (!Q)
	{
		//���� ť�� �����Ҵ翡 �����ߴٸ�!
		return NULL;
	}

	int size;
	printf("SIZE�� �����ּ���(�Է�) : ");
	scanf("%d", &size);

	Q->capacity = size; //Queue�� ũ��

	Q->front = -1; //�ʱⰪ
	Q->rear = -1;
	Q->array = (element*)malloc(sizeof(element) * Q->capacity);
	if (!Q->array)
	{
		//���� ť���� �迭�� �����Ҵ翡 �����ߴٸ�!
		return NULL;
	}

	return Q;
}

int isFull(QueueType* Q)
{
	return ((Q->rear + 1) % Q->capacity == Q->front);
}

void enQueue(QueueType* Q, element item)
{
	if (isFull(Q))
	{
		printf("[[Queue Overflow]] \n");
		Q->capacity *= 2;
		Q->array = (element*)realloc(Q->array, sizeof(element) * Q->capacity);
	}
	Q->rear = (Q->rear + 1) % Q->capacity;
	Q->array[Q->rear] = item;

	if (Q->front == -1)
	{
		//���� ù �������� ���, -1��
		//�� ���
		Q->front = Q->rear;
	}

}

int isEmpty(QueueType* Q)
{
	return ((Q->front) == -1);
}

element deQueue(QueueType* Q)
{
	element data = 0; //� ���� �����ϴ°�

	if (isEmpty(Q))
	{
		printf("[[Queue is empty]] ");

	}
	else
	{
		data = Q->array[Q->front];
		if (Q->front == Q->rear)
		{
			//���� ����
			Q->front = -1;
			Q->rear = -1;
		}
		else
		{
			Q->front = ((Q->front + 1) % Q->capacity);
		}
	}
	return data;
}

void deleteQueue(QueueType* Q)
{
	if (Q) {
		//Q�� NULL �� �ƴ϶��
		if (Q->array)
			free(Q->array);
	}
	free(Q);
}


void printQ(QueueType* Q)
{
	if (isEmpty(Q))
	{
		printf("[[Queue is empty]] ");
	}
	printf("front: %d, rear: %d, Circular Queue: [ ", Q->front, Q->rear);

	int i = Q->front;

	while (i % (Q->capacity) != Q->rear % (Q->capacity))
	{
		printf("%d ", Q->array[i % (Q->capacity)]);
		i++;
	}
	printf("%d ", Q->array[(Q->rear)]);

	printf("]\n");
}
