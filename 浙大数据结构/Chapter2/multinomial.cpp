#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode* PtrToPolyNode;
struct PolyNode {
	int Coef;
	int Expon;
	PtrToPolyNode Next;
};
typedef PtrToPolyNode Polynomial;

void Attach(int coef, int expon, Polynomial* PtrRear) {
	Polynomial P;

	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Coef = coef;
	P->Expon = expon;
	P->Next = NULL;

	(*PtrRear)->Next = P;
	*PtrRear = P;
}

Polynomial ReadPoly() {
	Polynomial P, Rear, t;
	int coef, expon, N;

	scanf_s("%d", &N);

	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Next = NULL;
	Rear = P;
	while (N--)
	{
		scanf_s("%d %d", &coef, &expon);
		Attach(coef, expon, &Rear);
	}

	t = P; P = P->Next; free(t);
	return P;
}

void PrintPoly(Polynomial P) {
	if (!P) printf("0 0\n");
	else {
		printf("%d %d", P->Coef, P->Expon);
		P = P->Next;
		while (P)
		{
			printf(" %d %d", P->Coef, P->Expon);
			P = P->Next;
		}
		printf("\n");
	}
}

Polynomial Mult(Polynomial P1, Polynomial P2) {
	Polynomial P, Rear, t1, t2, t;
	int coef, expon;

	if (!P1 || !P2) return NULL;

	t1 = P1; t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Next = NULL;
	Rear = P;
	while (t2)
	{
		Attach(t1->Coef * t2->Coef, t1->Expon + t2->Expon, &Rear);
		t2 = t2->Next;
	}
	t1 = t1->Next;
	while (t1) {
		t2 = P2; Rear = P;
		while (t2) {

			expon = t1->Expon + t2->Expon;
			coef = t1->Coef * t2->Coef;

			while (Rear->Next && Rear->Next->Expon > expon)
				Rear = Rear->Next;

			if (Rear->Next && Rear->Next->Expon == expon) {
				if (Rear->Next->Coef + coef)
					Rear->Next->Coef += coef;
				else {
					t = Rear->Next;
					Rear->Next = t->Next;
					free(t);
				}
			}
			else {
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->Coef = coef; t->Expon = expon;
				t->Next = Rear->Next;
				Rear->Next = t; Rear = Rear->Next;
			}
			t2 = t2->Next;
		}
		t1 = t1->Next;
	}
	t = P; P = P->Next; free(t);

	return P;
}

int Compare(int e1, int e2) {
	if (e1 > e2) return 1;
	else if (e1 < e2) return -1;
	else return 0;
}

Polynomial Add(Polynomial P1, Polynomial P2) {
	Polynomial front, rear, temp;
	int sum;

	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;
	while (P1 && P2) {
		switch (Compare(P1->Expon, P2->Expon))
		{
		case 1:
			Attach(P1->Coef, P1->Expon, &rear);
			P1 = P1->Next;
			break;
		case -1:
			Attach(P2->Coef, P2->Expon, &rear);
			P2 = P2->Next;
			break;
		case 0:
			sum = P1->Coef + P2->Coef;
			Attach(sum, P2->Expon, &rear);
			P1 = P1->Next;
			P2 = P2->Next;
			break;
		}
	}

	for (; P1; P1 = P1->Next) Attach(P1->Coef, P1->Expon, &rear);
	for (; P2; P2 = P2->Next) Attach(P2->Coef, P2->Expon, &rear);

	rear->Next = NULL;
	temp = front;
	front = front->Next;

	free(temp);
	return front;

}



int main() {
	Polynomial P1, P2, P;
	P1 = ReadPoly();
	P2 = ReadPoly();


	P = Mult(P1, P2);
	PrintPoly(P);

	P = Add(P1, P2);
	PrintPoly(P);


	return 0;
}