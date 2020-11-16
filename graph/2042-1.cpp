#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
typedef long long ll;
int N, M, K;
ll arr[1000002];
ll tree[3000002];
ll ans;

ll init(int index, int start, int end) {
	if (start == end) {
		tree[index] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		tree[index] = init(index * 2 + 1, start, mid) + init(index * 2 + 2, mid + 1, end);
	}
	return tree[index];
}

void update(int target_index, ll diff, int index, int start, int end) {
	if (start > target_index || end < target_index)
		return;

	tree[index] += diff;

	if (start != end) {
		int mid = (start + end) / 2;

		update(target_index, diff, index * 2 + 1, start, mid);
		update(target_index, diff, index * 2 + 2, mid + 1, end);
	}
}

ll sum(int index, int start, int end, int left, int right) {
	if (start > right || end < left)
		return 0;

	if (start >= left && end <= right)
		return tree[index];
	else {
		int mid = (start + end) / 2;
		return sum(index * 2 + 1, start, mid, left, right) + sum(index * 2 + 2, mid + 1, end, left, right);
	}
}
void show() {
	for (int i = 0; i < 3 * N; i++) {
		printf("TREE[%d] = %lld\n", i, tree[i]);
	}
}
int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N ; i++)
		scanf("%lld", &arr[i]);

	init(0, 0, N - 1);

	//show();

	int a, b, c;
	int cnt = M + K;
	while (cnt--) {

		scanf("%d", &a);

		if (a == 1) {
			scanf("%d %d", &b, &c);
			ll diff = c - arr[b - 1];
			arr[b - 1] = c;
			update(b - 1, diff, 0, 0, N - 1);
		}
		else {
			scanf("%d %d", &b, &c);
			ans =sum(0, 0, N - 1, b-1, c-1);
			printf("%lld\n", ans);
		}
	}


	return 0;
}