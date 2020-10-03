#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;
typedef struct Misang {
	int ypos;
	int xpos;
	int size;
	int dir;
	bool live;
}Misang;

int T, N, M, K;
int arr[102][102];
int ans = 0;
Misang mi[1002];
const int dy[] = { 0,-1,1,0,0 };
const int dx[] = { 0, 0,0,-1,1 };

void move() {
	for (int i = 1; i < K + 1; i++) {
		if (mi[i].live == true) {			//»ì¾ÆÀÕÀ»¶§
			int ny, nx, ndir;
			
			arr[mi[i].ypos][mi[i].xpos] -= 1;

			ny = mi[i].ypos + dy[mi[i].dir];
			nx = mi[i].xpos + dx[mi[i].dir];

			mi[i].ypos = ny;
			mi[i].xpos = nx;

			arr[ny][nx] += 1;
		}
	}
}

void change_dir(int pos) {
	int dir = mi[pos].dir;

	if (dir == 1)
		mi[pos].dir = 2;
	else if (dir == 2)
		mi[pos].dir = 1;
	else if (dir == 3)
		mi[pos].dir = 4;
	else
		mi[pos].dir = 3;
}

void check_side() {
	for (int i = 1; i < K + 1; i++) {
		if (mi[i].live == true) {
			if (mi[i].ypos == 0 || mi[i].ypos == N - 1 || mi[i].xpos == 0 || mi[i].xpos == N - 1) {
				mi[i].size = mi[i].size / 2;
				change_dir(i);
				if (mi[i].size == 0) {
					mi[i].live = false;
				}
			}
		}
	}
}

void find_sum(int ypos, int xpos) {
	vector<int> num;
	int tmp = 0;
	int aa = 0;
	for (int i = 1; i < K + 1; i++) {
		if (mi[i].live == true) {
			if (mi[i].ypos == ypos && mi[i].xpos == xpos) {
				if (tmp < mi[i].size) {
					aa = i;
					tmp = max(tmp, mi[i].size);
				}
				num.push_back(i);
			}
		}
	}

	for (int i = 0; i < num.size(); i++) {
		if (num.at(i) != aa) {
			mi[aa].size += mi[num.at(i)].size;
			mi[num.at(i)].live = false;
		}
	}
}

void sum_mi() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j] > 1) {
				find_sum(i, j);
			}
		}
	}

}
void find_ans() {
	for (int i = 1; i < K + 1; i++) {
		if (mi[i].live == true) {
			ans += mi[i].size;
		}
	}
}
int main() {

	freopen("sample_input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		memset(arr, 0, sizeof(arr));
		ans = 0;
		memset(mi, 0, sizeof(mi));

		scanf("%d %d %d", &N, &M, &K);

		int a, b, c, d;
		for (int i = 1; i < K + 1; i++) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			mi[i].ypos = a;
			mi[i].xpos = b;
			mi[i].size = c;
			mi[i].dir = d;
			mi[i].live = true;
			arr[a][b] += 1;
		}
		while (M--) {
			move();
			check_side();
			sum_mi();
		}
		find_ans();

		printf("#%d %d\n", t, ans);
	}

	return 0;
}