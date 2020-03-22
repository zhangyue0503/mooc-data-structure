#include <stdio.h>
#include <math.h>

int MaxSubseqSum1(int List[], int N);
int MaxSubseqSum2(int List[], int N);
int MaxSubseqSum3(int List[], int N);
int MaxSubseqSum4(int List[], int N);

int DivideAndConquer(int List[], int left, int right);
int Max3(int A, int B, int C);

void runCode(int s[], int n);

int test_main1() {
	int n = 6;
	int s[100000] = { -2, 11, -4, 13, -5, -2 };
	
	

	scanf_s("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &s[i]);
	}

	// 算法结果验证
	runCode(s, n);
	return 0;

	int symbol;
	int i;
	
	// 10的2次方数据
	n = pow(10, 2);
	for (i = 0; i < n; i++)
	{
		s[i] = rand() % 20;
		symbol = rand();
		if (symbol % 2) //奇数时，为负数，偶数时，为正数
			s[i] = -s[i];
		printf("%d ", s[i]);
	}
	printf("\n");
	runCode(s, n);
	

	// 10的3次方数据
	n = pow(10, 3);
	for (i = 0; i < n; i++)
	{
		s[i] = rand() % 20;
		symbol = rand();
		if (symbol % 2) //奇数时，为负数，偶数时，为正数
			s[i] = -s[i];
		printf("%d ", s[i]);
	}
	printf("\n");
	runCode(s, n);

	// 10的4次方数据
	n = pow(10, 4);
	for (i = 0; i < n; i++)
	{
		s[i] = rand() % 20;
		symbol = rand();
		if (symbol % 2) //奇数时，为负数，偶数时，为正数
			s[i] = -s[i];
		// printf("%d ", s[i]);
	}
	printf("\n");
	runCode(s, n);

	// 10的5次方数据
	n = pow(10, 5);
	for (i = 0; i < n; i++)
	{
		s[i] = rand() % 20;
		symbol = rand();
		if (symbol % 2) //奇数时，为负数，偶数时，为正数
			s[i] = -s[i];
		// printf("%d ", s[i]);
	}
	printf("\n");
	runCode(s, n);
	

	return 0;
}

void runCode(int s[], int n)
{
	int max1, max2, max3, max4;
	max1 = max2 = max3 = max4 = 0;
	/*max1 = MaxSubseqSum1(s, n);
	printf("Max1:%d\n", max1);
	max2 = MaxSubseqSum2(s, n);
	printf("Max2:%d\n", max2);
	max3 = MaxSubseqSum3(s, n);
	printf("Max3:%d\n", max3);*/
	max4 = MaxSubseqSum4(s, n);
	printf("%d", max4);
}

int MaxSubseqSum4(int List[], int N)
{
	int i;
	int ThisSum, MaxSum;
	ThisSum = MaxSum = 0;
	for (i = 0; i < N;i++) {
		ThisSum += List[i];
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
		}
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}

int Max3(int A, int B, int C) {
	return A > B ? A > C ? A : C : B > C ? B : C;
}



int DivideAndConquer(int List[], int left, int right) {
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;

	int LeftBorderSum, RightBorderSum;
	int center, i;

	if (left == right) {
		if (List[left] > 0) return List[left];
		else return 0;
	}

	center = (left + right) / 2;
	MaxLeftSum = DivideAndConquer(List, left, center);
	MaxRightSum = DivideAndConquer(List, center+1, right);

	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = center; i >= left; i--) {
		LeftBorderSum += List[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	MaxRightBorderSum = 0; RightBorderSum = 0;
	for (i = center + 1; i <= right; i++) {
		RightBorderSum += List[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubseqSum3(int List[], int N) {
	return DivideAndConquer(List, 0, N - 1);
}

int MaxSubseqSum2(int List[], int N) {
	int i, j, k;
	int ThisSum, MaxSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum = 0;
		for (j = i; j < N; j++) {
			ThisSum += List[j];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

int MaxSubseqSum1(int List[], int N) {
	int i,j,k;
	int ThisSum, MaxSum = 0;
	for (i = 0; i < N;i++) {
		for (j = i; j < N;j++) {
			ThisSum = 0;
			for (k = i; k <= j; k++)
				ThisSum += List[k];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;


		}
	}
	return MaxSum;
}