#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;  //Singly Linked List�� ���� ����ü

ListNode* insert_first(ListNode* head, element data);
ListNode* insert_last(ListNode* head, element data);

//delete first�� last����
ListNode* delete_first(ListNode* head);
ListNode* delete_last(ListNode* head);

void print_list(ListNode* head);

int main()
{
	ListNode* head = NULL;

	printf("[insert_first���]\n");
	for (int i = 0; i < 5; i++)
	{
		head = insert_first(head, i);
		print_list(head);
	}

	printf("[insert_last���]\n");
	head = insert_last(head, 10);
	print_list(head);

	printf("[delete_first���]\n");
	head = delete_first(head);
	print_list(head);

	printf("[delete_last���]\n");
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
		//head�ȿ� �ƹ��͵� ���� ��. ��尡 ���� ��
		//ù���
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link; //�̶��� head -> link�� �� ��尡 �������, �� ���� ����� �ּ�.
		head->link = node;  //�� �� ��尡 �ٲ������, head-> link�� �ٲ��ش�. ���� ���� ����� �ּҷ�..
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
		//head�� ���� node�� ����Ŵ. node->link�� head��� ���� �ڱ��ڽ��� ����Ų�ٴ� ��
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
	ListNode* p = NULL;//ù��° ����� ��ġ�� ������ �ӽ� ����;

	p = head->link;
	head->link = p->link;

	free(p);

	return head;
}
ListNode* delete_last(ListNode* head)
{
	ListNode* p = NULL, * p2 = NULL;
	p = head->link;
	while (p->link != head)//�Ǹ����� ���(head)�� �����ϸ� ��������.
	{
		p = p->link;
	}
	p2 = p->link;//p�� head�� ����Ŵ. �׷��Ƿ� p2=head��
	p->link = head->link;//p�� head�� ����Ű�� ��ũ. �� ó�� ��带 ����Ŵ
	head = p;//�������� head�� p��.

	free(p2);

	return head;
}


void print_list(ListNode* head)
{
	ListNode* p;
	if (head == NULL) 
		return;

	p = head->link;//ù��° ���

	while (p != head)
	{
		printf("%d -> ", p->data);
		p = p->link;
	}
	printf("%d->\n", p->data);// ������ ��� ���.
}