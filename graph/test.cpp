#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

typedef long long ll;
int N, M, K;
int arr[1000002];
ll tree[3000000];

void update(int change_index, ll diff,int index, int start, int end) {
	if (change_index > end || change_index < start)
		return;

	tree[index] += diff;

	if (start != end) {
		int mid = (start + end) / 2;
		update(change_index, diff, index * 2 + 1, start, mid);
		update(change_index, diff, index * 2 + 2, mid+1, end);
	}
}

ll get_sum(int index, int start, int end, int left, int right) {
	if (start > right || end < left)
		return 0;
	else if (start >= left && end <= right)
		return tree[index];
	else {
		int mid = (start + end) / 2;
		return get_sum(index * 2 + 1, start, mid, left, right) + get_sum(index * 2 + 2, mid + 1, end, left, right);
	}
}

ll init(int index, int start, int end) {
	if (start == end)
		tree[index] = arr[start];
	else {
		int mid = (start + end) / 2;
		tree[index] = init(index * 2 + 1, start, mid) + init(index * 2 + 2, mid + 1, end);
	}
	return tree[index];
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	init(0, 0, N - 1);

	int h = ceil(log2(N));
	int size = 1 << (h + 1);
	for (int i = 0; i < size; i++) {
		printf("TREE[%d] = %d\n", i, tree[i]);
	}

	update(3, 10, 0, 0, 9);

	for (int i = 0; i < size; i++) {
		printf("TREE[%d] = %d\n", i, tree[i]);
	}

	return 0;
}