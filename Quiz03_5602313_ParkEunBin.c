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
	
	int a = 0;//��� ������ �ƴ��� Ȯ���� ���ؼ�
	int b = 0;
	int c = 0;
	
	
	int rand_ABC = 0;

	int curABC_term = 0;
	
	int fail = 0;
	int success = -1;

	//=======
	int minutes = 3600;//1�ð� ���� ���ư���.

	for (int clock = 0; clock < minutes; clock++) //60�ʰ� �귯���ٴ� ����..
	{
		curABC_term--;
		if (clock % TASK_TERM == 0) //�� �ð��� 15�ʸ� ���� �������� 0�̸�.. �� 15�ʸ���
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
			//���� ������ �ƴ϶��..
			curABC_term = deQueue(myQ);
			success++;
		}
		
	}
	


	printf("a: %d	b: %d	c: %d\n", a, b, c);


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
	printf("CPU Queue Size : : ");
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

void  enQueue(QueueType* Q, element item)
{
	if (isFull(Q))
	{
		//printf("[[Queue Overflow]] ");

		//exit(1);
		

		//���� �����÷ο찡 ���ٸ�..



	}
	else
	{
		Q->rear = (Q->rear + 1) % Q->capacity;
		Q->array[Q->rear] = item;

		if (Q->front == -1)
		{
			//���� ù �������� ���, -1��
			//�� ���
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
