#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int arr[6][6];
bool visit[6][6];

int K;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int ans = 0;

void dfs(int ypos, int xpos, int cnt, int goal) {
	if (ypos == 5 && xpos == 5) {
		if (cnt == goal)
			ans++;
		return;
	}
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = ypos + dy[i];
		nx = xpos + dx[i];
		if (ny <= 0 || ny > 5 || nx <= 0 || nx > 5)
			continue;
		if (arr[ny][nx] == 1 && visit[ny][nx] == false) {
			visit[ny][nx] = true;
			dfs(ny, nx, cnt + 1, goal);
			visit[ny][nx] = false;
		}
	}
}
int main() {
	//memset(arr, 1, sizeof(arr));
	for (int i = 1; i < 6; i++)
		for (int j = 1; j < 6; j++)
			arr[i][j] = 1;
	scanf("%d", &K);

	int a, b;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = 0;
	}

	//show();
	visit[1][1] = true;
	dfs(1, 1,1, 25-K);
	//show();

	printf("%d\n", ans);
	return 0;
}