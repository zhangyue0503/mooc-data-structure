#include <stdio.h>
#include <math.h>

int MaxSubseqSum4_1(int List[], int N);
int first;
int last;

int test_main2() {
	int n = 10;
	int s[100000] = { -10, -1, -2, -3, -4, -5, -23, -3, -7, -21 };



	/*scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
	}*/

	int max = MaxSubseqSum4_1(s, n);
	printf("%d %d %d\n", max, first, last);

	return 0;
}

int MaxSubseqSum4_1(int List[], int N)
{
	int i;
	int ThisSum, MaxSum;
	ThisSum = MaxSum = 0;
	first = List[0];
	int f = 0;
	for (i = 0; i < N; i++) {
		if (ThisSum == 0) {
			f = List[i];
		}
		ThisSum += List[i];
		
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
			last = List[i];
			first = f;
		}
		else if (ThisSum < 0) {
			ThisSum = 0;
		}
			
	}
	return MaxSum;
}