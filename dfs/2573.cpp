#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

int N, M;
int arr[302][302];
int t_arr[302][302];
int ans;
bool visit[302][302];
bool two = false;
typedef pair<int, int> pii;
queue<pii> q;
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };

void bfs(int ypos, int xpos) {
	visit[ypos][xpos] = true;
	q.push({ ypos,xpos });

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny > N || ny <= 0 || nx > M || nx <= 0)
				continue;
			if (arr[ny][nx] != 0 && visit[ny][nx] == false){
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}
}

void dfs(int ypos, int xpos) {
	visit[ypos][xpos] = true;

	for (int i = 0; i < 4; i++) {
		int ny = ypos + dy[i];
		int nx = xpos + dx[i];
		if (ny > N || ny <= 0 || nx > M || nx <= 0)
			continue;
		if (arr[ny][nx] != 0 && visit[ny][nx] == false)
			dfs(ny, nx);
	}
}

void getArr() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			t_arr[i][j] = arr[i][j];
		}
	}
	int ny = 0;
	int nx = 0;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				ny = i + dy[k];
				nx = j + dx[k];
				if (ny <= 0 || ny > N | nx <= 0 || nx > M)
					continue;
				if (arr[ny][nx] == 0)
					cnt++;
			}
			t_arr[i][j] -= cnt;
		}
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			arr[i][j] = t_arr[i][j];
			if (arr[i][j] < 0)
				arr[i][j] = 0;
		}
	}
	ans++;
	/*
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	while (!two) {
		int cnt = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < M + 1; j++) {
				if (arr[i][j] != 0 && visit[i][j] == false) {
					dfs(i, j);
					//bfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt == 0) {
			two = true;
		}
		if (cnt >= 2)
			break;
		getArr();
	}

	if (two)
		printf("0\n");
	else
		printf("%d\n", ans);

	return 0;
}