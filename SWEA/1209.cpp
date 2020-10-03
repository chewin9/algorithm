#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int arr[102][102];
int ans;

void solve() {
	int tmp = -1e9;
	int sum;
	for (int i = 1; i < 101; i++) {
		sum = 0;
		for (int j = 1; j < 101; j++) {
			sum += arr[i][j];
		}
		tmp = max(tmp, sum);
	}
	for (int i = 1; i < 101; i++) {
		sum = 0;
		for (int j = 1; j < 101; j++) {
			sum += arr[j][i];
		}
		tmp = max(tmp, sum);
	}
	sum = 0;
	for (int i = 1; i < 101; i++) {
		sum += arr[i][1];
	}
	tmp = max(tmp, sum);
	sum = 0;
	for (int i = 1; i < 101; i++) {
		sum += arr[101 - i][i];
	}
	tmp = max(tmp, sum);
	ans = tmp;
}

int main() {

	freopen("input.txt", "r", stdin);
	int t;
	while (1) {
		scanf("%d", &t);

		for (int i = 1; i < 101; i++) {
			for (int j = 1; j < 101; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		solve();
		printf("#%d %d\n", t, ans);
		if (t == 10)
			break;
	}


	return 0;
}