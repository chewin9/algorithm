#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> pii;
queue<pii> q;

int arr[52][52];
bool visit[52][52];
int N, M, R, C, L;
int ans;
int T;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

bool check_link(int dir, int ypos, int xpos) {
	switch (dir) {
	case 0:
		if ((arr[ypos][xpos] == 1 || arr[ypos][xpos] == 2 || arr[ypos][xpos] == 5 || arr[ypos][xpos] == 6) && visit[ypos][xpos] == false) {
			return true;
		}
		else
			return false;
		break;

	case 1:
		if ((arr[ypos][xpos] == 1 || arr[ypos][xpos] == 3 || arr[ypos][xpos] == 4 || arr[ypos][xpos] == 5) && visit[ypos][xpos] == false)
			return true;
		else
			return false;
		break;

	case 2:
		if ((arr[ypos][xpos] == 1 || arr[ypos][xpos] == 2 || arr[ypos][xpos] == 4 || arr[ypos][xpos] == 7) && visit[ypos][xpos] == false)
			return true;
		else
			return false;
		break;

	case 3:
		if ((arr[ypos][xpos] == 1 || arr[ypos][xpos] == 3 || arr[ypos][xpos] == 6 || arr[ypos][xpos] == 7) && visit[ypos][xpos] == false)
			return true;
		else
			return false;
		break;
	}
}
void solve(int ypos, int xpos) {
	visit[ypos][xpos] = true;
	q.push({ ypos,xpos });

	int cnt = 0;
	int ny, nx;

	while (!q.empty()) {
		cnt++;
		if (cnt == L) {
			while (!q.empty())
				q.pop();
			return;
		}

		int q_size = q.size();

		for (int s = 0; s < q_size; s++) {
			pii now = q.front();
			q.pop();

			switch (arr[now.first][now.second]) {
			case 1:
				for (int i = 0; i < 4; i++) {
					ny = now.first + dy[i];
					nx = now.second + dx[i];

					if (ny <= 0 || ny > N || nx <= 0 || nx > M)
						continue;

					if (check_link(i, ny, nx)) {
						q.push({ ny,nx });
						visit[ny][nx] = true;
					}
				}
				break;

			case 2:
				for (int i = 0; i < 4; i+=2) {
					ny = now.first + dy[i];
					nx = now.second + dx[i];

					if (ny <= 0 || ny > N || nx <= 0 || nx > M)
						continue;

					if (check_link(i, ny, nx)) {
						q.push({ ny,nx });
						visit[ny][nx] = true;
					}
				}
				break;

			case 3:
				for (int i = 1; i < 4; i+=2) {
					ny = now.first + dy[i];
					nx = now.second + dx[i];

					if (ny <= 0 || ny > N || nx <= 0 || nx > M)
						continue;

					if (check_link(i, ny, nx)) {
						q.push({ ny,nx });
						visit[ny][nx] = true;
					}
				}
				break;

			case 4:
				for (int i = 0; i < 4; i+=3) {
					ny = now.first + dy[i];
					nx = now.second + dx[i];

					if (ny <= 0 || ny > N || nx <= 0 || nx > M)
						continue;

					if (check_link(i, ny, nx)) {
						q.push({ ny,nx });
						visit[ny][nx] = true;
					}
				}
				break;

			case 5:
				for (int i = 2; i < 4; i++) {
					ny = now.first + dy[i];
					nx = now.second + dx[i];

					if (ny <= 0 || ny > N || nx <= 0 || nx > M)
						continue;

					if (check_link(i, ny, nx)) {
						q.push({ ny,nx });
						visit[ny][nx] = true;
					}
				}
				break;

			case 6:
				for (int i = 1; i < 3; i++) {
					ny = now.first + dy[i];
					nx = now.second + dx[i];

					if (ny <= 0 || ny > N || nx <= 0 || nx > M)
						continue;

					if (check_link(i, ny, nx)) {
						q.push({ ny,nx });
						visit[ny][nx] = true;
					}
				}
				break;

			case 7:
				for (int i = 0; i < 2; i++) {
					ny = now.first + dy[i];
					nx = now.second + dx[i];

					if (ny <= 0 || ny > N || nx <= 0 || nx > M)
						continue;

					if (check_link(i, ny, nx)) {
						q.push({ ny,nx });
						visit[ny][nx] = true;
					}
				}
				break;
			}
		}
	}
}
void get_ans() {
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			if (visit[i][j] == true)
				ans++;
}
int main() {

	freopen("sample_input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));
		ans = 0;
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);

		for (int i = 1; i < N + 1; i++)
			for (int j = 1; j < M + 1; j++)
				scanf("%d ", &arr[i][j]);

		solve(R + 1, C + 1);
		get_ans();
		printf("#%d %d\n", t, ans);
	}



	return 0;
}