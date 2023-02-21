#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct {
    int size;  //현재 리스트에 저장된 항목들의 개수
    int size_M; //동적으로 어느정도 크기를 할당할 건지
    element* pA;  //동적 메모리 할당을 통한 배열을 가리킬 포인터
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
    printf("어떤 크기의 배열을 만들 것인가요? : ");
    scanf("%d", &list.size_M);
    create(&list); //동적 배열

    init(&list);

    insert(&list, 0, 10);
    print_list(&list); // 0번째 위치에 10 추가

    insert(&list, 0, 20);
    print_list(&list); // 0번째 위치에 20 추가

    insert(&list, 0, 30);
    print_list(&list); // 0번째 위치에 30 추가

    insert_last(&list, 40); 
    print_list(&list); // 맨 끝에 40 추가

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

void init(ArrayListType* L) //리스트 초기화
{
    L->size = 0;
}
int is_Empty(ArrayListType* L)
{
    //리스트가 비어 있으면, 1을 반환, 아니면 0 반환
    return L->size == 0;
}
int is_Full(ArrayListType* L)
{
    //리스트가 꽉 차 있으면, 1을 반환, 아니면 0 반환
    return L->size == L->size_M;
}
element get_entry(ArrayListType* L, int pos)
{
    if (pos < 0 || pos >= L->size)
        error("위치 오류");
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
    //배열 중간에 item을 넣기
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
    //배열 마지막에 item넣기
    if (L->size >= L->size_M)
        error("리스트 오버플로우");
    L->pA[L->size++] = item;  //pA[size]에 item을 넣고 size++한다.
}

element Delete(ArrayListType* L, int pos)
{
    element item;
    if (pos < 0 || pos >= L->size)
        error("위치 오류");
    item = L->pA[pos];
    for (int i = pos; i < (L->size - 1); i++)
        L->pA[i] = L->pA[i + 1];
    L->size--;

    return item;
}