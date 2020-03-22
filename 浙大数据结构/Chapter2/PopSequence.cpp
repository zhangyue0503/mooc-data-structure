#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct SNode* PtrToSNode;
struct SNode {
	ElementType Data;
	PtrToSNode Next;
	int size;
};
typedef PtrToSNode Stack;

Stack CreateStack();
bool IsEmpty(Stack S);
bool Push(Stack S, ElementType X);
ElementType Pop(Stack S);

//int main() {
//	int m = 5;
//	int n = 7;
//	int k = 5;
//
//	scanf_s("%d", &m);
//	scanf_s("%d", &n);
//	scanf_s("%d", &k);
//
//	int line[128][128];
//	int kk,nn;
//	for (kk = 0; kk < k;kk++) {
//		for (nn = 0; nn < n; nn++) {
//			int num;
//			scanf_s("%d", &num);
//			line[kk][nn] = num;
//		}
//	}
//
//	
//
//	
//
//	//int line1[] = { 1, 2, 3, 4, 5, 6, 7 };
//	//int line1[] = { 3, 2, 1, 7, 5, 6, 4 };
//	//int line1[] = { 7, 6, 5, 4, 3, 2, 1 };
//	//int line1[] = { 5, 6, 4, 3, 7, 2, 1 };
//	//int line1[] = { 1, 7, 6, 5, 4, 3, 2 };
//	int kkk = 0;
//	while (kkk < kk) {
//		Stack S = CreateStack();
//		int pushLine[128];
//		int popList[128];
//		int size = 0;
//		int no = 0;
//		int j = 0;
//		int i;
//		for (i = 0; i < n; i++) {
//			//if (IsEmpty(S) ) {
//			Push(S, i + 1);
//			pushLine[i] = line[kkk][i];
//			size++;
//			//}
//			if (size > m) {
//				no = 1;
//				printf("NO\n"); break;
//			}
//			if (i + 1 >= line[kkk][j]) {
//				while (i + 1 >= line[kkk][j]) {
//					int x = Pop(S);
//					//printf("%d ", x);
//					size--;
//					if (x != pushLine[j]) {
//						no = 1;
//						printf("NO\n"); break;
//					}
//					j++;
//					if (j >= n) {
//						break;
//					}
//				}
//				if (no == 1) {
//					break;
//				}
//
//			}
//			//else  {
//			//	Push(S, i + 1);
//			//	size++;
//			//	pushLine[i] = line1[i];
//			//}
//
//		}
//		if (no == 0) {
//			printf("YES\n");
//		}
//		kkk++;
//	}
//	return 0;
//	
//	
//}

Stack CreateStack() {
	Stack S;

	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	S->size = 0;
	return S;
};

bool IsEmpty(Stack S) {
	return(S->Next == NULL);
};

bool Push(Stack S, ElementType X) {
	PtrToSNode TmpCell;

	TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
	TmpCell->Data = X;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	return true;
};

ElementType Pop(Stack S) {
	PtrToSNode FirstCell;
	ElementType TopElem;
	if (IsEmpty(S)) {
		printf("¶ÑÕ»¿Õ");
	}
	else {
		FirstCell = S->Next;
		TopElem = FirstCell->Data;
		S->Next = FirstCell->Next;
		free(FirstCell);
		return TopElem;
	}
}

//Given a stack which can keep M numbers at most.Push N numbers in the order of 1, 2, 3, ..., Nand pop randomly.You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack.For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.
//
//Input Specification :
//
//Each input file contains one test case.For each case, the first line contains 3 numbers(all no more than 1000): M(the maximum capacity of the stack), N(the length of push sequence), and K(the number of pop sequences to be checked).Then K lines follow, each contains a pop sequence of N numbers.All the numbers in a line are separated by a space.
//
//	Output Specification :
//
//																											  For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.
//
//																												  Sample Input :
//
//																											  5 7 5
//																												  1 2 3 4 5 6 7
//																												  3 2 1 7 5 6 4
//																												  7 6 5 4 3 2 1
//																												  5 6 4 3 7 2 1
//																												  1 7 6 5 4 3 2
//
//
//
//																												  Sample Output :
//
//																											  YES
//																												  NO
//																												  NO
//																												  YES
//																												  NO