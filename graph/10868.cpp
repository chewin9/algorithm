#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int arr[100002];
int tree[300002];
int N, M;
int ans = 1e9;
void find_val(int index, int start, int end, int left, int right) {
	if (start > right || end < left)
		return;
	else if (start >= left && end <= right)
		ans = min(ans, tree[index]);
	else {
		int mid = (start + end) / 2;
		find_val(index * 2 + 1, start, mid, left, right);
		find_val(index * 2 + 2, mid + 1, end, left, right);
	}
}

void init(int index, int start, int end) {
	if (start == end) {
		tree[index] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		init(index * 2 + 1, start, mid);
		init(index * 2 + 2, mid + 1, end);
		tree[index] = min(tree[index * 2 + 1], tree[index * 2 + 2]);
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	init(0, 0, N - 1);

	/*for (int i = 0; i < 16; i++) {
		printf("TREE[%d] = %d\n", i, tree[i]);
	}*/
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		ans = 1e9;
		find_val(0, 0, N - 1, a - 1, b - 1);
		printf("%d\n", ans);
	}


	return 0;
}