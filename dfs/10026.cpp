#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int N;
int arr[102][102];
bool visit[102][102];
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };
typedef pair<int, int> pii;
queue<pii> q;

void bfs(int ypos, int xpos) {
	q.push({ ypos,xpos });
	visit[ypos][xpos] = true;
	int col = arr[ypos][xpos];

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > N)
				continue;
			if (arr[ny][nx] == col && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}


}

void dfs(int ypos, int xpos) {
	visit[ypos][xpos] = true;

	int now = arr[ypos][xpos];

	for (int i = 0; i < 4; i++) {
		int ny = ypos + dy[i];
		int nx = xpos + dx[i];

		if (ny <= 0 || ny > N || nx <= 0 || nx > N)
			continue;
		if (arr[ny][nx] == now && visit[ny][nx] == false)
			dfs(ny, nx);
	}
}

int main() {
	int ans = 0;
	int r_ans = 0;
	scanf("%d", &N);
	char c;

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf(" %c", &c);
			if (c == 'R')
				arr[i][j] = 0;
			else if (c == 'G')
				arr[i][j] = 1;
			else
				arr[i][j] = 2;
		}
	}
	/*
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
	*/
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (visit[i][j] == false) {
				//dfs(i, j);
				bfs(i, j);
				ans++;
			}
		}
	}
	memset(visit, false, sizeof(visit));

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
			}
		}
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (visit[i][j] == false) {
				//dfs(i, j);
				bfs(i, j);
				r_ans++;
			}
		}
	}

	printf("%d %d", ans, r_ans);

	return 0;
}