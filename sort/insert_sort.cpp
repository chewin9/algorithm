#include<iostream>
#include<stdlib.h>
using namespace std;

/*
Insert sort
시간 복잡도 : 최선 O(N)
			  최약 O(N^2)

index가 1부터 시작해서 index-1부터 비교하면서 위치를 찾아간다.

*/
void show(int arr[], int index) {
	printf("%d sort= ", index);
	for (int i = 0; i < 9; i++) {
		printf("%2d", arr[i]);
	}
	printf("\n");
}

void insertsort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int now = arr[i];
		int index = i - 1;

		while (0 <= index && now < arr[index]) {
			arr[index + 1] = arr[index];
			index--;
		}
		arr[index + 1] = now;

		show(arr, i);
	}
}

int main() {

	int arr[] = { 9,3,2,6,1,4,8,7,5 };

	show(arr, -1);
	//printf("%d", sizeof(arr) / sizeof(int));
	insertsort(arr, sizeof(arr) / sizeof(int));

	show(arr, 0);
	return 0;
}