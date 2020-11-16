#include<iostream>
#include<stdlib.h>
using namespace std;

/*
Quick sort
�ð� ���⵵ : �־� O(N^2)
			  �ּ� O(N*logN)

pivot�� �������� pivot���� ������ ����, ū�� ���������� ����
���� �ٽ� quick, ������ �ٽ� quick
���ĵ� �迭�̸� �־�


*/
void show(int arr[], int index) {
	printf("%d sort= ", index + 1);
	for (int i = 0; i < 9; i++) {
		printf("%2d", arr[i]);
	}
	printf("\n");
}

int partition(int arr[], int left, int right) {
	int pivot, index;
	int L, R;

	L = left+1;
	R = right;
	pivot = arr[left];

	while (L <= R) {
		while (L <= R && arr[L] < pivot)
			L++;
		while (L <= R && arr[R] > pivot)
			R--;

		if (L <= R) {
			int tmp = arr[L];
			arr[L] = arr[R];
			arr[R] = tmp;
		}
	}

	int tmp = arr[R];
	arr[R] = pivot;
	arr[left] = tmp;

	return R;
}

void quicksort(int arr[], int left, int right) {
	if (left < right) {

		int p = partition(arr, left, right);

		quicksort(arr, left, p - 1);
		quicksort(arr, p + 1, right);
	}

}

int main() {

	int arr[] = { 9,3,2,6,1,4,8,7,5 };

	show(arr, -1);
	//printf("%d", sizeof(arr) / sizeof(int));
	quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	show(arr, 0);
	return 0;
}