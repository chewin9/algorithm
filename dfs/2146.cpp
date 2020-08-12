#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int arr[102][102];
bool visit[102][102];
typedef pair<int, int> pii;
queue<pii> q;
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };
int ans = 1e9;

void bfs(int ypos, int xpos, int cnt) {
	q.push({ ypos,xpos });
	visit[ypos][xpos] = true;
	arr[ypos][xpos] = cnt;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny > N || ny <= 0 || nx > N || nx <= 0)
				continue;
			if (arr[ny][nx] != 0 && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
				arr[ny][nx] = cnt;
			}
		}
	}
}
void show() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}
void dfs(int ypos, int xpos, int val, int cnt) {

	if (ypos > N || ypos <= 0 || xpos > N || xpos <= 0)
		return;

	printf("{%d, %d}", ypos, xpos);
	//visit[ypos][xpos] = true;

	if (arr[ypos][xpos] != val && arr[ypos][xpos] != 0) {
		ans = min(ans, cnt);
		visit[ypos][xpos] = false;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = ypos + dy[i];
		int nx = xpos + dx[i];

		if (arr[ny][nx] != val && visit[ny][nx] == false) {
			visit[ny][nx] = true;
			dfs(ny, nx, val, cnt + 1);
			visit[ny][nx] = false;
		}
	}
}
int main() {
	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			scanf("%d", &arr[i][j]);

	int cnt = 1;
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j] != 0 && visit[i][j] == false) {
				bfs(i, j, cnt);
				cnt++;
			}
		}

	show();

	memset(visit, false, sizeof(visit));

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j] != 0 && visit[i][j] == false) {
				printf("start:{%d %d}->", i, j);
				dfs(i, j, arr[i][j],1);
				memset(visit, false, sizeof(visit));
				printf("\n");
			}
		}
	}
	/*
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%2d", visit[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d\n", ans-2);
	return 0;
}