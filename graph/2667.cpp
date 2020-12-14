#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pii;
queue<pii> q;
int N;
int arr[27][27];
bool visit[27][27];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
vector<int> ans;
void bfs(int ypos, int xpos) {
	int cnt = 0;
	visit[ypos][xpos] = true;
	q.push({ ypos,xpos });
	
	int ny, nx;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;
			if (arr[ny][nx] == 1 && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}
	ans.push_back(cnt);
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && visit[i][j] == false) {
				bfs(i, j);
			}
		}
	}
	sort(ans.begin(), ans.end());

	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}



	return 0;
}