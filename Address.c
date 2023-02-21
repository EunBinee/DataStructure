#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 50 //����ü �迭�� ũ��
int count = 0; //�� ���� ������ ����ִ��� Ȯ���� ����
struct AddressBook {
	char name[10];
	char phone[15];
	char addr[50];
	char birthday[8];
}; //����ü
void list(struct AddressBook const* address)//�ּҷϿ� �����͸� �����ֱ� ����
{
	int i;
	if (count == 0)
	{
		printf(">> ��ϵ� �ּҷ��� �����ϴ�.\n\n");
	}
	else {
		printf("\n�̸�\t��ȭ��ȣ\t�ּ�\t����\n");
		printf("-------------------------------------------------------------------------------\n");
		for (i = 0; i < count; i++)
		{
			printf("%s\t%s\t%s\t%s\n\n", address[i].name, address[i].phone,
				address[i].addr, address[i].birthday);
		}
	}
}

void append(struct AddressBook const* address)//�ּҷϿ� �����͸� �߰��ϱ� ����
{
	printf("�߰��� �̸� : ");
	scanf(" %[^\n]s", address[count].name);
	printf("�߰��� ��ȭ��ȣ : ");
	scanf(" %[^\n]s", address[count].phone);
	printf("�߰��� �ּ� : ");
	scanf(" %[^\n]s", address[count].addr);
	printf("�߰��� ���� : ");
	scanf(" %[^\n]s", address[count].birthday);
	//" %[^\n]s"�� ����� ������ ������� �ޱ� ���ؼ� �Դϴ�. 
	count++;
}
void search(struct AddressBook const* address)//�ּҷϿ� �����͸� �˻��ϱ� ����
{
	char name[10];
	int compare = 2;
	printf("�˻��� �̸� : ");
	scanf(" %[^\n]s", name);
	for (int i = 0; i < count; i++)
	{
		compare = strcmp(name, address[i].name); //�񱳸� �ؼ� ����ڰ� ã�� �����Ͱ� �ִ��� Ȯ��. 
		if (compare == 0) //�ִٸ� ���
		{
			printf("\n�̸�\t��ȭ��ȣ\t�ּ�\t����\n");
			printf("-------------------------------------------------------------------------------\n");
			printf("%s\t%s\t%s\t%s\n\n", address[i].name, address[i].phone,
				address[i].addr, address[i].birthday);
			break;
		}
	}
	if (compare != 0)
		printf("�˻� ����� �����ϴ�.");
}
void deal(struct AddressBook const* address) //�ּҷϿ� �����͸� �����ϱ� ����
{
	char name[10];
	int compare = 2;
	int i, j;
	printf("������ �̸� : ");
	scanf(" %[^\n]s", name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(name, address[i].name) == 0) // �񱳸� �ؼ� ����ڰ� ã�� �����Ͱ� �ִ��� Ȯ��. 
		{
			for (j = i; j + 1 < count; j++)
			{
				//�ܼ� ������ ������, �ڿ� �����͸� ������ ��ܿͼ� �־��ֱ�
				strcpy(address[j].name, address[j + 1].name);
				strcpy(address[j].phone, address[j + 1].phone);
				strcpy(address[j].addr, address[j + 1].addr);
				strcpy(address[j].birthday, address[j + 1].birthday);
			}
			printf("�����Ϸ�!\n\n");
			count--;
		}
		else if (i == count)
		{
			printf("%s�� ������ �����ϴ�.\n\n", name);
		}
	}
}
int main()
{
	struct AddressBook* address;
	address = (struct AddressBook*)malloc(SIZE * sizeof(struct AddressBook));
	//�����޸𸮷� ����ü �迭 ����.. 
	int choice;
	do {
		printf("\n\n==========================================================================\n");
		printf("---------------------------�ּҷ� �޴�------------------------------------\n");
			printf("\n\n========================================================================== \n");
				printf("1) ��Ϻ���\t2)�߰�\t3)�˻�\t4)����\t5)����\n");
		printf(">> ");
		scanf("%d", &choice);
		switch (choice) //switch������ � �޴��� �����ߴ��� Ȯ���ϰ�, �ű⿡ �´� �Լ��� ����
		{
		case 1:
		list(address);
		break;
		case 2:
		append(address);
		break;
		case 3:
		search(address);
		break;
		case 4:
		deal(address);
		break;
		case 5: //����
		break;
		}
	} while (choice != 5);
	free(address); //�޸� �ݳ�
	return 0;
}