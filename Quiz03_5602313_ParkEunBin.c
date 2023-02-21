#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define A_TERM 12
#define B_TERM 15
#define C_TERM 24
#define TASK_TERM 15

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

int main(void)
{
	srand(time(NULL));
	QueueType* myQ = CreateQueue();
	
	int a = 0;//몇번 수행이 됐는지 확인을 위해서
	int b = 0;
	int c = 0;
	
	
	int rand_ABC = 0;

	int curABC_term = 0;
	
	int fail = 0;
	int success = -1;

	//=======
	int minutes = 3600;//1시간 동안 돌아간다.

	for (int clock = 0; clock < minutes; clock++) //60초가 흘러간다는 것을..
	{
		curABC_term--;
		if (clock % TASK_TERM == 0) //총 시간에 15초를 나눈 나머지가 0이면.. 즉 15초마다
		{
			int trueFull = isFull(myQ);

			if (trueFull)
			{
				
				printf("a: %d	b: %d	c: %d\n", a, b, c);
				exit(1);
			}


			rand_ABC = rand() % 3; //0:A, 1:B, 2:C
			//rand_ABC = 2;
			switch (rand_ABC)
			{
			case 0:
				enQueue(myQ, A_TERM);
				a += 1;
				break;
			case 1:
				enQueue(myQ, B_TERM);
				b += 1;
				break;
			case 2:
				enQueue(myQ, C_TERM);
				c += 1;
				break;
			}

		}
		

		if (curABC_term <= 0 && !isEmpty(myQ))
		{
			//만약 공백이 아니라면..
			curABC_term = deQueue(myQ);
			success++;
		}
		
	}
	


	printf("a: %d	b: %d	c: %d\n", a, b, c);


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
	printf("CPU Queue Size : : ");
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

void  enQueue(QueueType* Q, element item)
{
	if (isFull(Q))
	{
		//printf("[[Queue Overflow]] ");

		//exit(1);
		

		//만약 오버플로우가 난다면..



	}
	else
	{
		Q->rear = (Q->rear + 1) % Q->capacity;
		Q->array[Q->rear] = item;

		if (Q->front == -1)
		{
			//만약 첫 데이터일 경우, -1임
			//그 경우
			Q->front = Q->rear;
		}
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
