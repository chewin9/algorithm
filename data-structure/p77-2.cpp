#include<iostream>

using namespace std;

int Sumof(const int arr[], int n) {
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	return sum;
}

int main() {
	int n;
	int *arr;

	printf("input number ");
	scanf("%d", &n);

	arr = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("input tall: ");
		scanf("%d", &arr[i]);
	}

	printf("Sum of tall %d \n", Sumof(arr, n));

	return 0;
}