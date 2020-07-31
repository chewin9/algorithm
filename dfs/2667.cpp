#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int arr[27][27];
bool visit[27][27];
int N;
vector<int> v;
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };
typedef pair<int, int> pii;
queue<pii> q;

int dfs(int ypos, int xpos) {
	int cnt = 1;

	if (ypos <= 0 || ypos > N || xpos <= 0 || xpos > N)
		return 0;
	
	visit[ypos][xpos] = true;

	for (int i = 0; i < 4; i++) {
		if (arr[ypos + dy[i]][xpos + dx[i]] == 1 && visit[ypos+dy[i]][xpos+dx[i]] == false)
			cnt += dfs(ypos + dy[i], xpos + dx[i]);
	}
	return cnt;
}

int bfs(int ypos, int xpos) {
	visit[ypos][xpos] = true;
	q.push({ ypos,xpos });
	int cnt = 0;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx, ny;
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > N)
				continue;
			if (arr[ny][nx] == 1 && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}
	return cnt;
}

int main() {
	scanf("%d", &N);
	int ans;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++)
			scanf("%1d", &arr[i][j]);
	}
	memset(visit, false, sizeof(visit));
	/*
	//dfs
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j] == 1 && visit[i][j] == false) {
				ans = dfs(i, j);
				//printf("%2d", ans);
				v.push_back(ans);
			}
		}
	}
	*/
	//bfs
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j] == 1 && visit[i][j] == false) {
				ans = bfs(i, j);
				//printf("%2d", ans);
				v.push_back(ans);
			}
		}
	}


	sort(v.begin(), v.end());

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v.at(i));

	return 0;
}