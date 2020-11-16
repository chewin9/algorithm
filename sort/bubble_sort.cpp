#include<iostream>

using namespace std;

/*
Bubble sort
시간 복잡도 : O(N^2)
공간 복잡도 : O(N)

인접 값들끼리 비교하면서 정렬함
하나씩 위치가 정해지기 때문에 N * (N-1)

*/
void show(int arr[], int index) {
	printf("%d sort= ", index + 1);
	for (int i = 0; i < 9; i++) {
		printf("%2d", arr[i]);
	}
	printf("\n");
}


void bubble_sort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		show(arr, i);
	}
}


int main() {

	int arr[] = { 9,3,2,6,1,4,8,7,5 };

	show(arr, -1);
	//printf("%d", sizeof(arr) / sizeof(int));
	bubble_sort(arr, sizeof(arr) / sizeof(int));


	return 0;
}