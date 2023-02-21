#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DQNode {
	element data;
	struct DQNode* Llink;
	struct DQNode* Rlink;
}DQNode;

typedef struct DQueType {
	DQNode* front, * rear;
}DQueType;

DQueType* creatDQue();
int isEmpty(DQueType* DQ);
void addFront(DQueType* DQ, element item);
void addRear(DQueType* DQ, element item);
element deleteFront(DQueType* DQ);
element deleteRear(DQueType* DQ);
void print_list(DQueType* DQ);

int main()
{
	DQueType* myDQ = creatDQue();

	printf("\n[addFront]\n");
	for (int i = 0; i < 5; i++)
	{
		addFront(myDQ, i);
		print_list(myDQ);
	}

	printf("\n[deleteFront]\n");
	for (int i = 0; i < 5; i++)
	{
		
		deleteFront(myDQ);
		print_list(myDQ);
	}

	printf("\n[addRear]\n");
	for (int i = 0; i < 5; i++)
	{
		addRear(myDQ, i);
		print_list(myDQ);
	}

	printf("\n[deleteRear]\n");
	for (int i = 0; i < 5; i++)
	{
		deleteRear(myDQ);
		print_list(myDQ);
	}
	

	return 0;
}

DQueType* creatDQue()
{
	DQueType* DQ;
	DQ = (DQueType*)malloc(sizeof(DQueType));
	DQ->front = NULL;
	DQ->rear = NULL;

	return DQ;
}


void addFront(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;

	if (DQ->front == NULL)
	{
		//Deque�� ��������� ���
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->Llink = NULL;
		newNode->Rlink = NULL;
	}
	else 
	{
		
		DQ->front->Llink = newNode;
		newNode->Rlink = DQ->front;
		newNode->Llink = NULL;
		DQ->front = newNode;
	}
}

void addRear(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;

	if (DQ->front == NULL)
	{
		//Deque�� ��������� ���
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->Llink = NULL;
		newNode->Rlink = NULL;
	}
	else
	{
		DQ->rear->Rlink = newNode;
		newNode->Llink = DQ->rear;
		newNode->Rlink = NULL;
		DQ->rear = newNode;
	}
}

int isEmpty(DQueType* DQ)
{
	return DQ->front == NULL;
}
element deleteFront(DQueType* DQ)
{
	DQNode* temp = DQ->front;

	element item; //������ ���� �����ֱ� ���� ����

	if (isEmpty(DQ))
		return 0;

	else
	{
		item = temp->data;

		if (DQ->front->Rlink == NULL)//���� �ϳ��ۿ� ������..
		{
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else
		{
			DQ->front = DQ->front->Rlink;
			DQ->front->Llink = NULL;
		}

		free(temp);
		return item;
	}
}

element deleteRear(DQueType* DQ)
{
	DQNode* temp = DQ->rear;

	element item; //������ ���� �����ֱ� ���� ����

	if (isEmpty(DQ))
		return 0;

	else
	{
		item = temp->data;

		if (DQ->rear->Llink == NULL) //���� �ϳ��ۿ� ������..
		{
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else
		{
			DQ->rear = DQ->rear->Llink;
			DQ->rear->Rlink = NULL;
		}

		free(temp);
		return item;
	}
}

void print_list(DQueType* DQ)  //���� ���!
{
	if (isEmpty(DQ))
	{
		return;
	}
	else
	{
		for (DQNode* q = DQ->front; q != NULL; q = q->Rlink)
		{
			printf("<- %d -> ", q->data);
		}
		printf("NULL!");
		printf("\n");
	}
}