#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 50 //구조체 배열의 크기
int count = 0; //몇 개의 정보를 담고있는지 확인을 위해
struct AddressBook {
	char name[10];
	char phone[15];
	char addr[50];
	char birthday[8];
}; //구조체
void list(struct AddressBook const* address)//주소록에 데이터를 보여주기 위해
{
	int i;
	if (count == 0)
	{
		printf(">> 등록된 주소록이 없습니다.\n\n");
	}
	else {
		printf("\n이름\t전화번호\t주소\t생일\n");
		printf("-------------------------------------------------------------------------------\n");
		for (i = 0; i < count; i++)
		{
			printf("%s\t%s\t%s\t%s\n\n", address[i].name, address[i].phone,
				address[i].addr, address[i].birthday);
		}
	}
}

void append(struct AddressBook const* address)//주소록에 데이터를 추가하기 위해
{
	printf("추가할 이름 : ");
	scanf(" %[^\n]s", address[count].name);
	printf("추가할 전화번호 : ");
	scanf(" %[^\n]s", address[count].phone);
	printf("추가할 주소 : ");
	scanf(" %[^\n]s", address[count].addr);
	printf("추가할 생일 : ");
	scanf(" %[^\n]s", address[count].birthday);
	//" %[^\n]s"를 사용한 이유는 공백까지 받기 위해서 입니다. 
	count++;
}
void search(struct AddressBook const* address)//주소록에 데이터를 검색하기 위해
{
	char name[10];
	int compare = 2;
	printf("검색할 이름 : ");
	scanf(" %[^\n]s", name);
	for (int i = 0; i < count; i++)
	{
		compare = strcmp(name, address[i].name); //비교를 해서 사용자가 찾는 데이터가 있는지 확인. 
		if (compare == 0) //있다면 출력
		{
			printf("\n이름\t전화번호\t주소\t생일\n");
			printf("-------------------------------------------------------------------------------\n");
			printf("%s\t%s\t%s\t%s\n\n", address[i].name, address[i].phone,
				address[i].addr, address[i].birthday);
			break;
		}
	}
	if (compare != 0)
		printf("검색 결과가 없습니다.");
}
void deal(struct AddressBook const* address) //주소록에 데이터를 삭제하기 위해
{
	char name[10];
	int compare = 2;
	int i, j;
	printf("삭제할 이름 : ");
	scanf(" %[^\n]s", name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(name, address[i].name) == 0) // 비교를 해서 사용자가 찾는 데이터가 있는지 확인. 
		{
			for (j = i; j + 1 < count; j++)
			{
				//단순 삭제가 어려우니, 뒤에 데이터를 앞으로 당겨와서 넣어주기
				strcpy(address[j].name, address[j + 1].name);
				strcpy(address[j].phone, address[j + 1].phone);
				strcpy(address[j].addr, address[j + 1].addr);
				strcpy(address[j].birthday, address[j + 1].birthday);
			}
			printf("삭제완료!\n\n");
			count--;
		}
		else if (i == count)
		{
			printf("%s의 정보가 없습니다.\n\n", name);
		}
	}
}
int main()
{
	struct AddressBook* address;
	address = (struct AddressBook*)malloc(SIZE * sizeof(struct AddressBook));
	//동적메모리로 구조체 배열 선언.. 
	int choice;
	do {
		printf("\n\n==========================================================================\n");
		printf("---------------------------주소록 메뉴------------------------------------\n");
			printf("\n\n========================================================================== \n");
				printf("1) 목록보기\t2)추가\t3)검색\t4)삭제\t5)종료\n");
		printf(">> ");
		scanf("%d", &choice);
		switch (choice) //switch문으로 어떤 메뉴를 선택했는지 확인하고, 거기에 맞는 함수를 제공
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
		case 5: //종료
		break;
		}
	} while (choice != 5);
	free(address); //메모리 반납
	return 0;
}