#include<iostream>
#include<algorithm>

using namespace std;

int arr[100002];
int N, M;

int search(int find) {
	int start, end;

	start = 0;
	end = N - 1;

	while (start<=end) {
		int mid = (start + end) / 2;

		if (arr[mid] == find)
			return 1;

		else if (arr[mid] >= find) {
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return 0;
}

	

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr+N);

	scanf("%d", &M);

	int find;
	for (int i = 0; i < M; i++) {
		scanf("%d", &find);
		printf("%d\n",search(find));
	}

	return 0;
}