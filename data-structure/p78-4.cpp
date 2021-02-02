#include<iostream>
#include<stdlib.h>
#include<time.h>

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

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = 5 + rand() % 15;
	}

	printf("Average of tall %0.3lf \n", Averof(arr, n));

	return 0;
}