#include<iostream>
#include<time.h>	

using namespace std;


int Max(const int a[], int n) {int max = a[0];

	for (int i = 0; i < n; i++)
		if (max < a[i])
			max = a[i];

	return max;
}

int main() {

	int *p;
	int n;

	printf("input num: ");
	scanf("%d", &n);

	p = (int*)malloc(n * sizeof(int));

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		p[i] = 100 + rand() % 100;
	}
	for (int i = 0; i < n; i++) {
		printf("%4d", p[i]);
	}

	printf("\n최대값은 %d \n", Max(p,n));

	free(p);

	return 0;
}