#include<iostream>

using namespace std;

void Swap(int arr[], int size) {
	int t;

	for (int i = 0; i < size / 2; i++) {
		t = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = t;
	}
}

int main() {

	int *arr;
	int n;

	printf("input size: ");
	scanf("%d", &n);

	arr = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("before swap\n");
	for (int i = 0; i < n; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");

	Swap(arr, n);

	printf("after swap\n");
	for (int i = 0; i < n; i++) {
		printf("%3d", arr[i]);
	}

	free(arr);
	return 0;
}