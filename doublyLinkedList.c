#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* Llink;
	struct ListNode* Rlink;
}ListNode;  //Singly Linked List를 위한 구조체

void init(ListNode* head);

void print_list(ListNode* head);

void insertFirst(ListNode* head, element data);
void deleteFirst(ListNode* head, ListNode* removed);

int main(void)
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	init(head);//초기화
	printf("[insertFirst]사용\n");
	for (int i = 0; i < 5; i++)
	{
		//헤드의 오른쪽(맨처음에 삽입)
		insertFirst(head, i);
		print_list(head);
	}
	printf("\n[deleteFirst]사용\n");
	for (int i = 0; i < 5; i++)
	{
		//헤드의 오른쪽(맨처음에 삽입)
		deleteFirst(head, head->Rlink);
		print_list(head);
	}

	free(head);

	return 0;
}


void init(ListNode* head)
{
	head->Llink = head;
	head->Rlink = head;
}

void print_list(ListNode* head)
{
	ListNode* p;
	for (p = head->Rlink; p != head; p = p->Rlink)
	{
		printf(" <-||%d||-> ", p->data);
	}
	printf("\n");

}
void insertFirst(ListNode* head, element data)//insertfirst
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->Llink = head;
	newNode->Rlink = head->Rlink;

	head->Rlink->Llink = newNode;
	head->Rlink = newNode;

}

void deleteFirst(ListNode* head, ListNode* removed)
{
	if (removed == head)
		return;
	//removed->Llink->Rlink = removed->Rlink; //removed의 왼쪽 링크의 오른쪽링크는 removed의 오른쪽 링크를 가리킨다.
	//removed->Rlink->Llink = removed->Llink; //removed의 오른쪽 링크의 왼쪽 링크는 removed의 왼쪽 링크를 기리킨다.
	head->Rlink = removed->Rlink;
	removed->Rlink->Llink = head;
	free(removed);
}