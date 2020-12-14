#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

typedef pair<int, int> pii;
queue<pii> q;
int N, M;
int arr[102][102];
int visit[102][102];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int ans;
void bfs(int ypos, int xpos) {
	visit[ypos][xpos] = 1;
	q.push({ ypos,xpos });

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int ny, nx;
		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (arr[ny][nx] == 1 && visit[ny][nx] == -1) {
				q.push({ ny,nx });
				visit[ny][nx] = visit[now.first][now.second]+1;
			}
		}
	}
}
int main() {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	memset(visit, -1, sizeof(visit));
	bfs(0, 0);

	printf("%d\n", visit[N-1][M-1]);
	return 0;
}