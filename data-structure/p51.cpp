#include<iostream>

using namespace std;

int main() {

	int *p;
	int n;

	printf("input size: ");
	scanf("%d", &n);

	p = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		//printf("input num: ");
		scanf("%d", &p[i]);
	}

	for (int i = 0; i < n; i++) {
		printf("%2d", p[i]);
	}

	free(p);



	return 0;
}