#include<iostream>

using namespace std;

void Swap(int arr[], int n) {


	int tmp;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", arr[j]);
		}
		printf("\nSwap arr[%d], arr[%d]\n", i, n - i - 1);
		tmp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = tmp;
	}
}


int main() {
	int n;
	int* arr;

	printf("input number: ");
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	Swap(arr, n);
	for (int i = 0; i < n; i++)
		printf("%3d", arr[i]);

	return 0;
}