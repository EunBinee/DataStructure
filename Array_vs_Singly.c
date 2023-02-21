#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;

//Singly Linked List를 위한 구조체
typedef struct SinglyListNode {
	element data;
	struct SinglyListNode* link;
}SinglyListNode;

//doubly Linked List를 위한 구조체
typedef struct DoublyListNode {
	element data;
	struct DoublyListNode* Llink;
	struct DoublyListNode* Rlink;
}DoublyListNode;

SinglyListNode* insert_position(SinglyListNode* head, int position, element value);
SinglyListNode* SinglyListNode_delete_position(SinglyListNode* head, int position);

void DoublyLinkedList_Insert(DoublyListNode** head, int position, int data);
void DoublyLinkedList_Delete(DoublyListNode** head, int position);

element SinglyListNode_search_list(SinglyListNode* head, int position);
element DoublyListNode_search_list(DoublyListNode* head, int position);


int main(void)
{
	int start_time = 0, end_time = 0;
	float time = 0.0f;
	double sum = 0;

	//==========================================================
	// Array //
	int* array = (int*)malloc(sizeof(int) * 10000); //메모리 할당//


	//Array에 insert하는 수행 시간 측정
	start_time = clock();
    
	for (int i = 0; i < 10000; i++)
	{
		array[i] = i;
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[배열_insert]\nduration : %f\n", time);
	printf("\n");

	//Array에 rand한 값 1000번 구해서 더하기, 수행시간 측정
	start_time = clock();
	for (int i = 0; i < 1000; i++)
	{
		int randIndex = rand() % 10000;
		sum += array[randIndex];
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[배열_random Index_Add]\nduration : %f\n", time);
	printf("sum : %.0lf\n", sum); //소수점은 없애고 출력

	printf("\n");
	//Array에 rand한 값 1000번 구해서 삭제하기(사실상 -1로 바꾸기), 수행시간 측정
	start_time = clock();
	for (int i = 0; i < 1000; i++)
	{
		int randIndex = rand() % 10000;
		array[randIndex] = -1;
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[배열_random Index_Delete]\nduration : %f\n", time);
	printf("\n");
	
	//메모리 삭제
	free(array);
	
	//==========================================================
	printf("========================================\n\n");
	//==========================================================
	// Singly Linked List //
	SinglyListNode* head = NULL;
	

	//Singly Linked List에 insert하는 수행 시간 측정
	start_time = clock();

	for (int i = 0; i < 10000; i++)
	{
		head = insert_position(head, (i+1), i);
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[Singly Linked List_insert]\nduration : %f\n", time);
	printf("\n");


	//Singly Linked List에 rand한 값 1000번 구해서 더하기, 수행시간 측정
	start_time = clock();
	sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		int randIndex = rand() % 10000;
		sum += SinglyListNode_search_list(head, randIndex);
	}
	
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[Singly Linked List_random Index_Add]\nduration : %f\n", time);
	printf("sum : %.0lf\n", sum); //소수점은 없애고 출력
	printf("\n");
	
	//Singly Linked List에 랜덤한 위치의 값 1000번 삭제하기, 수행시간 측정
	start_time = clock();
	for (int i = 0; i < 1000; i++)
	{
		int randIndex = rand() % 10000;
		head = SinglyListNode_delete_position(head, (randIndex+1));
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[Singly Linked List_Delete]\nduration : %f\n", time);
	printf("\n");

	//==========================================================
	printf("========================================\n\n");
	//==========================================================
	// Doubly Linked List //
	DoublyListNode* Doubly_head = NULL;

	//Doubly Linked List에 insert하는 수행 시간 측정
	start_time = clock();

	for (int i = 0; i < 10000; i++)
	{
		DoublyLinkedList_Insert(&Doubly_head, (i + 1) , i);
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[Doubly Linked List_insert]\nduration : %f\n", time);
	printf("\n");

	//Doubly Linked List에 rand한 값 1000번 구해서 더하기, 수행시간 측정
	start_time = clock();
	sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		int randIndex = rand() % 10000;
		sum += DoublyListNode_search_list(Doubly_head, randIndex);
	}

	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[Doubly Linked List_random Index_Add]\nduration : %f\n", time);
	printf("sum : %.0lf\n", sum); //소수점은 없애고 출력
	printf("\n");

	//Doubly Linked List에 랜덤한 위치의 값 1000번 삭제하기, 수행시간 측정
	start_time = clock();
	for (int i = 0; i < 1000; i++)
	{
		int randIndex = rand() % 10000;
		DoublyLinkedList_Delete(&Doubly_head, (randIndex+1));
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[Doubly Linked List_Delete]\nduration : %f\n", time);
	printf("\n");

	return 0;
}

SinglyListNode* insert_position(SinglyListNode* head, int position, element value) //SinglyLinkedList의 insert
{
	int k = 1;
	SinglyListNode* p = NULL, * q = NULL;
	//p는 head, q는 p의 이전 노드를 저장하기 위함.

	SinglyListNode* NewNode = (SinglyListNode*)malloc(sizeof(SinglyListNode));
	NewNode->data = value;
	p = head;

	if (position == 1) //1번 위치에 추가하겠다.
	{
		NewNode->link = head;
		head = NewNode;
	}
	else
	{
		while ((p != NULL) && (k < position))
		{
			k++;
			q = p;
			p = p->link;
		}
		if (p == NULL)
		{
			q->link = NewNode;
			NewNode->link = NULL;
		}
		else
		{
			q->link = NewNode;
			NewNode->link = p;
		}
	}
	

	return head;
}

SinglyListNode* SinglyListNode_delete_position(SinglyListNode* head, int position)
{
	int k = 1;
	SinglyListNode* p = NULL, * q = NULL;
	//p는 head, q는 p의 이전 노드를 저장하기 위함.
	p = head;


	if (position == 1)
	{
		//첫번째 노드를 삭제하시오
		q = p->link;
		free(p);
		head = q;
	}
	else
	{
		while ((p->link != NULL) && (k < position))
		{
			k++;
			q = p; //q이전 노드 p그다음 노드
			p = p->link;
		}
		if (p == NULL)
		{
			//맨 마지막 노드 삭제
			q = p;
			free(p);
			q->link = NULL;
		}
		else
		{
			q->link = p->link;
			free(p);
		}
	}

	return head;
}

void DoublyLinkedList_Insert(DoublyListNode** head, int position, int data)
{
	int k = 1;

	DoublyListNode* newNode, * temp;
	newNode = (DoublyListNode*)malloc(sizeof(DoublyListNode));
	newNode->data = data;

	//첫번째 위치에 삽입하겠다.
	if (position == 1)
	{
		if ((*head) == NULL)//head에 아무노드도 없는 경우, 빈리스트
		{
			newNode->Llink = NULL;//왜 NULL을 가리키는 지, 왜냐하면.. newNode가 제일 첫번째 노드이기 때문이다!!
			newNode->Rlink = *head; //Rlink에도 NULL이 들어가는지 디버깅해보기
			*head = newNode;
		}
		else
		{
			//head가 빈 리스트가 아닌 경우
			newNode->Llink = NULL;
			newNode->Rlink = *head;

			(*head)->Llink = newNode;
			*head = newNode;
		}
		return;
	}
	else
	{
		temp = *head;  //가독성을 위한 temp

		while (k < (position - 1) && temp->Rlink != NULL)
		{
			temp = temp->Rlink;
			k++;
		}

		if (temp->Rlink == NULL)
		{
			//insert Last,  맨마지막 노드에 넣기, 포지션의 수가 노드의 수보다 커도
			newNode->Rlink = temp->Rlink;
			newNode->Llink = temp;

			temp->Rlink = newNode;
		}
		else
		{
			//중간에 넣는 경우
			newNode->Rlink = temp->Rlink;
			newNode->Llink = temp;

			temp->Rlink->Llink = newNode;
			temp->Rlink = newNode;
		}
	}
}

void DoublyLinkedList_Delete(DoublyListNode** head, int position)
{
	int k = 1;

	DoublyListNode* temp;

	//첫번째 위취를 삭제하겠다.
	if (position == 1)
	{
		temp = *head;
		if ((*head) == NULL)//head에 아무노드도 없는 경우, 빈리스트
		{
			printf("\n아무것도 없다.\n");
		}
		else
		{
			*head = temp->Rlink;
			if (*head != NULL)
				(*head)->Llink = NULL;
			free(temp);
		}
		return;
	}
	else
	{
		temp = *head;  //가독성을 위한 temp
		DoublyListNode* temp02 = NULL; //temp의 다음 노드를 담을 temp02
		while (k < (position - 1) && temp->Rlink != NULL)
		{
			temp = temp->Rlink;
			k++;
		}

		if (temp->Rlink == NULL)
		{
			//insert Last,  맨마지막 노드를 삭제
			temp->Llink->Rlink = NULL;
			free(temp);
		}
		else
		{
			temp02 = temp->Rlink;
			if (temp02->Rlink == NULL)
			{
				temp->Rlink = NULL;
			}
			else
			{
				temp->Rlink = temp02->Rlink;
				temp02->Rlink->Llink = temp;
			}
			

			free(temp02);
		}
		return;
	}
}

element SinglyListNode_search_list(SinglyListNode* head, int position)
{
	SinglyListNode* p = head;

	while (p != NULL)
	{
		if (p->data == position)
			return p->data;
		p = p->link;
	}
	return NULL;
}

element DoublyListNode_search_list(DoublyListNode* head, int position)
{
	DoublyListNode* p = head;

	while (p != NULL)
	{
		if (p->data == position)
			return p->data;
		p = p->Rlink;
	}
	return NULL;
}