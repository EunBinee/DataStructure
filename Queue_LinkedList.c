#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	//스택의 노드를 구조체로 정의
	element data;
	struct ListNode* link;
}ListNode;

typedef struct Queue {
	struct ListNode* front; //맨처음 data
	struct ListNode* rear; //맨뒤 data
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
		//만약 Q가 NULL이면
		return NULL;
	}
	Q->front = NULL;
	Q->rear = NULL;

	int size;
	printf("SIZE를 정해주세요(입력) : ");
	scanf("%d", &size);

	Q->capacity = size; //Queue의 크기
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
	printf("%d 삽입\n", Q->rear->data);
	if (Q->front == NULL)
	{
		//만약 Q가 비어있을 경우..
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
		ListNode* preFront; //front를 담을 노드
		preFront = Q->front;

		Q->front = Q->front->link;
		if (isEmpty(Q))
		{
			Q->rear = NULL;
		}
		Q->count -= 1;
		printf("%d 삭제\n", preFront->data);
		free(preFront);
	}

}

void print_list(Queue* Q)  //내용 출력!
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