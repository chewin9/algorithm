#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int M, N, K;
int arr[102][102];
bool visit[102][102];
vector<int> v;
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };
typedef pair<int, int> pii;
queue <pii> q;
int bfs(int ypos, int xpos) {
	int cnt = 0;
	q.push({ ypos,xpos });
	visit[ypos][xpos] = true;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || ny >= M || nx < 0 || nx >= N)
				continue;
			if (arr[ny][nx] != 1 && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}

	return cnt;
}

int dfs(int ypos, int xpos) {
	int cnt = 1;
	visit[ypos][xpos] = true;
	
	for (int i = 0; i < 4; i++) {
		int ny = ypos + dy[i];
		int nx = xpos + dx[i];

		if (ny < 0 || ny >= M || nx<0 || nx>=N)
			continue;
		if (arr[ny][nx] != 1 && visit[ny][nx]==false)
			cnt += dfs(ny, nx);
	}

	return cnt;

}

int main() {
	int cnt = 0;
	scanf("%d %d %d", &M, &N, &K);

	for (int k = 0; k < K; k++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				arr[i][j] = 1;
			}
		}
	}
	
	/*
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
	*/
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0 && visit[i][j] == false) {
				//cnt = dfs(i, j);
				cnt = bfs(i, j);
				//printf("%d %d %d \n", i, j,cnt);
				v.push_back(cnt);
			}
		}
	}
	
	sort(v.begin(), v.end());

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v.at(i));

	return 0;
}