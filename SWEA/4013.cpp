#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> pii;
pii change[5];
int T, K;
int arr[5][8];
vector<pii> v;

void spin(int pos, int dir) {
	int tmp = 0;
	if (dir == 1) {			//시계방향
		tmp = arr[pos][7];
		for (int i = 7; i > 0; i--) {
			arr[pos][i] = arr[pos][i - 1];
		}
		arr[pos][0] = tmp;
	}
	else if (dir == -1) {
		tmp = arr[pos][0];
		for (int i = 0; i < 7; i++)
			arr[pos][i] = arr[pos][i + 1];
		arr[pos][7] = tmp;
	}
}

void go_change() {
	for (int i = 1; i < 5; i++) {
		if (change[i].first == true) {
			spin(i,change[i].second);
		}
	}
}

void check_change(int pos) {
	memset(change, 0, sizeof(change));

	int now = v.at(pos).first;
	int dir = v.at(pos).second;

	change[now] = { 1,dir };

	for (int i = now; i < 4; i++) {
		if (arr[i][2] != arr[i + 1][6]) {
			change[i + 1] = { 1, -change[i].second };
		}
		else
			break;
	}
	for (int i = now; i > 1; i--) {
		if (arr[i][6] != arr[i - 1][2]) {
			change[i - 1] = { 1, -change[i].second };
		}
		else
			break;
	}

	/*for (int i = 1; i < 5; i++) {
		printf("{%d %d} => ", change[i].first, change[i].second);
	}
	printf("\n");*/
}

void show() {
	printf("\nShow\n");
	for (int i = 1; i < 5; i++) {
		printf("%d = ", i);
		for (int j = 0; j < 8; j++) {
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {

	freopen("sample_input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		int ans = 0;
		v.clear();
		memset(arr, 0, sizeof(arr));

		scanf("%d", &K);
		for (int i = 1; i < 5; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		int a, b;
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &a, &b);
			v.push_back({ a,b });
		}

		for (int i = 0; i < K; i++) {
			check_change(i);
			go_change();
			//show();
		}
		for (int i = 1; i < 5; i++) {
			if (arr[i][0] == 1) {
				ans += pow(2, i - 1);
			}
		}
		printf("#%d %d\n", t, ans);
	}



	return 0;
}