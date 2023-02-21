#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//단순 연결 리스트
typedef int element;

typedef struct ListNode
{
	element data;
	struct ListNode* link;
}ListNode;

ListNode* Insert_First(ListNode* head, element data);
ListNode* Insert_Last(ListNode* head, element data);
ListNode* InsertPos(ListNode* head, int pos, element data);

ListNode* DeleteFirst(ListNode* head);
ListNode* DeleteLast(ListNode* head);
ListNode* DeletePos(ListNode* head, int pos);

void DeleteALL(ListNode** head);

int search_List(ListNode* head, element data);

void print_Node(ListNode* head);

int main(void)
{
	ListNode* head = NULL;
	int num, count;  //search에 사용
	//insertFirst 구현
	for (int i = 0; i < 5; i++)
	{
		head = Insert_First(head, i);
		print_Node(head);
	}
	Insert_Last(head, 0);
	print_Node(head);

	head = InsertPos(head, 1, 12);
	print_Node(head);
	head = InsertPos(head, 3, 20);
	print_Node(head);
	head = InsertPos(head, 10, 1);
	print_Node(head);

	printf("\n");
	head = DeleteFirst(head);
	print_Node(head);
	head = DeleteLast(head);
	print_Node(head);
	head = DeletePos(head, 2);
	print_Node(head);
	head = DeletePos(head, 10);
	print_Node(head);

	printf("\n어떤 값를 찾으시겠습니까? : ");
	scanf("%d", &num);
	count = search_List(head, num);

	if (count == NULL)
		printf("리스트에 값이 없습니다.\n\n");
	else
		printf("찾는 값 %d는 %d위치에 있습니다.\n\n", num, count + 1);


	DeleteALL(&head);
	print_Node(head);
	return 0;
}

ListNode* Insert_First(ListNode* head, element data)
{
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	NewNode->data = data;
	NewNode->link = head;
	head = NewNode;

	return head;
}

ListNode* Insert_Last(ListNode* head, element data)
{
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	ListNode* p = head;
	NewNode->data = data;

	if (head == NULL)
	{
		NewNode->link = head;
		head = NewNode;
	}
	else
	{
		while (p->link != NULL)
		{
			p = p->link;
		}
		p->link = NewNode;
		NewNode->link = NULL;
	}


	return head;
}

ListNode* InsertPos(ListNode* head, int pos, element data)
{
	int k = 1;//pos 세기위해서
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	NewNode->data = data;
	ListNode* p = head;
	ListNode* pre = NULL;

	if (pos == 1)//처음에 넣어야하는 경우
	{
		NewNode->link = head;
		head = NewNode;
	}
	else
	{
		while (k < pos && p != NULL)
		{
			k++;
			pre = p;
			p = p->link;
		}

		if (p == NULL)
		{
			pre->link = NewNode;
			NewNode->link = NULL;
		}
		else
		{
			pre->link = NewNode;
			NewNode->link = p;
		}
	}
	return head;
}

ListNode* DeleteFirst(ListNode* head)
{
	ListNode* p = NULL;
	if (head == NULL)
	{
		printf("No element in the list\n\n");
		exit(0);
	}
	p = head;
	head = p->link;

	free(p);

	return head;
}

ListNode* DeleteLast(ListNode* head)
{
	ListNode* pre, * p;

	if (head == NULL)
	{
		printf("No element in the list\n\n");
		exit(0);
	}
	else if (head->link == NULL)
	{
		//노드가 한개인 경우
		free(head);
		head = NULL;
	}
	else
	{
		//중요 두개!!!
		pre = head;
		p = head->link;

		while (p->link != NULL)
		{
			pre = p;
			p = p->link;
		}
		pre->link = NULL;
		free(p);
	}

	return head;
}

ListNode* DeletePos(ListNode* head, int pos)
{
	int k = 1;
	ListNode* p, * pre;

	if (pos == 1)
	{
		//첫번째를 지움
		pre = head;
		p = head->link;
		
		free(pre);
		head = p;
	}
	else
	{
		pre = head;
		p = head->link;
		while (k < pos && p->link != NULL)
		{
			k++;
			pre = p;
			p = p->link;
		}

		if (p->link == NULL)
		{
			free(p);
			pre->link = NULL;
		}
		else 
		{
			pre->link = p->link;
			free(p);
		}
	}

	return head;
}

void DeleteALL(ListNode** head)
{
	ListNode* remove01, * remove02;
	remove01 = *head;

	while (remove01)//NULL이 될때 까지 
	{
		printf("\n삭제할 데이터 : %d\n", remove01->data);
		remove02 = remove01->link;
		free(remove01);
		remove01 = remove02;
	}

	*head = NULL;
}

int search_List(ListNode* head, element data)
{
	ListNode* p = head;
	int count = 0;
	while (p != NULL)
	{
		if (p->data == data)
		{
			return count;
		}
		count++;
		p = p->link;
	}

	return NULL;
}
ListNode* reverse(ListNode* head)
{

	ListNode* p = head;
	ListNode* reverseNode = NULL;

	while (p != NULL)
	{
		reverseNode = Insert_First(reverseNode, p->data);
		p = p->link;
	}
	return reverseNode;
}

void print_Node(ListNode* head)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
	{
		printf("%d -> ", p->data);
	}
	printf("NULL\n");
}