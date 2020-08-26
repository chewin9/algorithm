#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

int N, M;
int arr[1002][1002];
bool visit[1002][1002][2];
typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;
queue<ppi> q;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int ans = -1;

void bfs(int ypos, int xpos, int bre, int cnt) {
	visit[ypos][xpos][bre] = true;
	q.push({ {ypos,xpos},{bre,cnt} });

	while (!q.empty()) {
		ppi now = q.front();
		q.pop();
		int ny, nx;

		if (now.first.first == N && now.first.second == M) {
			ans = now.second.second;
			return;
		}

		for (int i = 0; i < 4; i++) {
			ny = now.first.first + dy[i];
			nx = now.first.second + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > M)
				continue;
			if (arr[ny][nx] == 0 && visit[ny][nx][now.second.first] == false) {
				q.push({ {ny,nx}, {now.second.first, now.second.second + 1} });
				visit[ny][nx][now.second.first] = true;
			}
			if (arr[ny][nx] == 1 && visit[ny][nx][now.second.first-1] == false && now.second.first == 1) {
				q.push({ {ny,nx},{now.second.first - 1, now.second.second + 1} });
				visit[ny][nx][now.second.first-1] = true;
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	bfs(1, 1, 1, 1);
	while (!q.empty())
		q.pop();

	printf("%d\n", ans);
	return 0;
}