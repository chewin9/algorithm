#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;

typedef pair<int, int> pii;
typedef struct Shark {
	int ypos;
	int xpos;
	int dir;
	int pri[5][5];
}Shark;
int N, M, K;
int arr[22][22];
pii smell[22][22];		//번호, 시간
Shark s[402];
bool sh[402];
//vector<int> map[22][22];
const int dy[] = { 0, -1, 1, 0, 0 };
const int dx[] = { 0, 0, 0, -1, 1 };
int ans = 0;

void spread_smell() {
	for (int i = 1; i < M + 1; i++) {
		if (sh[i] == true) {
			smell[s[i].ypos][s[i].xpos].first = i;
			smell[s[i].ypos][s[i].xpos].second = K;
		}
	}
}

void move() {
	for (int i = 1; i < M + 1; i++) {
		if (sh[i] == true) {
			int ypos, xpos, dir;
			
			ypos = s[i].ypos;
			xpos = s[i].xpos;
			dir = s[i].dir;
			
			int ny, nx;
			bool check = true;
			for (int j = 1; j < 5; j++) {				//일단 찾자
				ny = ypos + dy[s[i].pri[dir][j]];
				nx = xpos + dx[s[i].pri[dir][j]];
				if (ny <= 0 || ny > N || nx <= 0 || nx > N)
					continue;
				if (smell[ny][nx].first != 0 || smell[ny][nx].second != 0)
					continue;
				if (smell[ny][nx].first == 0 && smell[ny][nx].second == 0) {		//빈칸 찾음
					s[i].ypos = ny;
					s[i].xpos = nx;
					s[i].dir = s[i].pri[dir][j];
					check = false;
					break;
				}
			}

			if (check == true) {									//빈칸 못찾아서 예전에 내 냄시로 간다.
				for (int j = 1; j < 5; j++) {
					ny = ypos + dy[s[i].pri[dir][j]];
					nx = xpos + dx[s[i].pri[dir][j]];
					if (ny <= 0 || ny > N || nx <= 0 || nx > N)
						continue;
					if (smell[ny][nx].first == i) {
						s[i].ypos = ny;
						s[i].xpos = nx;
						s[i].dir = s[i].pri[dir][j];
						break;
					}
				}
			}

		}
	}
}
void show() {
	printf("\nShow Shark\n");
	for (int i = 1; i < M + 1; i++) {
		if(sh[i] == true)
			printf("Shark%d = {%d %d}, %d\n", i, s[i].ypos, s[i].xpos, s[i].dir);
	}

	printf("\nShow Smell\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("Smell{%d %d} = {S=%d, K= %d}\n", i, j, smell[i][j].first, smell[i][j].second);
		}
	}
	printf("\n");
}
void del() {
	for (int i = 1; i < M; i++) {
		if (sh[i] == true) {
			int ypos, xpos;
			ypos = s[i].ypos;
			xpos = s[i].xpos;
			for (int j = i + 1; j < M + 1; j++) {
				if (sh[j] == true) {
					int ny, nx;
					ny = s[j].ypos;
					nx = s[j].xpos;

					if (ypos == ny && xpos == nx) {
						sh[j] = false;
					}
				}
			}
		}
	}
}
void del_smell() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (smell[i][j].second != 0) {
				smell[i][j].second -= 1;
				if (smell[i][j].second == 0)
					smell[i][j].first = 0;
			}
		}
	}
}
bool find_ans() {
	for (int i = 2; i < M + 1; i++) {
		if (sh[i] == true)
			return false;
	}
	return true;
}
int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%d ", &arr[i][j]);
			if (arr[i][j] != 0) {
				s[arr[i][j]].ypos = i;
				s[arr[i][j]].xpos = j;
				//map[i][j].push_back(arr[i][j]);
			}
		}
	}
	int a;
	for (int i = 1; i < M + 1; i++) {
		scanf("%d", &a);
		s[i].dir = a;
	}
	int  b, c, d;
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < 5; j++) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			s[i].pri[j][1] = a;
			s[i].pri[j][2] = b;
			s[i].pri[j][3] = c;
			s[i].pri[j][4] = d;
		}
	}
	memset(sh, true, sizeof(sh));

	while (1) {
		
		ans++;
		if (ans > 1000) {
			ans = -1;
			break;
		}
		//printf("%d===================================\n", ans);
		spread_smell();
		//printf("spread_smell\n");
		//show();

		move();
		//printf("move\n");
		//show();

		del();
		//printf("del\n");
		//show();

		if (find_ans()) {
			break;
		}

		del_smell();
		//printf("del_smell\n");
		//show();
	}
	if (ans == -1)
		printf("-1\n");
	else
		printf("%d", ans);
	return 0;

}