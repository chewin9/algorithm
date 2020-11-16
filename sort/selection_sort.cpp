#include<iostream>

using namespace std;

/*
Selection sort
시간 복잡도 : O(N^2)
공간 복잡도 : O(N)

단순하다.

*/
void show(int arr[], int index) {
	printf("%d sort= ", index + 1);
	for (int i = 0; i < 9; i++) {
		printf("%2d", arr[i]);
	}
	printf("\n");
}

void selection_sort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int now = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[now] > arr[j])
				now = j;
		}
		int tmp = arr[now];
		arr[now] = arr[i];
		arr[i] = tmp;

		show(arr, i);
	}
}


int main() {

	int arr[] = { 9,3,2,6,1,4,8,7,5 };

	show(arr, -1);
	//printf("%d", sizeof(arr) / sizeof(int));
	selection_sort(arr, sizeof(arr)/sizeof(int)	);


	return 0;
}