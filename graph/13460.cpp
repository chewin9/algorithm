#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>

using namespace std;
int N, M;
char arr[12][12];
bool visit[12][12];
int ans;
int Rx, Ry, Bx, By, Ox, Oy;
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };
typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;
queue<ppi> q;
int RNX, RNY, BNX, BNY;
bool rgoal = false, bgoal = false;
bool aa;

void show() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			printf("%2c", arr[i][j]);
		}
		printf("\n");
	}
	printf("==========\n");
}

void grav(int rypos, int rxpos, int bypos, int bxpos, int dir) {
	bool red, blue;
	while (1) {
		red = false;
		blue = false;

		visit[rypos][rxpos] = true;
		if (rypos == Oy && rxpos == Ox) {
			rgoal = true;
			arr[rypos][rxpos] = '.';
			red = true;
		}
		if (bypos == Oy && bxpos == Ox) {
			bgoal = true;
			arr[bypos][bxpos] = '.';
			blue = true;
		}

		if (rgoal == false) {
			if (arr[rypos + dy[dir]][rxpos + dx[dir]] == '.') {
				arr[rypos][rxpos] = '.';
				arr[rypos + dy[dir]][rxpos + dx[dir]] = 'R';
				rypos = rypos + dy[dir];
				rxpos = rxpos + dx[dir];
			}
			else {
				RNY = rypos;
				RNX = rxpos;
				red = true;
			}
		}

		if (bgoal == false) {
			if (arr[bypos + dy[dir]][bxpos + dx[dir]] == '.') {
				arr[bypos][bxpos] = '.';
				arr[bypos + dy[dir]][bxpos + dx[dir]] = 'B';
				bypos = bypos + dy[dir];
				bxpos = bxpos + dx[dir];
			}
			else {
				BNY = bypos;
				BNX = bxpos;
				blue = true;
			}
		}
		if (red == true && blue == true) {
			//show();
			arr[rypos][rxpos] = '.';
			arr[bypos][bxpos] = '.';
			break;
		}
		//show();
	}
}

int check() {

	if (rgoal == true && bgoal == false) {
		return 1;
	}
	else if (rgoal == true && bgoal == true) {
		return 2;
	}
	else if (rgoal == false && bgoal == true) {
		return 3;
	}
	else
		return 4;

}
void bfs() {
	q.push({ { Ry,Rx }, { By,Bx } });
	visit[Ry][Rx] = true;
	visit[By][Bx] = true;
	int rny, rnx, bny, bnx;
	int tcase;

	while (!q.empty()) {
		int size = q.size();
		ans++;
		if (ans > 10) {
			printf("-1\n");
			aa = true;
			break;
		}
		for (int s = 0; s < size; s++) {
			ppi now = q.front();
			q.pop();
			//printf("R:{%d %d}, B: {%d %d}\n", now.first.first, now.first.second, now.second.first, now.second.second);
			//arr[now.first.first][now.first.second] = 'R';
			//arr[now.second.first][now.second.second] = 'B';
			//show();
			for (int i = 0; i < 4; i++) {
				arr[now.first.first][now.first.second] = 'R';
				arr[now.second.first][now.second.second] = 'B';
				//show();
				rny = now.first.first + dy[i];
				rnx = now.first.second + dx[i];
				bny = now.second.first + dy[i];
				bnx = now.second.second + dx[i];

				//if (rny <= 1 || rny >= N || rnx <= 1 || rnx >= M)
				//	continue;
				if ((arr[rny][rnx] == '.' || arr[bny][bnx] == '.')) {// && visit[rny][rnx] == false) {
					//printf("DIR %d\n", i);
					//show();
					rgoal = false;
					bgoal = false;
					grav(now.first.first, now.first.second, now.second.first, now.second.second, i);
					//printf("===============\n");
					tcase = check();
					
					if (tcase == 1) {
						printf("%d\n", ans);
						aa = true;
						return;
					}
					//else if (tcase == 2 && q.empty()) {
					//	printf("-1\n");
					//	return;
					//}
					else if (tcase == 4) {
						q.push({ {RNY,RNX},{BNY,BNX} });
					}
					//q.push({ {RNY, RNX}, {BNY, BNX} });
				}
			}
			arr[now.first.first][now.first.second] = '.';
			arr[now.second.first][now.second.second] = '.';
		}
	}
	if (aa == false)
		printf("-1\n");
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == 'R') {
				Ry = i;
				Rx = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				By = i;
				Bx = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'O') {
				Oy = i;
				Ox = j;
				arr[i][j] = '.';
			}
		}
	}

	//show();
	bfs();

	return 0;
}