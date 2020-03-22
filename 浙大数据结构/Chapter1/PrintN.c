#include <stdio.h>
#include <math.h>

void PrintN(int N);
double f(int n, double a[], double x);

//int main() {
//	//int N;
//
//	//scanf_s("%d", &N);
//	//PrintN(N);
//	double a[] = { 1,2,3 };
//	double p = f(2, a, 2);
//	printf("%f\n", p);
//	return 0;
//}

double f(int n, double a[], double x) {
	int i;
	double p = a[n];
	for (i = n; i > 0; i--)
		p += a[i-1] + x *p;
	return p;
}

//double f(int n, double a[], double x) {
//	int i;
//	double p = a[0];
//	for (i = 1; i <= n; i++)
//		p += (a[i] * pow(x, i));
//	return p;
//}

//void PrintN(int N) {
//	int i;
//	for (i = 1; i <= N; i++)
//		printf("%d\n", i);
//	return;
//}

void PrintN(int N) {
	if (N > 0) {
		PrintN(N - 1);
		printf("%d\n", N);
	}
}