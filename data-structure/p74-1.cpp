#include<iostream>

using namespace std;

int Minof(const int arr[], int n) {
	int min = arr[0];

	for (int i = 1; i < n; i++) {
		if (min > arr[i])
			min = arr[i];
	}

	return min;
}
int main() {
	int n;
	int *arr;
	int a;

	printf("input numver: ");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		printf("input tall ");
		scanf("%d", &arr[i]);
	}
	printf("Min tall %d \n", Minof(arr, n));


	return 0;
}