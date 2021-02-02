#include<iostream>

using namespace std;

double Averof(const int arr[], int n) {
	double sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	return sum / n;
}

int main() {
	int n;
	int *arr;

	printf("input number ");
	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("input tall ");
		scanf("%d", &arr[i]);
	}
	printf("average of tall %0.2f \n", Averof(arr, n));

	return 0;
}