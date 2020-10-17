#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int N, M, K;
typedef long long ll;
ll arr[1000002];
ll tree[3000000];
ll ans;

void update(int change_index, ll diff, int index, int start, int end) {
	if (start > change_index || end < change_index)
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
	else if (start >= left && end <= right) {
		return tree[index];
	}
	else {
		int mid = (start + end) / 2;
		return get_sum(index * 2 + 1, start, mid, left, right) + get_sum(index * 2 + 2, mid + 1, end, left, right);
	}
}

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

int main() {

	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);
	
	init(0, 0, N - 1);

	int h = ceil(log2(N));
	int size = 1 << (h + 1);

	/*for (int i = 0; i < size; i++) {
		printf("TREE[%d] = %d\n", i, tree[i]);
	}*/

	int cnt = M + K;

	int a, b, c;
	ll d;
	while (cnt--) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d %d %lld", &b, &c, &d);

			for (int i = b - 1; i < c; i++) {
				//ll diff = d - arr[i];
				arr[i] += d;
				update(i, d, 0, 0, N - 1);
			}
		}
		else {
			scanf("%d %d", &b, &c);
			ans = get_sum(0, 0, N - 1, b - 1, c - 1);
			printf("%lld\n", ans);
		}
	}

	return 0;
}