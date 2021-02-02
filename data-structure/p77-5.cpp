#include<iostream>

using namespace std;

void Swap(int arr[], int n) {
	int tmp;

	for (int i = 0; i < n / 2; i++) {
		printf("arr[%d] swap arr[%d] \n", i, n - i-1);
		tmp = arr[i];
		arr[i] = arr[n - i-1];
		arr[n - i-1] = tmp;
		for (int j = 0; j < n; j++) {
			printf("%3d", arr[j]);
		}
		printf("\n");
	}
}

int main() {

	int n;
	int *arr;

	printf("input number ");
	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));

	printf("input tall ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	Swap(arr, n);

	return 0;
}