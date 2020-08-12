#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int T, N;
int arr[100002];
int visit[100002];
int cycle[100002];
int ans = 0;

void dfs(int start, int pos, int cnt) {

	visit[pos] = cnt;
	cycle[pos] = start;

	int next = arr[pos];

	if (visit[next] == 0) {
		dfs(start, next, cnt + 1);
	}
	else if (visit[next] != 0 && cycle[next] == start) {
		ans += cnt - visit[next] + 1;
		return;
	}
	else if (visit[next] != 0 && cycle[next] != start) {
		return;
	}
}

int main() {
	scanf("%d ", &T);

	for (int t = 0; t < T; t++) {
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		memset(cycle, 0, sizeof(cycle));
		ans = 0;

		scanf("%d", &N);

		for (int i = 1; i < N + 1; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 1; i < N + 1; i++)	{
			if (visit[i] != 0)
				continue;
			if (visit[arr[i]] == 0) {
				dfs(i, i, 1);
			}
		}
		printf("%d\n", N - ans);
	}

	return 0;
}