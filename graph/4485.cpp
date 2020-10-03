#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int, int> pii;
queue<pii> q;
int arr[127][127];
int visit[127][127];
int N;
int ans=0;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
void bfs(int ypos, int xpos) {
	visit[ypos][xpos] = arr[ypos][xpos];
	q.push({ ypos,xpos });

	int ny, nx;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			if (visit[ny][nx] > visit[now.first][now.second] + arr[ny][nx]) {
				visit[ny][nx] = visit[now.first][now.second] + arr[ny][nx];
				q.push({ ny,nx });
			}
		}
	}


}
int main() {

	do {
		ans++;
		memset(arr, 0, sizeof(arr));

		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
				visit[i][j] = 1e9;
			}
		}

		bfs(0, 0);
		if(N != 0)
			printf("Problem %d: %d\n",ans, visit[N - 1][N - 1]);

	} while (N != 0);



	return 0;
}