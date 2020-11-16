#include<iostream>
#include<stdlib.h>
using namespace std;

/*
Heapsort
시간 복잡도 : O(N*logN)

완전 이진트리로 최대 힙 트리 또는 최소 힙트리로 구성한다 -> heapify

구성 후 루트 노드와 마지막 리프노드를 바꾸고 다시 힙 구성, size는 하나씩 빼주고
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

	int *sorted = (int *)malloc(sizeof(int) * 9);

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

	for (int t = left; t < right + 1; t++)
		arr[t] = sorted[t];
	free(sorted);
}

void heapify(int arr[], int size, int pos) {
	int p, l, r;

	p = pos;
	l = p * 2 + 1;
	r = p * 2 + 2;

	if (l <size && arr[l] > arr[p])
		p = l;
	if (r <size && arr[r]>arr[p])
		p = r;

	if (p != pos) {
		int tmp = arr[pos];
		arr[pos] = arr[p];
		arr[p] = tmp;

		heapify(arr, size, p);
	}
}

void heapsort(int arr[], int size) {

	for (int i = (size / 2) - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}

	for (int i = size - 1; i > 0; i--) {
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;

		heapify(arr, i, 0);

		show(arr, size - i);
	}
}


int main() {

	int arr[] = { 9,3,2,6,1,4,8,7,5 };

	show(arr, -1);
	//printf("%d", sizeof(arr) / sizeof(int));
	heapsort(arr, sizeof(arr)/sizeof(int));

	show(arr, 0);
	return 0;
}