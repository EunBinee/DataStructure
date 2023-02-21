#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define T_NUM 5000 //몇번 PUSH할 것인지
#define MAX_STACK_SIZE 5   //DynamicArray의 최대 스택값
typedef int element;
//===============================================================================
//DynamicRoundArray

typedef struct QueueType
{
	int front, rear;
	int capacity;
	element* array;
}QueueType;

QueueType* CreateQueue_DA();
int isFull_DA(QueueType* Q);
void enQueue_DA(QueueType* Q, element item);

//===============================================================================
//SinglyLinkedList
typedef struct ListNode {
	//스택의 노드를 구조체로 정의
	element data;
	struct ListNode* link;
}ListNode;

typedef struct Queue {
	struct ListNode* front; //맨처음 data
	struct ListNode* rear; //맨뒤 data
	int count;
}Queue;

Queue* creatQueue_SLL();
int isFull_SLL(Queue* Q);
void enQueue_SLL(Queue* Q, element data);

int RandIndexValue(Queue* Q, int randInt); //랜덤한 인덱스의 값을 가져오기위한 함수.
//===============================================================================


int main(void)
{
	//Queue에서의 DynamicRoundArray와 SinglyLinkedList의 동작 시간 비교
	srand(time(NULL));
	int start_time = 0, end_time = 0;
	float time = 0.0f;
	int randint = 0;
	double sum = 0;

	printf("Queue_Push %d번 반복\n\n", T_NUM);
	//===============================================================================
	//DynamicRoundArray
	QueueType* myQ_DA = CreateQueue_DA();

	//DynamicRoundArray에 PUSH하는 수행 시간 측정
	start_time = clock();

	for (int i = 0; i < T_NUM; i++)
	{
			enQueue_DA(myQ_DA, i);
	} 
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[DynamicRoundArray_PUSH]	duration : %f\n", time);
	printf("\n");

	//DynamicRoundArray에 Random Access For Read하는 수행 시간 측정
	start_time = clock();

	for (int i = 0; i < 100; i++)
	{
		randint = rand() % T_NUM;
		//printf("%d -> ", myS_DA->array[randint]);

		sum += myQ_DA->array[randint];
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[DynamicRoundArray_Random Access For Read]	duration : %f\tSum : %.0lf\n", time, sum); //더한 값은 소수점 없애고 출력.
	printf("\n");

	//===============================================================================
	//===============================================================================
	//SinglyLinkedList

	Queue* myQ_SLL = creatQueue_SLL();

	//SinglyLinkedList에 PUSH하는 수행 시간 측정
	start_time = clock();

	for (int i = 0; i < T_NUM; i++)
	{
		enQueue_SLL(myQ_SLL, i);
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[SinglyLinkedList_PUSH]		duration : %f\n", time);
	printf("\n");

	//SinglyLinkedList에 Random Access For Read하는 수행 시간 측정
	sum = 0;
	start_time = clock();

	for (int i = 0; i < 100; i++)
	{
		randint = rand() % T_NUM;
		sum += RandIndexValue(myQ_SLL, randint);
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[SinglyLinkedList_Random Access For Read]\tduration : %f\tSum : %.0lf\n", time, sum); //더한 값은 소수점 없애고 출력.
	printf("\n");

	return 0;
}

//===============================================================================
//DynamicRoundArray
QueueType* CreateQueue_DA()
{
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	if (!Q)
	{
		//만약 큐가 동적할당에 실패했다면!
		return NULL;
	}


	Q->capacity = MAX_STACK_SIZE; //Queue의 크기

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

int isFull_DA(QueueType* Q)
{
	return ((Q->rear + 1) % Q->capacity == Q->front);
}

void enQueue_DA(QueueType* Q, element item)
{
	if (isFull_DA(Q))
	{
		Q->capacity *= 2;
		Q->array = (element*)realloc(Q->array, Q->capacity * sizeof(element));
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


//===============================================================================
//SinglyLinkedList

Queue* creatQueue_SLL()
{
	Queue* Q;
	//ListNode* temp;
	Q = (Queue*)malloc(sizeof(Queue));

	if (!Q)
	{
		//만약 Q가 NULL이면
		return NULL;
	}
	//temp = (ListNode*)malloc(sizeof(ListNode));
	Q->front = NULL;
	Q->rear = NULL;

	Q->count = -1;

	return Q;
}

void enQueue_SLL(Queue* Q, element data)
{
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;

	newNode->data = data;
	newNode->link = NULL;

	if (Q->rear == NULL)
	{
		//만약 첫 데이터일경우.. rear과 front모두 newnode를 가리키게
		Q->rear = newNode;
		Q->front = newNode;
	}
	else
	{
		Q->rear->link = newNode; //첫데이터가 아닌경우, rear
		Q->rear = newNode;
	}

	Q->count += 1; //나중에 count의 위치 조절이 필요할 수도 있음.
	if (Q->front == NULL)
	{
		//만약 Q가 비어있을 경우..
		Q->front = Q->rear;
	}
}

int RandIndexValue(Queue* Q, int randInt)
{
	//랜덤한 인덱스의 값을 가져오기위한 함수.
	ListNode* q = Q->front;

	while (randInt != 0)
	{
		randInt--;
		q = q->link;
	}
	return q->data;
}

