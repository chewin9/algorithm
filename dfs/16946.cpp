#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;

typedef pair<int, int> pii;
int N, M;
int arr[1002][1002];
int ans[1002][1002];
bool visit[1002][1002];
bool sum[500002];
queue<pii> q;
vector<int> v;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

int dfs(int ypos, int xpos, int pos) {
	visit[ypos][xpos] = true;
	ans[ypos][xpos] = pos;
	int count = 1;

	int ny, nx;
	
	for (int i = 0; i < 4; i++) {
		ny = ypos + dy[i];
		nx = xpos + dx[i];

		if (ny <= 0 || ny > N || nx <= 0 || nx > M)
			continue;
		if (arr[ny][nx] == 0 && visit[ny][nx] == false) {
			count += dfs(ny, nx, pos);
		}
	}
	return count%10;
}

int bfs(int ypos, int xpos, int pos) {
	visit[ypos][xpos] = true;
	//ans[ypos][xpos] = pos;
	q.push({ ypos,xpos });
	int count = 0;
	int ny, nx;
	while (!q.empty()){
		count++;
		pii now = q.front();
		q.pop();
		ans[now.first][now.second] = pos;
		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];
			if (ny <= 0 || ny > N || nx <= 0 || nx > M)
				continue;
			if (arr[ny][nx] == 0 && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}
	return count%10;
}

void show() {
	printf("Show arr\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}

	printf("\nShow ans\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			printf("%3d", ans[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

int find(int ypos, int xpos) {
	memset(sum, false, sizeof(sum));
	int count = 1;
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = ypos + dy[i];
		nx = xpos + dx[i];
		if (ny <= 0 || ny > N || nx <= 0 || nx > M)
			continue;
		if (arr[ny][nx] == 0 && sum[ans[ny][nx]] == false) {
			count += v.at(ans[ny][nx])%10;
			sum[ans[ny][nx]] = true;
		}
	}
	return count;
}
int main() {

	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	int cnt = 1;
	v.push_back(-1);
	int aa;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (arr[i][j] == 0 && visit[i][j] == false) {
				aa = bfs(i, j, cnt++);
				v.push_back(aa);
			}
			else if(arr[i][j] == 1)
				ans[i][j] = -1;
		}
	}

	//show();

	memset(visit, false, sizeof(visit));
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (ans[i][j] == -1 && visit[i][j] ==false) {
				visit[i][j] = true;
				ans[i][j] = find(i, j);
			}
		}
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (visit[i][j] == false)
				printf("0");
			else
				printf("%d", ans[i][j]%10);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}