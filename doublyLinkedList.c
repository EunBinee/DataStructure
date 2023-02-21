#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* Llink;
	struct ListNode* Rlink;
}ListNode;  //Singly Linked List�� ���� ����ü

void init(ListNode* head);

void print_list(ListNode* head);

void insertFirst(ListNode* head, element data);
void deleteFirst(ListNode* head, ListNode* removed);

int main(void)
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	init(head);//�ʱ�ȭ
	printf("[insertFirst]���\n");
	for (int i = 0; i < 5; i++)
	{
		//����� ������(��ó���� ����)
		insertFirst(head, i);
		print_list(head);
	}
	printf("\n[deleteFirst]���\n");
	for (int i = 0; i < 5; i++)
	{
		//����� ������(��ó���� ����)
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
	//removed->Llink->Rlink = removed->Rlink; //removed�� ���� ��ũ�� �����ʸ�ũ�� removed�� ������ ��ũ�� ����Ų��.
	//removed->Rlink->Llink = removed->Llink; //removed�� ������ ��ũ�� ���� ��ũ�� removed�� ���� ��ũ�� �⸮Ų��.
	head->Rlink = removed->Rlink;
	removed->Rlink->Llink = head;
	free(removed);
}