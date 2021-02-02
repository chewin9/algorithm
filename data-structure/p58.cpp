#include<iostream>

using namespace std;

int Max(const int a[], int n) {
	int max = a[0];

	for (int i = 1; i < n; i++)
		if (max < a[i])
			max = a[i];

	return max;
}

int main() {
	int n;
	int *p;

	printf("사람 수: ");
	scanf("%d", &n);

	p = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}

	printf("제일 큰 값은 %d \n", Max(p, n));


	free(p);

	return 0;
}