#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>

using namespace std;

typedef long long ll;
int N, M, K;
ll arr[1000002];
ll tree[3000002];
ll D_num = 1000000007;
ll ans;

ll update(int change_index, int val, int index, int start, int end) {
	if (start > change_index || end < change_index)
		return tree[index];
	if (start == end) {
		tree[index] = val;
		return tree[index];
	}

	int mid = (start + end) / 2;

	return tree[index] = (update(change_index, val, index * 2 + 1, start, mid) *
		update(change_index, val, index * 2 + 2, mid+1, end)) % D_num;
}

//void update(int change_index, int ori, int change, int index, int start, int end) {
//	if (start > change_index || end < change_index)
//		return;
//	if (tree[index] != 0) {
//		tree[index] /= ori;
//		tree[index] = (tree[index] * change) % D_num;
//	}
//
//	if (start != end) {
//		int mid = (start + end) / 2;
//		update(change_index, ori, change, index * 2 + 1, start, mid);
//		update(change_index, ori, change, index * 2 + 2, mid+1, end);
//	}
//}

ll get_mul(int index, int start, int end, int left, int right) {
	if (start > right || end < left)
		return 1;
	else if (start >= left && end <= right) {
		return tree[index];
	}
	else {
		int mid = (start + end) / 2;
		return (get_mul(index * 2 + 1, start, mid, left, right) *
			get_mul(index * 2 + 2, mid + 1, end, left, right)) % D_num;
	}
}

ll init(int index, int start, int end) {
	if (start == end)
		tree[index] = arr[start];
	else {
		int mid = (start + end) / 2;
		tree[index] = (init(index * 2 + 1, start, mid) * init(index * 2 + 2, mid + 1, end)) % D_num;
	}
	return tree[index];
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);

	init(0, 0, N - 1);

	int h = ceil(log2(N));
	int size = 1 << (h + 1);

	/*for (int i = 0; i < size; i++) {
		printf("TREE[%d] = %lld\n", i, tree[i]);
	}*/

	int cnt = M + K;

	int a, b, c;
	while (cnt--) {
		scanf("%d", &a);

		if (a == 1) {
			scanf("%d %d", &b, &c);
			update(b - 1, c, 0, 0, N - 1);

			/*printf("\n\n\n");
			for (int i = 0; i < size; i++) {
				printf("TREE[%d] = %lld\n", i, tree[i]);
			}*/

		}
		else {
			scanf("%d %d", &b, &c);
			ans = get_mul(0, 0, N - 1, b - 1, c - 1);
			printf("%lld\n", ans);

		}
	}

	return 0;
}