#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define StackLimit 20


typedef int StackElementType;
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

void CreateStack(StackType *Stack);
bool EmptyStack(StackType Stack);
bool FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

void TraverseStack(StackType Stack);
void  FilterStack(StackType *Stack, StackElementType delete_item);


int main()
{
    StackType Stack;
    StackElementType item;
    StackElementType delete_item;
    int n;

    CreateStack(&Stack);
    printf("Dwse to plh8os twn stoixeivn:");
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        printf("Dwse to %d stoixeio:", i+1);
        scanf ("%d", &item);
        Push(&Stack,item);
    }

    printf("Dwse to stoixeio gia diagrafh:");
    scanf("%d",&delete_item);
    FilterStack(&Stack,delete_item);
    TraverseStack(Stack);


    return 0;
}

void  FilterStack(StackType *Stack, StackElementType delete_item)
{
    StackType TempStack;
    StackElementType popped;
    CreateStack(&TempStack);
    TraverseStack(*Stack);
    while (!EmptyStack(*Stack) ) {
  while (popped != delete_item) {
    Pop(Stack, &popped);
    TraverseStack(*Stack);
    Push(&TempStack, popped);
    if(popped != delete_item)
      TraverseStack(TempStack);
  }
  if(popped==delete_item){
    Pop(&TempStack,&popped);
    TraverseStack(TempStack);
    break;
  }

    }
    while (!EmptyStack(TempStack)){
        StackElementType popped;
        Pop(&TempStack, &popped); // Use correct Pop signature
  if (popped != delete_item) {
    Push(Stack, popped);
  }
  TraverseStack(TempStack);
  TraverseStack(*Stack);
    }
}


void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

bool EmptyStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}

bool FullStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* �������: ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������: ������ ������� �������, �� � ������ Stack ����� ������
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* �������: ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:  ������ ����� ������� �� � Stack ����� ����
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
