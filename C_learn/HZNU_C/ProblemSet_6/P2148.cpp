#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef struct Node Node;
typedef PtrToNode List;

List read()
{
	List head = (List)malloc(sizeof(Node));
	head->Next = NULL;
	List now = head;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		List tmp = (List)malloc(sizeof(Node));
		tmp->Next = NULL;
		scanf("%d", &tmp->Data);
		now->Next = tmp;
		now = now->Next;
	}
	return head;
}
void PrintList(List L)
{
	int cot = 0;
	List now = L->Next;
	while (now)
	{
		if (cot)printf(" ");
		cot++;
		printf("%d", now->Data);
		now = now->Next;
	}
	if (!cot)printf("NULL");
	printf("\n");
}

void ListReverse(List x); //提交该函数

int main()
{
	List L1 = read();
	PrintList(L1);
	ListReverse(L1);
	PrintList(L1);
}
void ListReverse(List x){
    Node* temp = x , *prev = nullptr;
    while(temp != NULL){
        Node* next = temp->Next;
        temp->Next = prev;
        prev = temp;
        temp = next;
    }
    x = prev;
}