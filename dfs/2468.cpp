#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;

int N;
int arr[102][102];
int ans = -1e9;
//int copy_arr[102][102];
bool visit[102][102];
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };
typedef pair<int, int> pii;
queue<pii> q;

void bfs(int ypos, int xpos) {
	q.push({ ypos,xpos });
	visit[ypos][xpos] = true;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			
			if (ny <= 0 || ny > N || nx <= 0 || ny > N)
				continue;
			if (arr[ny][nx] != 0 && visit[ny][nx] == false) {
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

		if (ny <= 0 || ny > N || nx <= 0 || ny > N)
			continue;
		if (arr[ny][nx] != 0 && visit[ny][nx] == false)
			dfs(ny, nx);
	}
}

void wetArr(int high) {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j] <= high)
				arr[i][j] = 0;
		}
	}
}

int main() {
	scanf("%d", &N);
	int tall = -1e9;
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &arr[i][j]);
			tall = max(tall, arr[i][j]);
		}
	
	for (int h = 0; h < tall; h++) {
		wetArr(h);
		memset(visit, false, sizeof(visit));
		int cnt = 0;
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (arr[i][j] != 0 && visit[i][j] == false) {
					//dfs(i, j);
					bfs(i, j);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}

	printf("%d\n", ans);

	return 0;
}