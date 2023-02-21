#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

//Singly Linked List를 위한 구조체
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
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));   //추가할 value를 넣어줄 Node를 만들어준다.
	p->data = value; //p의 데이터에 value를 넣어준다.
	p->link = head;   //p의 데이터는 head를 넣어준다. head는 앞의 노드의 주소를 담고있다.
	head = p;   //head의 주로를 p의 link에 넣어준 후엔, head가 가리키는 주소를 p의 주소로 바꾸어준다.

	return head;
}
ListNode* insert_last(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));   //추가할 value를 넣어줄 Node를 만들어준다.
	ListNode* ph = head;  //얕은 복사
	//ph는 head와 같은 주소값을 가지기 때문에 hp가 바뀌면 head도 바뀐다.
	p->data = value;

	do
	{
		if (ph->link == NULL)
		{
			//미리 앞의 주소를 보고 NULL인지 아닌지 파악
			//만약 NULL이면..
			ph->link = p;
			break;
		}
		ph = ph->link;   //ph는 ph가 가리키는 ListNode야~
	} while (ph != NULL);


	p->link = NULL;


	return head;
}
void print_list(ListNode* head)  //내용 출력!
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
		reverseNode = insert_first(reverseNode, p->data); //맨처음에 넣어주는 insert_first를 이용하여 역순 출력.
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