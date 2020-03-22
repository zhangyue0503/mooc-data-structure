#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

//int main()
//{
//    List L1, L2, L;
//    L1 = Read();
//    L2 = Read();
//
//
//
//    L = Merge(L1, L2);
//    Print(L);
//    Print(L1);
//    Print(L2);
//    return 0;
//}

List Merge(List L1, List L2) {
    List L = (List)malloc(sizeof(struct Node));
    PtrToNode n1 = L1->Next;
    L1->Next = NULL;
    PtrToNode n2 = L2->Next;
    L2->Next = NULL;
    PtrToNode lastNode = L;
    while (n1 != NULL) {
        if (n2 != NULL) {
            if (n1->Data < n2->Data) {
                
                lastNode->Next = n1;
                lastNode = lastNode->Next;
                n1 = n1->Next;
            }
            else if (n1->Data > n2->Data) {
               
                lastNode->Next = n2;
                lastNode = lastNode->Next;
                n2 = n2->Next;
            }
            else {
                lastNode->Next = n1;
                lastNode = lastNode->Next;
                n1 = n1->Next;
                lastNode->Next = n2;
                lastNode = lastNode->Next;
                n2 = n2->Next;
            }
        }
        else {
            lastNode->Next = n1;
            lastNode = lastNode->Next;
            n1 = n1->Next;
        }
       
    }
    if (n2 != NULL) {
        while (n2 != NULL) {
            lastNode->Next = n2;
            lastNode = lastNode->Next;
            n2 = n2->Next;
        }
    }
    return L;

}

void Print(List L) {
    PtrToNode n = L->Next;
    if (n == NULL) {
        printf("NULL\n");
    }else {
        while (n != NULL) {
            printf("%d ", n->Data);
            n = n->Next;
        }
    }
    printf("\n");
}

List Read() {
     
   List L = (List)malloc(sizeof(struct Node));
   
   int size;
   int i;
   scanf_s("%d", &size);

   PtrToNode lastNode = L;
   for (i = 0; i < size;i++) {
       PtrToNode n = (PtrToNode)malloc(sizeof(struct Node));
       int nData;
       scanf_s("%d", &nData);
       n->Data = nData;
       n->Next = NULL;
       lastNode->Next = n;
       lastNode = n;
   }
   return L;

}


