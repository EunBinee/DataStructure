#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define T_NUM 5000 //��� PUSH�� ������
#define MAX_STACK_SIZE 5   //DynamicArray�� �ִ� ���ð�
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
	//������ ��带 ����ü�� ����
	element data;
	struct ListNode* link;
}ListNode;

typedef struct Queue {
	struct ListNode* front; //��ó�� data
	struct ListNode* rear; //�ǵ� data
	int count;
}Queue;

Queue* creatQueue_SLL();
int isFull_SLL(Queue* Q);
void enQueue_SLL(Queue* Q, element data);

int RandIndexValue(Queue* Q, int randInt); //������ �ε����� ���� ������������ �Լ�.
//===============================================================================


int main(void)
{
	//Queue������ DynamicRoundArray�� SinglyLinkedList�� ���� �ð� ��
	srand(time(NULL));
	int start_time = 0, end_time = 0;
	float time = 0.0f;
	int randint = 0;
	double sum = 0;

	printf("Queue_Push %d�� �ݺ�\n\n", T_NUM);
	//===============================================================================
	//DynamicRoundArray
	QueueType* myQ_DA = CreateQueue_DA();

	//DynamicRoundArray�� PUSH�ϴ� ���� �ð� ����
	start_time = clock();

	for (int i = 0; i < T_NUM; i++)
	{
			enQueue_DA(myQ_DA, i);
	} 
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[DynamicRoundArray_PUSH]	duration : %f\n", time);
	printf("\n");

	//DynamicRoundArray�� Random Access For Read�ϴ� ���� �ð� ����
	start_time = clock();

	for (int i = 0; i < 100; i++)
	{
		randint = rand() % T_NUM;
		//printf("%d -> ", myS_DA->array[randint]);

		sum += myQ_DA->array[randint];
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[DynamicRoundArray_Random Access For Read]	duration : %f\tSum : %.0lf\n", time, sum); //���� ���� �Ҽ��� ���ְ� ���.
	printf("\n");

	//===============================================================================
	//===============================================================================
	//SinglyLinkedList

	Queue* myQ_SLL = creatQueue_SLL();

	//SinglyLinkedList�� PUSH�ϴ� ���� �ð� ����
	start_time = clock();

	for (int i = 0; i < T_NUM; i++)
	{
		enQueue_SLL(myQ_SLL, i);
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[SinglyLinkedList_PUSH]		duration : %f\n", time);
	printf("\n");

	//SinglyLinkedList�� Random Access For Read�ϴ� ���� �ð� ����
	sum = 0;
	start_time = clock();

	for (int i = 0; i < 100; i++)
	{
		randint = rand() % T_NUM;
		sum += RandIndexValue(myQ_SLL, randint);
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[SinglyLinkedList_Random Access For Read]\tduration : %f\tSum : %.0lf\n", time, sum); //���� ���� �Ҽ��� ���ְ� ���.
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
		//���� ť�� �����Ҵ翡 �����ߴٸ�!
		return NULL;
	}


	Q->capacity = MAX_STACK_SIZE; //Queue�� ũ��

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
		//���� ù �������� ���, -1��
		//�� ���
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
		//���� Q�� NULL�̸�
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
		//���� ù �������ϰ��.. rear�� front��� newnode�� ����Ű��
		Q->rear = newNode;
		Q->front = newNode;
	}
	else
	{
		Q->rear->link = newNode; //ù�����Ͱ� �ƴѰ��, rear
		Q->rear = newNode;
	}

	Q->count += 1; //���߿� count�� ��ġ ������ �ʿ��� ���� ����.
	if (Q->front == NULL)
	{
		//���� Q�� ������� ���..
		Q->front = Q->rear;
	}
}

int RandIndexValue(Queue* Q, int randInt)
{
	//������ �ε����� ���� ������������ �Լ�.
	ListNode* q = Q->front;

	while (randInt != 0)
	{
		randInt--;
		q = q->link;
	}
	return q->data;
}

