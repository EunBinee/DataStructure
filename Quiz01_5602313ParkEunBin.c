#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int count = 1;

typedef struct Student {
	int order;
	char name[10];
	int num; //�й�
	char score; //����
	struct Student* link;
}Student;

Student* insert_last(Student* head, int order, char* name, int num, char score);
Student* delete_first(Student* head);
void print_list(Student* head);

int search_list(Student* head, char* name);

int main(void)
{
	int num=0;
	//char* namefine = "����ȣ";
	Student* head = NULL;

	head = insert_last(head, 1,"��ö��", 551212, 'A');
	print_list(head);
	head = insert_last(head, 2,"�̿���", 432323, 'B');
	print_list(head);
	head = insert_last(head, 3,"����ȣ", 533434, 'C');
	print_list(head);

	num = search_list(head, "����ȣ");
	if (num == NULL)
	{
		printf("����ȣ�� ����.");

	}
	else
	{
		printf("ã�� �� ����ȣ�� %d��ġ�� �ֽ��ϴ�.\n\n", num);
	}
	
	head= delete_first(head);
	print_list(head);
	return 0;
}

Student* insert_last(Student* head, int order,char* name, int num, char score)
{
	Student* p = (Student*)malloc(sizeof(Student));   //�߰��� value�� �־��� Node�� ������ش�.
	Student* ph = head;  //���� ����
	//ph�� head�� ���� �ּҰ��� ������ ������ hp�� �ٲ�� head�� �ٲ��.
	//p->data = value;
	p->order = order;

	strcpy(p->name, name);
	p->num = num;
	p->score = score;

	if (head == NULL)
	{
		head = p;
	}
	else
	{
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
	}

	p->link = NULL;
	return head;
}

Student* delete_first(Student* head)
{
	Student* removed;
	if (head == NULL)
	{
		printf("No element in the list\n\n");
		exit(0);
	}
	removed = head;
	head = removed->link;

	free(removed);
	
	return head;  //head�� ���ϱ⶧���� head�� ����
}
void print_list(Student* head)  //���� ���!
{

	for (Student* ph = head; ph != NULL; ph = ph->link)
	{
		printf("\n==================================\n");
		printf("����: %d\n", ph->order);
		printf("�̸�: %s\n", ph->name);
		printf("�й�: %d\n", ph->num);
		printf("����: %c\n", ph->score);
		printf("==================================\n");
	}

	printf("\n");
}

int search_list(Student* head, char* name)
{
	//Student* p = head;
	int count = 1;
	int compare;
	while (head != NULL)
	{
		compare = strcmp(name, head->name);
		if (compare==0)
			return count;
		count++;
		head = head->link;
	}
	return NULL;
}