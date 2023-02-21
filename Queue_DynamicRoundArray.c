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
//Q관련 함수
QueueType* CreateQueue()
{
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	if (!Q)
	{
		//만약 큐가 동적할당에 실패했다면!
		return NULL;
	}

	int size;
	printf("SIZE를 정해주세요(입력) : ");
	scanf("%d", &size);

	Q->capacity = size; //Queue의 크기

	Q->front = -1; //초기값
	Q->rear = -1;
	Q->array = (element*)malloc(sizeof(element) * Q->capacity);
	if (!Q->array)
	{
		//만약 큐안의 배열이 동적할당에 실패했다면!
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
		//만약 첫 데이터일 경우, -1임
		//그 경우
		Q->front = Q->rear;
	}

}

int isEmpty(QueueType* Q)
{
	return ((Q->front) == -1);
}

element deQueue(QueueType* Q)
{
	element data = 0; //어떤 값을 삭제하는가

	if (isEmpty(Q))
	{
		printf("[[Queue is empty]] ");

	}
	else
	{
		data = Q->array[Q->front];
		if (Q->front == Q->rear)
		{
			//공백 상태
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
		//Q가 NULL 이 아니라면
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
