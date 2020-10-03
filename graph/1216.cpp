#include<iostream>
#include<algorithm>
#include<string.h>
#include<deque>
#include<queue>
using namespace std;

typedef pair<int, int> pii;
deque<pii> dq;
queue<pii>q;
int N, M;
int arr[102][102];
int visit[102][102];

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void q_bfs(int ypos, int xpos) {
	visit[ypos][xpos] = 0;
	q.push({ ypos,xpos });

	int ny, nx;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > M)
				continue;
			if (arr[ny][nx] == 0 && visit[ny][nx] == -1) {
				q.push({ ny,nx });
				visit[ny][nx] = visit[now.first][now.second];
			}
			if (arr[ny][nx] == 1 && visit[ny][nx] == -1) {
				q.push({ ny,nx });
				visit[ny][nx] = visit[now.first][now.second] + 1;
			}
		}
	}
}

void dq_bfs(int ypos, int xpos) {
	visit[ypos][xpos] = 0;
	dq.push_back({ ypos,xpos });

	int ny, nx;

	while (!dq.empty()) {
		pii now = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > M)
				continue;
			if (arr[ny][nx] == 0 && visit[ny][nx] == -1) {
				dq.push_front({ ny,nx });
				visit[ny][nx] = visit[now.first][now.second];
			}
			if (arr[ny][nx] == 1 && visit[ny][nx] == -1) {
				dq.push_back({ ny,nx });
				visit[ny][nx] = visit[now.first][now.second] + 1;
			}
		}
	}
}

int main() {
	scanf("%d %d", &M, &N);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	memset(visit, -1, sizeof(visit));

	dq_bfs(1, 1);

	//q_bfs(1, 1);
	printf("%d\n", visit[N][M]);


	return 0;
}