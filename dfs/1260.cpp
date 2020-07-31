#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int N, M, V;
int arr[1002][1002];
bool visit[1002];
queue <int> q;

void dfs(int start) {
	if (visit[start] == true)
		return;

	if (visit[start] == false) {
		printf("%d ", start);
		visit[start] = true;
	}

	for (int i = 1; i < N+1; i++) {
		if (arr[start][i] == 1)
			dfs(i);
	}
}

void bfs(int start) {
	visit[start] = true;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d ", now);

		for (int i = 1; i < N + 1; i++) {
			if (arr[now][i] == 1 && visit[i] == false) {
				q.push(i);
				visit[i] = true;
			}
		}
	}
}

int main() {
	int s, e;
	scanf("%d %d %d", &N, &M, &V);

	memset(arr, 0, sizeof(arr));
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		arr[s][e] = arr[e][s] = 1;
	}

	dfs(V);
	memset(visit, false, sizeof(visit));
	printf("\n");
	bfs(V);

	return 0;
}