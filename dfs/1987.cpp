#include<iostream>
#include<algorithm>
using namespace std;

int arr[22][22];
bool visit[28];
int R, C;
int ans = -1e9;
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };

void dfs(int ypos, int xpos, int cnt) {
	int now = arr[ypos][xpos];
	//if (visit[now] == true)
	//	return;

	visit[now] = true;
	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++) {
		int ny = ypos + dy[i];
		int nx = xpos + dx[i];

		if (ny <= 0 || ny > R || nx <= 0 || nx > C)
			continue;
		if (visit[arr[ny][nx]] == false) {
			dfs(ny, nx, cnt+1);
		}
	}
	visit[now] = false;
}

int main() {

	scanf("%d %d", &R, &C);
	char c;
	int a;
	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			scanf(" %c", &c);
			a = c - 'A';
			arr[i][j] = a;
		}
	}
	/*
	for (int i = 1; i < R + 1; i++){
		for (int j = 1; j < C + 1; j++) {
			printf("%d ", arr[i][j]);
		}
	printf("\n");
	}
	*/
	dfs(1, 1, 1);

	printf("%d\n", ans);

	return 0;
}