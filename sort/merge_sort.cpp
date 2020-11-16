#include<iostream>
#include<stdlib.h>
using namespace std;

/*
Merge sort
�ð� ���⵵ : O(N*logN)

�߰� ���� �������� ������ �պ��ϸ鼭 ����

*/
void show(int arr[], int index) {
	printf("%d sort= ", index + 1);
	for (int i = 0; i < 9; i++) {
		printf("%2d", arr[i]);
	}
	printf("\n");
}

void merge(int arr[], int left, int mid, int right) {
	int i, j, k;
	i = left;
	j = mid + 1;
	k = i;

	int *sorted = (int *)malloc(sizeof(int)*9);

	while (i <= mid && j <= right) {
		if (arr[i] < arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	if (i > mid) {
		for (int t = j; t < right + 1; t++)
			sorted[k++] = arr[t];
	}
	else
		for (int t = i; t < mid + 1; t++)
			sorted[k++] = arr[t];

	for (int t = left; t < right+1; t++)
		arr[t] = sorted[t];
	free(sorted);
}

void mergesort(int arr[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		mergesort(arr, left, mid);
		mergesort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}


int main() {

	int arr[] = { 9,3,2,6,1,4,8,7,5 };

	show(arr, -1);
	//printf("%d", sizeof(arr) / sizeof(int));
	mergesort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	show(arr, 0);
	return 0;
}