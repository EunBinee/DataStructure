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
		//짝수
		add_rear(myD, i);
		printf("add_rear 삽입 >> ");
		printQ(myD);
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		//짝수
		delete_rear(myD);
		printf("delete_rear 삭제 >> ");
		printQ(myD);
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		//짝수
		add_front(myD, i);
		printf("add_front 삽입 >> ");
		printQ(myD);
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		//짝수
		delete_front(myD);
		printf("delete_front 삭제 >> ");
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
		//만약 큐가 동적할당에 실패했다면!
		return NULL;
	}

	int size;
	printf("SIZE를 정해주세요(입력) : ");
	scanf("%d", &size);
	printf("\n");
	D->capacity = size; //Queue의 크기

	D->front = -1; //초기값
	D->rear = -1;
	D->array = (element*)malloc(sizeof(element) * D->capacity);
	if (!D->array)
	{
		//만약 큐안의 배열이 동적할당에 실패했다면!
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
			//만약 첫 데이터일 경우, -1임
			//그 경우
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
			//만약 첫 데이터일 경우, -1임
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
	return (D->front == D->rear); //만약 두개가 같다면 덱이 빈거임.
}

element delete_rear(DequeType* D)
{
	int pre = D->rear; //이전 rear의 값을 저장
	if (isEmpty(D))
	{
		printf("[[is empty]] ");

		D->rear = -1;
		D->front = -1;
	}
	else
	{
		//슬롯이 빈상태가 아닐 때만 실행.

		D->rear = (((D->rear - 1) + D->capacity) % D->capacity);
		
		//if (D->rear == 0)
		//{
		//	//만약 rear이 0인경우
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
			//만약 D와 front와 rear이 같다면, -1로 변환
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
		//만약 -1이면 공백 상태인거임.
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
