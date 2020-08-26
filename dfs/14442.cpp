#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;

int N, M, K;
int arr[1002][1002];
bool visit[1002][1002][12];
int ans = 1e9;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;
queue<ppi> q;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void bfs(int ypos, int xpos, int bre, int cnt) {
	q.push({ {ypos,xpos},{bre,cnt} });
	visit[ypos][xpos][bre] = true;
	int ny, nx, nb;
	while (!q.empty()) {
		ppi now = q.front();
		q.pop();

		if (now.first.first == N && now.first.second == M) {
			ans = min(ans, now.second.second);
		}

		for (int i = 0; i < 4; i++) {
			ny = now.first.first + dy[i];
			nx = now.first.second + dx[i];
			nb = now.second.first;
			if (ny <= 0 || ny > N || nx <= 0 || nx > M)
				continue;
			if (arr[ny][nx] == 0 && visit[ny][nx][nb] == false) {
				q.push({ {ny,nx},{nb, now.second.second+1} });
				visit[ny][nx][nb] = true;
			}
			if (arr[ny][nx] == 1 && visit[ny][nx][nb] == false && nb != 0) {
				q.push({ {ny,nx},{nb - 1,now.second.second+1} });
				visit[ny][nx][nb - 1] = true;
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	bfs(1, 1, K, 1);

	if (ans != 1e9)
		printf("%d\n", ans);
	else
		printf("-1\n");

	return 0;
}