#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;

//Singly Linked List�� ���� ����ü
typedef struct SinglyListNode {
	element data;
	struct SinglyListNode* link;
}SinglyListNode;

//doubly Linked List�� ���� ����ü
typedef struct DoublyListNode {
	element data;
	struct DoublyListNode* Llink;
	struct DoublyListNode* Rlink;
}DoublyListNode;

SinglyListNode* insert_position(SinglyListNode* head, int position, element value);
SinglyListNode* SinglyListNode_delete_position(SinglyListNode* head, int position);

void DoublyLinkedList_Insert(DoublyListNode** head, int position, int data);
void DoublyLinkedList_Delete(DoublyListNode** head, int position);

element SinglyListNode_search_list(SinglyListNode* head, int position);
element DoublyListNode_search_list(DoublyListNode* head, int position);


int main(void)
{
	int start_time = 0, end_time = 0;
	float time = 0.0f;
	double sum = 0;

	//==========================================================
	// Array //
	int* array = (int*)malloc(sizeof(int) * 10000); //�޸� �Ҵ�//


	//Array�� insert�ϴ� ���� �ð� ����
	start_time = clock();
    
	for (int i = 0; i < 10000; i++)
	{
		array[i] = i;
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[�迭_insert]\nduration : %f\n", time);
	printf("\n");

	//Array�� rand�� �� 1000�� ���ؼ� ���ϱ�, ����ð� ����
	start_time = clock();
	for (int i = 0; i < 1000; i++)
	{
		int randIndex = rand() % 10000;
		sum += array[randIndex];
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[�迭_random Index_Add]\nduration : %f\n", time);
	printf("sum : %.0lf\n", sum); //�Ҽ����� ���ְ� ���

	printf("\n");
	//Array�� rand�� �� 1000�� ���ؼ� �����ϱ�(��ǻ� -1�� �ٲٱ�), ����ð� ����
	start_time = clock();
	for (int i = 0; i < 1000; i++)
	{
		int randIndex = rand() % 10000;
		array[randIndex] = -1;
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[�迭_random Index_Delete]\nduration : %f\n", time);
	printf("\n");
	
	//�޸� ����
	free(array);
	
	//==========================================================
	printf("========================================\n\n");
	//==========================================================
	// Singly Linked List //
	SinglyListNode* head = NULL;
	

	//Singly Linked List�� insert�ϴ� ���� �ð� ����
	start_time = clock();

	for (int i = 0; i < 10000; i++)
	{
		head = insert_position(head, (i+1), i);
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[Singly Linked List_insert]\nduration : %f\n", time);
	printf("\n");


	//Singly Linked List�� rand�� �� 1000�� ���ؼ� ���ϱ�, ����ð� ����
	start_time = clock();
	sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		int randIndex = rand() % 10000;
		sum += SinglyListNode_search_list(head, randIndex);
	}
	
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[Singly Linked List_random Index_Add]\nduration : %f\n", time);
	printf("sum : %.0lf\n", sum); //�Ҽ����� ���ְ� ���
	printf("\n");
	
	//Singly Linked List�� ������ ��ġ�� �� 1000�� �����ϱ�, ����ð� ����
	start_time = clock();
	for (int i = 0; i < 1000; i++)
	{
		int randIndex = rand() % 10000;
		head = SinglyListNode_delete_position(head, (randIndex+1));
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[Singly Linked List_Delete]\nduration : %f\n", time);
	printf("\n");

	//==========================================================
	printf("========================================\n\n");
	//==========================================================
	// Doubly Linked List //
	DoublyListNode* Doubly_head = NULL;

	//Doubly Linked List�� insert�ϴ� ���� �ð� ����
	start_time = clock();

	for (int i = 0; i < 10000; i++)
	{
		DoublyLinkedList_Insert(&Doubly_head, (i + 1) , i);
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[Doubly Linked List_insert]\nduration : %f\n", time);
	printf("\n");

	//Doubly Linked List�� rand�� �� 1000�� ���ؼ� ���ϱ�, ����ð� ����
	start_time = clock();
	sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		int randIndex = rand() % 10000;
		sum += DoublyListNode_search_list(Doubly_head, randIndex);
	}

	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[Doubly Linked List_random Index_Add]\nduration : %f\n", time);
	printf("sum : %.0lf\n", sum); //�Ҽ����� ���ְ� ���
	printf("\n");

	//Doubly Linked List�� ������ ��ġ�� �� 1000�� �����ϱ�, ����ð� ����
	start_time = clock();
	for (int i = 0; i < 1000; i++)
	{
		int randIndex = rand() % 10000;
		DoublyLinkedList_Delete(&Doubly_head, (randIndex+1));
	}
	end_time = clock();
	time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("[Doubly Linked List_Delete]\nduration : %f\n", time);
	printf("\n");

	return 0;
}

SinglyListNode* insert_position(SinglyListNode* head, int position, element value) //SinglyLinkedList�� insert
{
	int k = 1;
	SinglyListNode* p = NULL, * q = NULL;
	//p�� head, q�� p�� ���� ��带 �����ϱ� ����.

	SinglyListNode* NewNode = (SinglyListNode*)malloc(sizeof(SinglyListNode));
	NewNode->data = value;
	p = head;

	if (position == 1) //1�� ��ġ�� �߰��ϰڴ�.
	{
		NewNode->link = head;
		head = NewNode;
	}
	else
	{
		while ((p != NULL) && (k < position))
		{
			k++;
			q = p;
			p = p->link;
		}
		if (p == NULL)
		{
			q->link = NewNode;
			NewNode->link = NULL;
		}
		else
		{
			q->link = NewNode;
			NewNode->link = p;
		}
	}
	

	return head;
}

SinglyListNode* SinglyListNode_delete_position(SinglyListNode* head, int position)
{
	int k = 1;
	SinglyListNode* p = NULL, * q = NULL;
	//p�� head, q�� p�� ���� ��带 �����ϱ� ����.
	p = head;


	if (position == 1)
	{
		//ù��° ��带 �����Ͻÿ�
		q = p->link;
		free(p);
		head = q;
	}
	else
	{
		while ((p->link != NULL) && (k < position))
		{
			k++;
			q = p; //q���� ��� p�״��� ���
			p = p->link;
		}
		if (p == NULL)
		{
			//�� ������ ��� ����
			q = p;
			free(p);
			q->link = NULL;
		}
		else
		{
			q->link = p->link;
			free(p);
		}
	}

	return head;
}

void DoublyLinkedList_Insert(DoublyListNode** head, int position, int data)
{
	int k = 1;

	DoublyListNode* newNode, * temp;
	newNode = (DoublyListNode*)malloc(sizeof(DoublyListNode));
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

void DoublyLinkedList_Delete(DoublyListNode** head, int position)
{
	int k = 1;

	DoublyListNode* temp;

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
		DoublyListNode* temp02 = NULL; //temp�� ���� ��带 ���� temp02
		while (k < (position - 1) && temp->Rlink != NULL)
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
			temp02 = temp->Rlink;
			if (temp02->Rlink == NULL)
			{
				temp->Rlink = NULL;
			}
			else
			{
				temp->Rlink = temp02->Rlink;
				temp02->Rlink->Llink = temp;
			}
			

			free(temp02);
		}
		return;
	}
}

element SinglyListNode_search_list(SinglyListNode* head, int position)
{
	SinglyListNode* p = head;

	while (p != NULL)
	{
		if (p->data == position)
			return p->data;
		p = p->link;
	}
	return NULL;
}

element DoublyListNode_search_list(DoublyListNode* head, int position)
{
	DoublyListNode* p = head;

	while (p != NULL)
	{
		if (p->data == position)
			return p->data;
		p = p->Rlink;
	}
	return NULL;
}