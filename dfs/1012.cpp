#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

int N, M, T, K;
int arr[52][52];
bool visit[52][52];
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };
typedef pair<int, int> pii;
queue<pii> q;

int dfs(int ypos, int xpos) {
	int cnt = 1;
	visit[ypos][xpos] = true;

	for (int i = 0; i < 4; i++) {
		int ny = ypos + dy[i];
		int nx = xpos + dx[i];

		if (ny >= N || ny < 0 || nx >= M || nx < 0)
			continue;
		if (arr[ny][nx] == 1 && visit[ny][nx] == false)
			cnt+=dfs(ny, nx);
	}
	return cnt;
}

int bfs(int ypos, int xpos) {
	visit[ypos][xpos] = true;
	q.push({ ypos,xpos });
	int cnt = 0;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx, ny;
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny >= N || ny < 0 || nx >= M || nx < 0)
				continue;
			if (arr[ny][nx] == 1 && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}
	return cnt;

}
int main() {
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));
		int cnt = 0;
		int ans;
		int yp, xp;
		scanf("%d %d %d", &M, &N, &K);

		for (int k = 0; k < K; k++) {
			scanf("%d %d", &xp, &yp);
			arr[yp][xp] = 1;
		}
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%2d", arr[i][j]);
			}
			printf("\n");
		}
		*/
		/*
		//dfs
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1 && visit[i][j] == false) {
					ans = dfs(i, j);
					//printf("%2d\n", ans);
					cnt++;
				}
			}
		}
		printf("\n%d\n", cnt);
		*/
		//bfs
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1 && visit[i][j] == false) {
					ans = bfs(i, j);
					printf("%2d", ans);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}


	return 0;
}