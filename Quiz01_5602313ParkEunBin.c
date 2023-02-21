#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int count = 1;

typedef struct Student {
	int order;
	char name[10];
	int num; //학번
	char score; //학점
	struct Student* link;
}Student;

Student* insert_last(Student* head, int order, char* name, int num, char score);
Student* delete_first(Student* head);
void print_list(Student* head);

int search_list(Student* head, char* name);

int main(void)
{
	int num=0;
	//char* namefine = "박찬호";
	Student* head = NULL;

	head = insert_last(head, 1,"김철수", 551212, 'A');
	print_list(head);
	head = insert_last(head, 2,"이영희", 432323, 'B');
	print_list(head);
	head = insert_last(head, 3,"박찬호", 533434, 'C');
	print_list(head);

	num = search_list(head, "박찬호");
	if (num == NULL)
	{
		printf("박찬호는 없다.");

	}
	else
	{
		printf("찾는 값 박찬호는 %d위치에 있습니다.\n\n", num);
	}
	
	head= delete_first(head);
	print_list(head);
	return 0;
}

Student* insert_last(Student* head, int order,char* name, int num, char score)
{
	Student* p = (Student*)malloc(sizeof(Student));   //추가할 value를 넣어줄 Node를 만들어준다.
	Student* ph = head;  //얕은 복사
	//ph는 head와 같은 주소값을 가지기 때문에 hp가 바뀌면 head도 바뀐다.
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
				//미리 앞의 주소를 보고 NULL인지 아닌지 파악
				//만약 NULL이면..
				ph->link = p;
				break;
			}
			ph = ph->link;   //ph는 ph가 가리키는 ListNode야~
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
	
	return head;  //head가 변하기때문에 head를 리턴
}
void print_list(Student* head)  //내용 출력!
{

	for (Student* ph = head; ph != NULL; ph = ph->link)
	{
		printf("\n==================================\n");
		printf("순서: %d\n", ph->order);
		printf("이름: %s\n", ph->name);
		printf("학번: %d\n", ph->num);
		printf("성적: %c\n", ph->score);
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