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

	//ù��° ��ġ�� �����ϰڴ�.
	if (position == 1)
	{
		if ((*head) == NULL)//head�� �ƹ���嵵 ���� ���, �󸮽�Ʈ
		{
			newNode->Llink = NULL;//�� NULL�� ����Ű�� ��, �ֳ��ϸ�.. newNode�� ���� ù��° ����̱� �����̴�!!
			newNode->Rlink = *head; //Rlink���� NULL�� ������ ������غ���
			*head = newNode;
		}
		else
		{
			//head�� �� ����Ʈ�� �ƴ� ���
			newNode->Llink = NULL;
			newNode->Rlink = *head;

			(*head)->Llink = newNode;
			*head = newNode;
		}
		return;
	}
	else
	{
		temp = *head;  //�������� ���� temp

		while (k < (position - 1) && temp->Rlink != NULL)
		{
			temp = temp->Rlink;
			k++;
		}

		if (temp->Rlink == NULL)
		{
			//insert Last,  �Ǹ����� ��忡 �ֱ�, �������� ���� ����� ������ Ŀ��
			newNode->Rlink = temp->Rlink;
			newNode->Llink = temp;

			temp->Rlink = newNode;
		}
		else
		{
			//�߰��� �ִ� ���
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
	
	//ù��° ���븦 �����ϰڴ�.
	if (position == 1)
	{
		temp = *head;
		if ((*head) == NULL)//head�� �ƹ���嵵 ���� ���, �󸮽�Ʈ
		{
			printf("\n�ƹ��͵� ����.\n");
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
		temp = *head;  //�������� ���� temp
		ListNode* temp02=NULL; //temp�� ���� ��带 ���� temp02
		while (k < (position -1) && temp->Rlink != NULL)
		{
			temp = temp->Rlink;
			k++;
		}

		if (temp->Rlink == NULL)
		{
			//insert Last,  �Ǹ����� ��带 ����
			temp->Llink->Rlink = NULL;
			free(temp);
		}
		else
		{
			//�߰��� ���� �����ϴ� ���
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