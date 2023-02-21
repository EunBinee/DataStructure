#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct {
    int size;  //���� ����Ʈ�� ����� �׸���� ����
    int size_M; //�������� ������� ũ�⸦ �Ҵ��� ����
    element* pA;  //���� �޸� �Ҵ��� ���� �迭�� ����ų ������
}ArrayListType;

void create(ArrayListType* L);
void error(char* massage);
void init(ArrayListType* L);
int is_Empty(ArrayListType* L);
int is_Full(ArrayListType* L);
element get_entry(ArrayListType* L, int pos);
void print_list(ArrayListType* L);
void insert(ArrayListType* L, int pos, element item);
void insert_last(ArrayListType* L, element item);
element Delete(ArrayListType* L, int pos);

int main()
{
    ArrayListType list;
    printf("� ũ���� �迭�� ���� ���ΰ���? : ");
    scanf("%d", &list.size_M);
    create(&list); //���� �迭

    init(&list);

    insert(&list, 0, 10);
    print_list(&list); // 0��° ��ġ�� 10 �߰�

    insert(&list, 0, 20);
    print_list(&list); // 0��° ��ġ�� 20 �߰�

    insert(&list, 0, 30);
    print_list(&list); // 0��° ��ġ�� 30 �߰�

    insert_last(&list, 40); 
    print_list(&list); // �� ���� 40 �߰�

    Delete(&list, 0);
    print_list(&list);

    free(list.pA);
    return 0;
}
void create(ArrayListType* L)
{
    L->pA = (element*)malloc(sizeof(element) * L->size_M);
}
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(ArrayListType* L) //����Ʈ �ʱ�ȭ
{
    L->size = 0;
}
int is_Empty(ArrayListType* L)
{
    //����Ʈ�� ��� ������, 1�� ��ȯ, �ƴϸ� 0 ��ȯ
    return L->size == 0;
}
int is_Full(ArrayListType* L)
{
    //����Ʈ�� �� �� ������, 1�� ��ȯ, �ƴϸ� 0 ��ȯ
    return L->size == L->size_M;
}
element get_entry(ArrayListType* L, int pos)
{
    if (pos < 0 || pos >= L->size)
        error("��ġ ����");
    return L->pA[pos];
}
void print_list(ArrayListType* L)
{
    int i;
    for (i = 0; i < L->size; i++)
        printf("%d -> ", L->pA[i]);
    printf("\n");
}
void insert(ArrayListType* L, int pos, element item)
{
    //�迭 �߰��� item�� �ֱ�
    if (!is_Full(L) && (pos >= 0) && (pos <= L->size))
    {
        for (int i = (L->size - 1); i >= pos; i--)
            L->pA[i + 1] = L->pA[i];
        L->pA[pos] = item;
        L->size++;
    }
}
void insert_last(ArrayListType* L, element item)
{
    //�迭 �������� item�ֱ�
    if (L->size >= L->size_M)
        error("����Ʈ �����÷ο�");
    L->pA[L->size++] = item;  //pA[size]�� item�� �ְ� size++�Ѵ�.
}

element Delete(ArrayListType* L, int pos)
{
    element item;
    if (pos < 0 || pos >= L->size)
        error("��ġ ����");
    item = L->pA[pos];
    for (int i = pos; i < (L->size - 1); i++)
        L->pA[i] = L->pA[i + 1];
    L->size--;

    return item;
}