#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	//������ ��带 ����ü�� ����
	element data;
	struct ListNode* link;
}ListNode;

typedef struct Queue {
	struct ListNode* front; //��ó�� data
	struct ListNode* rear; //�ǵ� data
	int count;
	int capacity;
}Queue;

Queue* creatQueue();
int isFull(Queue* Q);
void enQueue(Queue* Q, element data);
int isEmpty(Queue* Q);
void deQueue(Queue* Q);
void print_list(Queue* Q);
int main(void)
{
	Queue* myQ = creatQueue();
	for (int i = 0; i < 6; i++)
	{
		printf("\n[enQ] : ");
		enQueue(myQ, i);
		print_list(myQ);
	}
	/*for (int i = 0; i < 3; i++)
	{
		printf("\n[deQ] : ");
		deQueue(myQ);
		print_list(myQ);
	}
	for (int i = 0; i < 7; i++)
	{
		printf("\n[enQ] : ");
		enQueue(myQ, i);
		print_list(myQ);
	}*/
	return 0;
}

Queue* creatQueue()
{
	Queue* Q;
	//ListNode* temp;
	Q = (Queue*)malloc(sizeof(Queue));
	
	if (!Q)
	{
		//���� Q�� NULL�̸�
		return NULL;
	}
	Q->front = NULL;
	Q->rear = NULL;

	int size;
	printf("SIZE�� �����ּ���(�Է�) : ");
	scanf("%d", &size);

	Q->capacity = size; //Queue�� ũ��
	Q->count = -1;

	return Q;
}

int isFull(Queue* Q)
{
	return (Q->count) == ((Q->capacity)-1);
}
void enQueue(Queue* Q, element data)
{
	if (isFull(Q))
	{
		printf("Overflow\n");
		return;
	}
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return ;

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
	printf("%d ����\n", Q->rear->data);
	if (Q->front == NULL)
	{
		//���� Q�� ������� ���..
		Q->front = Q->rear;
	}
}
int isEmpty(Queue* Q)
{
	return (Q->front == NULL);
}

void deQueue(Queue* Q)
{
	if (isEmpty(Q))
	{
		printf("Is Empty\n");
		return;
	}
	else
	{
		ListNode* preFront; //front�� ���� ���
		preFront = Q->front;

		Q->front = Q->front->link;
		if (isEmpty(Q))
		{
			Q->rear = NULL;
		}
		Q->count -= 1;
		printf("%d ����\n", preFront->data);
		free(preFront);
	}

}

void print_list(Queue* Q)  //���� ���!
{
	if (isEmpty(Q))
	{
		printf("Is Empty\n");
		return;
	}
	else
	{
		for (ListNode* q = Q->front; q != NULL; q = q->link)
		{
			printf("%d -> ", q->data);
		}
		printf("NULL!");
		printf("\n");
	}
}