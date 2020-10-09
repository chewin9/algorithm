#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

typedef pair<int, int> pii;
typedef struct Shark {
	int ypos;
	int xpos;
	int dir;
	int dir_list[5][5];
	bool live;
}Shark;


Shark s[402];
pii arr[22][22];

int N, M, K;
const int dy[] = { 0,-1,1,0,0 };		//위 아래 왼쪽 오른쪽
const int dx[] = { 0,0,0,-1,1 };
int ans = 0;
void spread_smell() {
	for (int i = 1; i < M + 1; i++) {
		if (s[i].live == true) {
			int s_ypos = s[i].ypos;
			int s_xpos = s[i].xpos;
			arr[s_ypos][s_xpos] = { i,K };
		}
	}
}

void check_shark() {
	for (int i = 1; i < M + 1; i++) {
		if (s[i].live == true) {
			for (int j = i + 1; j < M + 1; j++) {
				if (s[j].live == true) {
					int f_ypos, f_xpos;
					int s_ypos, s_xpos;

					f_ypos = s[i].ypos;
					f_xpos = s[i].xpos;
					s_ypos = s[j].ypos;
					s_xpos = s[j].xpos;

					if (f_ypos == s_ypos && f_xpos == s_xpos) {
						s[j].live = false;
					}
				}
			}
		}
	}
}

bool check_ans() {
	for (int i = 2; i < M + 1; i++) {
		if (s[i].live == true)
			return false;
	}
	return true;
}

void move_shark() {
	for (int i = 1; i < M + 1; i++) {
		if (s[i].live == true) {
			int ypos, xpos, n_dir;
			int ny, nx;
			bool check = false;

			ypos = s[i].ypos;
			xpos = s[i].xpos;
			n_dir = s[i].dir;
			for (int j = 1; j < 5; j++) {							//빈칸ㅇ ㅣ있는지 찾아보자
				ny = ypos + dy[s[i].dir_list[n_dir][j]];
				nx = xpos + dx[s[i].dir_list[n_dir][j]];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;
				if (arr[ny][nx].first == 0) {
					s[i].ypos = ny;
					s[i].xpos = nx;
					s[i].dir = s[i].dir_list[n_dir][j];
					check = true;
					break;
				}
			}

			if (check == false) {									//없으면 내 냄시로
				for (int j = 1; j < 5; j++) {
					ny = ypos + dy[s[i].dir_list[n_dir][j]];
					nx = xpos + dx[s[i].dir_list[n_dir][j]];

					if (ny < 0 || ny >= N || nx < 0 || nx >= N)
						continue;
					if (arr[ny][nx].first == i) {
						s[i].ypos = ny;
						s[i].xpos = nx;
						s[i].dir = s[i].dir_list[n_dir][j];
						break;
					}
				}
			}

		}
	}
}

void decre_smell() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j].first != 0) {
				arr[i][j].second = arr[i][j].second - 1;		//감소 시키고
			}
			if (arr[i][j].first != 0 && arr[i][j].second == 0) {	//냄새가 0가 되면 없애준다
				arr[i][j] = { 0,0 };
			}
		}
	}
}

void show() {
	printf("\nShark state\n");

	for (int i = 1; i < M + 1; i++) {
		printf("Shark %d = {%d %d}, dir = %d, live = %d\n", i, s[i].ypos, s[i].xpos, s[i].dir, s[i].live);
	}

	printf("\nArr state\n");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("{%d %d}  ", arr[i][j].first, arr[i][j].second);
		}
		printf("\n");
	}
	printf("\n");
}
int main() {
	int a;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a);
			if (a != 0) {
				s[a].ypos = i;
				s[a].xpos = j;
				s[a].live = true;
			}
		}
	}
	for (int i = 1; i < M + 1; i++) {
		scanf("%d", &a);
		s[i].dir = a;
	}

	int b, c, d;
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < 5; j++) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			s[i].dir_list[j][1] = a;
			s[i].dir_list[j][2] = b;
			s[i].dir_list[j][3] = c;
			s[i].dir_list[j][4] = d;
		}
	}

	spread_smell();

	while (1) {
		//printf("TIME %d=================", ans);
		//show();
		if (check_ans())
			break;
		ans++;
		if (ans > 1000)
			break;

		move_shark();
		//show();
		check_shark();
		decre_smell();
		spread_smell();
	}
	if (ans == 1001)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}