#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;
queue<ppi> q;
char arr[52][52];
bool visit[52][52][2];		//0 가로, 1 세로
int N;
int e_ypos, e_xpos, e_dir;

const int dy[] = { -1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int ans = 0;
void bfs() {
	ppi now;
	int ny, nx;
	int ypos, xpos, dir, cnt;
	bool check = false;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		check = true;

		if (now.first.first == e_ypos && now.first.second == e_xpos && now.second.first == e_dir) {
			ans = now.second.second;
			while (!q.empty())
				q.pop();
			break;
		}
		ypos = now.first.first;
		xpos = now.first.second;
		dir = now.second.first;
		cnt = now.second.second;

		for (int i = 0; i < 8; i++) {
			ny = now.first.first + dy[i];
			nx = now.first.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
				check = false;
				break;
			}
			if (arr[ny][nx] == '1') {
				check = false;
				break;
			}
		}

		if (check == true) {
			if (dir == 0 && visit[ypos][xpos][dir + 1] == false) {
				q.push({ {ypos,xpos},{dir + 1, cnt + 1} });
				visit[ypos][xpos][dir + 1] = true;
			}
			else if (dir == 1 && visit[ypos][xpos][dir - 1] == false) {
				q.push({ {ypos,xpos},{dir - 1,cnt + 1} });
				visit[ypos][xpos][dir - 1] = true;
			}
		}


		for (int i = 0; i < 8; i+=2) {
			ny = now.first.first + dy[i];
			nx = now.first.second + dx[i];

			if (ny < 0 || ny >= N || ny < 0 || ny >= N)	//범위 나가는거
				continue;
			if (dir == 0) {								//가로 방향일때
				if (nx - 1 < 0 || nx + 1 >= N)				//범위 나감
					continue;
				if (arr[ny][nx - 1] == '1' || arr[ny][nx + 1] == '1' || arr[ny][nx] == '1')
					continue;
				if (arr[ny][nx] == '0' && visit[ny][nx][dir] == false) {
					q.push({ {ny,nx},{dir,cnt + 1} });
					visit[ny][nx][dir] = true;
				}
			}
			else {
				if (ny - 1 < 0 || ny + 1 >= N)
					continue;
				if (arr[ny - 1][nx] == '1' || arr[ny + 1][nx] == '1' || arr[ny][nx] == '1')
					continue;
				if (arr[ny][nx] == '0' && visit[ny][nx][dir] == false) {
					q.push({ {ny,nx},{dir,cnt + 1} });
					visit[ny][nx][dir] = true;
				}
			}

			
		}

	}
}

int main() {
	scanf("%d", &N);
	vector<pii> start;
	vector<pii> fi;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == 'B') {
				start.push_back({ i,j });
				arr[i][j] = '0';
			}
			if (arr[i][j] == 'E') {
				fi.push_back({ i,j });
				arr[i][j] = '0';
			}
		}
	}

	if (start.at(0).first == start.at(1).first) {
		visit[start.at(1).first][start.at(1).second][0] = true;
		q.push({ {start.at(1).first, start.at(1).second}, {0,0} });
	}
	else {
		visit[start.at(1).first][start.at(1).second][0] = true;
		q.push({ {start.at(1).first, start.at(1).second}, {1,0} });
	}

	if (fi.at(0).first == fi.at(1).first) {
		e_ypos = fi.at(1).first;
		e_xpos = fi.at(1).second;
		e_dir = 0;
	}
	else {
		e_ypos = fi.at(1).first;
		e_xpos = fi.at(1).second;
		e_dir = 1;
	}

	bfs();

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}*/

	printf("%d\n", ans);

	return 0;
}