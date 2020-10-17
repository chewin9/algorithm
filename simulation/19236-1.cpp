#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

typedef struct Fish {
	int ypos;
	int xpos;
	int dir;
	bool live;
	int num;
}Fish;

int arr[4][4];
Fish f[17];
int ans = -1e9;
Fish S;

const int dy[] = { 0,-1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0, 0,-1,-1,-1,0,1,1,1 };


void fish_move() {
	int ny, nx;
	int n_dir;
	for (int i = 1; i < 17; i++) {
		if (f[i].live == true) {
			for (int j = 0; j < 8; j++) {
				n_dir = (f[i].dir + j) % 8;
				if (n_dir == 0)
					n_dir = 8;

				ny = f[i].ypos + dy[n_dir];
				nx = f[i].xpos + dx[n_dir];

				if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
					continue;
				if (ny == S.ypos && nx == S.xpos)
					continue;
				else {
					arr[f[i].ypos][f[i].xpos] = arr[ny][nx];
					f[arr[ny][nx]].ypos = f[i].ypos;
					f[arr[ny][nx]].xpos = f[i].xpos;
					f[i].ypos = ny;
					f[i].xpos = nx;
					f[i].dir = n_dir;
					arr[ny][nx] = i;
					break;
				}/*
				if (ny != S.ypos && nx != S.xpos) {
					f[i].ypos = ny;
					f[i].xpos = nx;
					f[i].dir = n_dir;
					arr[ny][nx] = i;
				}*/
			}
		}

		/*for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				printf("%3d", arr[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
	}
}

void show(int ypos, int xpos) {
	printf("\nEAT {%d %d}\n", ypos,xpos);
	printf("Shark {%d %d}, dir %d, num %d\n", S.ypos, S.xpos, S.dir, S.num);

	printf("Show arr\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\nFish state\n");
	for (int i = 1; i < 17; i++) {
		printf("Fish %d {%d %d}, dir = %d, live = %d\n",i, f[i].ypos, f[i].xpos, f[i].dir, f[i].live);
	}
}

void eat(int ypos, int xpos) {
	S.ypos = ypos;
	S.xpos = xpos;
	S.dir = f[arr[ypos][xpos]].dir;
	S.num = S.num + f[arr[ypos][xpos]].num;
	ans = max(S.num, ans);
	f[arr[ypos][xpos]].live = false;
}
void dfs(int ypos, int xpos) {
	//printf("Before eat & move\n");
	//show(ypos, xpos);

	Fish ori_S;
	Fish ori_f[17];
	int ori_arr[4][4];

	S.ypos = ypos;
	S.xpos = xpos;
	S.dir = f[arr[ypos][xpos]].dir;
	S.num = S.num + f[arr[ypos][xpos]].num;
	ans = max(S.num, ans);
	f[arr[ypos][xpos]].live = false;

	fish_move();
	//printf("After eat & move\n");
	//show(ypos, xpos);

	//printf("\n\n==============================\n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ori_arr[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i < 17; i++)
		ori_f[i] = f[i];
	ori_S = S;

	int ny, nx;

	for (int i = 1; i < 4; i++) {
		ny = S.ypos + dy[S.dir] *i;
		nx = S.xpos + dx[S.dir] * i;

		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
			continue;
		if (f[arr[ny][nx]].live == false)
			continue;

		if (f[arr[ny][nx]].live == true) {
			//eat(ny, nx);
			dfs(ny, nx);

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					arr[i][j] = ori_arr[i][j];
				}
			}
			for (int i = 1; i < 17; i++) {
				f[i] = ori_f[i];
			}
			S = ori_S;
			//printf("BACK!!!\n");
			//show(ypos, xpos);
		}

	}

}

int main() {

	int num, dir;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d %d", &num, &dir);
			arr[i][j] = num;
			f[num].ypos = i;
			f[num].xpos = j;
			f[num].dir = dir;
			f[num].num = num;
			f[num].live = true;
		}
	}

	S.ypos = 0;
	S.xpos = 0;
	S.dir = 0;
	S.num = 0;

	//eat(0, 0);
	dfs(0, 0);

	printf("%d\n", ans);
	return 0;
}