#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode* List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

/* List ReadInput(); 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    Position P;

    L->Data[0] = 1;
    L->Data[1] = 2;
    L->Last = 1;
    scanf_s("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}

Position BinarySearch(List L, ElementType X) {
    if (L->Last < 0 ) {
        return NotFound;
    }
    if (L->Last == 0) {
        return L->Data == X ? 1 : NotFound;
    }
    int low = 0;
    int high = L->Last;
    while (low <= high)
    {
        int halfIndex = (low +high) / 2;
        if (X == L->Data[halfIndex]) {
            return halfIndex;
        }
        else if (X > L->Data[halfIndex]) {
            low = halfIndex + 1;
        }
        else {
            high = halfIndex - 1;
        }

    }

    return NotFound;
    
    
}

