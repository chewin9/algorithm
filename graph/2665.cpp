#include<iostream>
#include<algorithm>
#include<string.h>
#include<deque>

using namespace std;

typedef pair<int, int> pii;
deque<pii> dq;

int N;
int arr[52][52];
int visit[52][52];

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void bfs(int ypos, int xpos) {		//1 »Ú 0 ∞À
	visit[ypos][xpos] = 0;
	dq.push_front({ ypos,xpos });

	int ny, nx;
	while (!dq.empty()) {
		pii now = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > N)
				continue;
			if (arr[ny][nx] == 1 && visit[ny][nx] == -1) {
				dq.push_front({ ny,nx });
				visit[ny][nx] = visit[now.first][now.second];
			}
			if (arr[ny][nx] == 0 && visit[ny][nx] == -1) {
				dq.push_back({ ny,nx });
				visit[ny][nx] = visit[now.first][now.second] + 1;
			}
		}
	}
}

int main() {

	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	memset(visit, -1, sizeof(visit));
	bfs(1, 1);

	printf("%d\n", visit[N][N]);

	return 0;
}