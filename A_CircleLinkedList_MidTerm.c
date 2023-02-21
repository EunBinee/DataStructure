#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;  //Singly Linked List를 위한 구조체

ListNode* insert_first(ListNode* head, element data);

ListNode* insert_last(ListNode* head, element data);

//delete first와 last구현
ListNode* delete_first(ListNode* head);
ListNode* delete_last(ListNode* head);

void print_list(ListNode* head);

int main(void)
{
	ListNode* head = NULL;

	printf("[insert_first사용]\n");
	for (int i = 0; i < 5; i++)
	{
		head = insert_first(head, i);
		print_list(head);
	}


	printf("[insert_last사용]\n");
	head = insert_last(head, 10);
	print_list(head);

	printf("[delete_first사용]\n");
	head = delete_first(head);
	print_list(head);

	printf("[delete_last사용]\n");
	head = delete_last(head);
	print_list(head);
	return 0;
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL)
	{
		//head안에 아무것도 없는 경우
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL)
	{
		head = node;
		node->link = head;
	}

	else
	{
		node->link = head->link;
		head->link = node;
		head = node;

	}
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* p = NULL;
	p = head->link;
	head->link = p->link;

	free(p);

	return head;
}

ListNode* delete_last(ListNode* head)
{
	ListNode* p, * p2;
	p = head->link;

	while (p->link != head)
	{
		p = p->link;
	}
	p2 = head;
	p->link = p2->link;
	head = p;

	free(p2);

	return head;
	
}


void print_list(ListNode* head)
{
	ListNode* p;
	if (head == NULL)
		return;

	p = head->link;

	while (p != head)
	{
		printf("%d -> ", p->data);
		p = p->link;
	}
	printf("%d->\n", p->data); //지금의 p는 head
	
}