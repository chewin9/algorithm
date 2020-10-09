#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
typedef struct TREE {
	int min_val= 1e9;
	int max_val = -1e9;
	int val=-1;
}TREE;

int arr[100002];
TREE tree[300000];
int N, M;
int MAX_VAL, MIN_VAL;

void find_val(int index, int start, int end, int left, int right) {
	if (start > right || end < left)
		return;
	else if (start >= left && end <= right) {
		//if (tree[index].val != -1) {
			MAX_VAL = max(MAX_VAL, tree[index].max_val);
			MIN_VAL = min(MIN_VAL, tree[index].min_val);
		//}
	}
	else {
		int mid = (start + end) / 2;
		find_val(index * 2 + 1, start, mid, left, right);
		find_val(index * 2 + 2, mid + 1, end, left, right);
	}
}

void init(int index, int start, int end) {
	if (start == end) {
		tree[index].val = arr[start];
		tree[index].min_val = arr[start];
		tree[index].max_val = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		//printf("INIT(%d, %d, %d) \n", index * 2 + 1, start, mid);
		init(index * 2 + 1, start, mid);
		//printf("INIT(%d %d %d)\n", index * 2 + 2, mid + 1, end);
		init(index * 2 + 2, mid + 1, end);
		tree[index].min_val = min(tree[index * 2 + 1].min_val, tree[index * 2 + 2].min_val);
		tree[index].max_val = max(tree[index * 2 + 1].max_val, tree[index * 2 + 2].max_val);
	}
}

int main() {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	init(0, 0, N - 1);
	/*int h = ceil(log2(N));
	int size = 1 << (1 + h);
	for (int i = 0; i < size; i++) {
		printf("TREE[%d]=", i);
		printf("MAX_VAL = %d, MIN_VAL = %d \n", tree[i].max_val, tree[i].min_val);
	}*/

	int a, b;
	for (int i = 0; i < M; i++) {
		MAX_VAL = -1e9;
		MIN_VAL = 1e9;
		scanf("%d %d", &a, &b);

		find_val(0, 0, N - 1, a - 1, b - 1);

		printf("%d %d\n", MIN_VAL, MAX_VAL);
	}
	return 0;
}