#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>

using namespace std;

int N, M;
int map[10][10];
int c_map[10][10];
bool visit[10][10];
bool c_visit[10][10];
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };
typedef pair<int, int> pii;
queue<pii> q;
int ans = -1e9;

void get_arr() {
	int cnt = 0;
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			if (c_map[i][j] == 0)
				cnt++;
	ans = max(ans, cnt);
}

void start_virus() {
	memset(c_visit, false, sizeof(c_visit));

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (c_map[i][j] == 2) {
				q.push({ i,j });
				c_visit[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > M)
				continue;
			if (c_map[ny][nx] == 0 && c_visit[ny][nx] == false) {
				q.push({ ny,nx });
				c_visit[ny][nx] = true;
				c_map[ny][nx] = 2;
			}
		}
	}
}

void copy_map() {
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			c_map[i][j] = map[i][j];
}

void dfs(int ypos, int xpos, int cnt) {
	visit[ypos][xpos] = true;
	map[ypos][xpos] = 1;

	if (cnt == 3) {
		copy_map();
		start_virus();
		get_arr();
		visit[ypos][xpos] = false;
		map[ypos][xpos] = 0;
		return;
	}

	for (int i = ypos; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (map[i][j] == 0 && visit[i][j] == false) {
				dfs(i, j, cnt + 1);
			}
		}
	}

	visit[ypos][xpos] = false;
	map[ypos][xpos] = 0;

}


int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (map[i][j] == 0) {
				dfs(i, j,1);
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}