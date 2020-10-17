#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;


int T;
int N;
int arr[100002];
int visit[100002];		//시작점
int deep[100002];		//이 지점에 오기전에 얼마나 방문했는지/ 방문했는지
int ans = 0;

void dfs(int start, int pos, int cnt) {
	visit[pos] = start;
	deep[pos] = cnt;

	int next = arr[pos];

	if (deep[next] == 0) {
		dfs(start, next, cnt + 1);
	}

	if (deep[next] != 0 && visit[next] == start) {
		ans += cnt - deep[next] + 1;
		return;
	}
	else if (deep[next] != 0 && visit[next] != start) {
		return;
	}
}

int main() {

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		memset(arr, 0, sizeof(arr));
		memset(visit, -1, sizeof(visit));
		memset(deep, 0, sizeof(visit));
		ans = 0;
		scanf("%d", &N);

		for (int i = 1; i < N + 1; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 1; i < N + 1; i++) {
			if (deep[i] == 0) {
				dfs(i, i, 1);
			}
		}
		printf("%d\n", N-ans);
	}


	return 0;
}