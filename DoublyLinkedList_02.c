#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* Llink;
	struct ListNode* Rlink;
}ListNode;  


void Insert(ListNode** head, int position, int data);
void Delete(ListNode** head, int position);
void print_list(ListNode* head);
int main(void)
{
	ListNode* head = NULL;

	for (int i = 1; i <= 5; i++)
	{
		Insert(&head, i, i);
		print_list(head);
	}
	Delete(&head, 3);
	print_list(head);

	return 0;
}

void Insert(ListNode** head, int position, int data)
{
	int k = 1;

	ListNode* newNode, * temp;
	newNode = (ListNode*)malloc(sizeof(ListNode));
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


void Delete(ListNode** head, int position)
{
	int k = 1;

	ListNode* temp;
	
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
		ListNode* temp02=NULL; //temp의 다음 노드를 담을 temp02
		while (k < (position -1) && temp->Rlink != NULL)
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
			//중간의 것을 삭제하는 경우
			/*temp02 = temp->Rlink;
			temp02->Llink->Rlink = temp02->Rlink;
			temp02->Rlink->Llink = temp02->Llink;*/
			
			temp02 = temp->Rlink;
			temp->Rlink = temp02->Rlink;
			temp02->Rlink->Llink = temp;

			/*temp->Llink->Rlink = temp->Rlink;
			temp->Rlink->Llink = temp->Llink;*/

			free(temp02);
		}
		return;
	}
}

void print_list(ListNode* head)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->Rlink)
	{
		printf(" <-||%d||-> ", p->data);
	}
	printf("\n");

}