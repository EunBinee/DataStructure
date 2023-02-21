#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

//Singly Linked List�� ���� ����ü
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;


ListNode* insert_first(ListNode* head, element value);
ListNode* insert_last(ListNode* head, element value);
void print_list(ListNode* head);

ListNode* ListAdd(ListNode* List1_head, ListNode* List2_head, ListNode* List3_head); 
ListNode* Listmix(ListNode* List1_head, ListNode* List2_head, ListNode* List3_head);
ListNode* reverse(ListNode* head);

int main(void)
{
	ListNode* List1_head = NULL; 
	ListNode* List2_head = NULL;

	ListNode* List3_head = NULL;

	for (int i =4; i >=0; i--)
	{
		List1_head = insert_first(List1_head, i+1);
	}
	printf("List1: ");
	print_list(List1_head);
	for (int i = 4; i >=0; i--)
	{
		List2_head = insert_first(List2_head, i+10);
	}
	printf("List2: ");
	print_list(List2_head);

	List3_head= ListAdd(List1_head,List2_head, List3_head);
	print_list(List3_head);

	return 0;
}
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));   //�߰��� value�� �־��� Node�� ������ش�.
	p->data = value; //p�� �����Ϳ� value�� �־��ش�.
	p->link = head;   //p�� �����ʹ� head�� �־��ش�. head�� ���� ����� �ּҸ� ����ִ�.
	head = p;   //head�� �ַθ� p�� link�� �־��� �Ŀ�, head�� ����Ű�� �ּҸ� p�� �ּҷ� �ٲپ��ش�.

	return head;
}
ListNode* insert_last(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));   //�߰��� value�� �־��� Node�� ������ش�.
	ListNode* ph = head;  //���� ����
	//ph�� head�� ���� �ּҰ��� ������ ������ hp�� �ٲ�� head�� �ٲ��.
	p->data = value;

	do
	{
		if (ph->link == NULL)
		{
			//�̸� ���� �ּҸ� ���� NULL���� �ƴ��� �ľ�
			//���� NULL�̸�..
			ph->link = p;
			break;
		}
		ph = ph->link;   //ph�� ph�� ����Ű�� ListNode��~
	} while (ph != NULL);


	p->link = NULL;


	return head;
}
void print_list(ListNode* head)  //���� ���!
{
	for (ListNode* ph = head; ph != NULL; ph = ph->link)
		printf("%d -> ", ph->data);
	printf("NULL!");
	printf("\n");
}


ListNode* ListAdd(ListNode* List1_head, ListNode* List2_head, ListNode* List3_head)
{
	//ListNode* p = reverse(List1_head);
	ListNode* p2 = List2_head;
	ListNode* p3;
	
	int check = 0;
	p3 = List1_head;
	//p3 = p3->link;

	while (p2->link != NULL)
	{
		p3 = p3->link;
		p3 = insert_last(List1_head, p2->data);
		
		p2 = p2->link;
	}
	p3 = p3->link;
	p3 = insert_last(List1_head, p2->data);

	p2 = p2->link;

	return p3;

}
ListNode* reverse(ListNode* head)
{
	ListNode* p = head;
	ListNode* reverseNode = NULL;
	while (p != NULL)
	{
		reverseNode = insert_first(reverseNode, p->data); //��ó���� �־��ִ� insert_first�� �̿��Ͽ� ���� ���.
		p = p->link;
	}
	return reverseNode;
}

ListNode* Listmix(ListNode* List1_head, ListNode* List2_head, ListNode* List3_head)
{
	ListNode* temp;

	ListNode* p = List3_head;

	while (List1_head != NULL && List2_head != NULL)
	{
		p = insert_first(p, List1_head->data);
		temp = List1_head->link;
		
	}
}