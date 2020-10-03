#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;
typedef pair<int, int> pii;
vector <pii> worm[5];
int T, N;
int arr[102][102];
int point;
int ans = -1e9;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int change_dir[6][4] = { {0,0,0,0}, {2,0,3,1}, {3,2,0,1}, {1,3,0,2}, {2,3,1,0}, {2,3,0,1} };	//block, dir => block을 dir 방향일때 변화하는거
void go(int ypos, int xpos, int dir) {
	int Sy, Sx;
	Sy = ypos;
	Sx = xpos;

	int ny, nx;
	ny = ypos;
	nx = xpos;
	while (1) {
		ny = ny + dy[dir];
		nx = nx + dx[dir];		//move

		if (ny <= 0 || ny > N || nx <= 0 || nx > N) {
			point++;
			dir = change_dir[5][dir];
			continue;
		}
		if (ny == Sy && nx == Sx)		//start position
			break;
		if (arr[ny][nx] == -1)			//black hole
			break;			

		if (arr[ny][nx] == 0)
			continue;

		switch (arr[ny][nx]) {
		case 1:
			point++;
			dir = change_dir[1][dir];
			break;
		case 2:
			point++;
			dir = change_dir[2][dir];
			break;
		case 3:
			point++;
			dir = change_dir[3][dir];
			break;
		case 4:
			point++;
			dir = change_dir[4][dir];
			break;
		case 5:
			point++;
			dir = change_dir[5][dir];
			break;
		case 6:
			if (worm[0].at(0).first == ny && worm[0].at(0).second == nx) {
				ny = worm[0].at(1).first;
				nx = worm[0].at(1).second;
			}
			else {
				ny = worm[0].at(0).first;
				nx = worm[0].at(0).second;
			}
			break;
		case 7:
			if (worm[1].at(0).first == ny && worm[1].at(0).second == nx) {
				ny = worm[1].at(1).first;
				nx = worm[1].at(1).second;
			}
			else {
				ny = worm[1].at(0).first;
				nx = worm[1].at(0).second;
			}
			break;
		case 8:
			if (worm[2].at(0).first == ny && worm[2].at(0).second == nx) {
				ny = worm[2].at(1).first;
				nx = worm[2].at(1).second;
			}
			else {
				ny = worm[2].at(0).first;
				nx = worm[2].at(0).second;
			}
			break;
		case 9:
			if (worm[3].at(0).first == ny && worm[3].at(0).second == nx) {
				ny = worm[3].at(1).first;
				nx = worm[3].at(1).second;
			}
			else {
				ny = worm[3].at(0).first;
				nx = worm[3].at(0).second;
			}
			break;
		case 10:
			if (worm[4].at(0).first == ny && worm[4].at(0).second == nx) {
				ny = worm[4].at(1).first;
				nx = worm[4].at(1).second;
			}
			else {
				ny = worm[4].at(0).first;
				nx = worm[4].at(0).second;
			}
			break;
		}

	}
	ans = max(ans, point);
}

int main() {

	freopen("sample_input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		for (int i = 0; i < 5; i++) {
			worm[i].clear();
		}
		ans = 0;
		scanf("%d", &N);

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				scanf("%d", &arr[i][j]);
				if (6 <= arr[i][j] && arr[i][j] <= 10) {
					worm[arr[i][j] - 6].push_back({ i, j });
				}
			}
		}

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				for (int k = 0; k < 4; k++) {
					if (arr[i][j] == 0) {
						point = 0;
						go(i, j, k);
					}
				}
			}
		}

		printf("#%d %d\n", t, ans);
	}


	return 0;
}