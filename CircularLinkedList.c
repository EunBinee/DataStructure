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

int main()
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
		//head안에 아무것도 없을 시. 노드가 없을 시
		//첫노드
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link; //이때의 head -> link는 새 노드가 생기기전, 맨 앞의 노드의 주소.
		head->link = node;  //맨 앞 노드가 바뀌었으니, head-> link를 바꿔준다. 새로 생긴 노드의 주소로..
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
		//head는 지금 node를 가리킴. node->link가 head라는 뜻은 자기자신을 가리킨다는 뜻
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
	ListNode* p = NULL;//첫번째 노드의 위치를 저장할 임시 변수;

	p = head->link;
	head->link = p->link;

	free(p);

	return head;
}
ListNode* delete_last(ListNode* head)
{
	ListNode* p = NULL, * p2 = NULL;
	p = head->link;
	while (p->link != head)//맨마지막 노드(head)에 도착하면 빠져나감.
	{
		p = p->link;
	}
	p2 = p->link;//p는 head를 가리킴. 그러므로 p2=head임
	p->link = head->link;//p는 head가 가리키던 링크. 맨 처음 노드를 가리킴
	head = p;//이제부터 head는 p임.

	free(p2);

	return head;
}


void print_list(ListNode* head)
{
	ListNode* p;
	if (head == NULL) 
		return;

	p = head->link;//첫번째 노드

	while (p != head)
	{
		printf("%d -> ", p->data);
		p = p->link;
	}
	printf("%d->\n", p->data);// 마지막 노드 출력.
}