#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;

typedef pair<int, int > pii;

int arr[22][22];
int N;
int ans = 1e9;
int visit[22][22];
void show() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%2d", visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void get_ans() {
	int cost[6] = { 0,0,0,0,0,0 };
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cost[visit[i][j]] += arr[i][j];
		}
	}
	int maxi = -1e9;
	int mini = 1e9;

	for (int i = 1; i < 6; i++) {
		maxi = max(maxi, cost[i]);
		mini = min(mini, cost[i]);
	}
	ans = min(ans, maxi - mini);
}
void get_area(int ypos, int xpos, int d1, int d2) {
	// 1½Ã ¹æÇâ
	queue<pii> q;
	int y1, y2, y3, x1, x2, x3;
	y1 = ypos - d1;
	x1 = xpos + d1;
	y2 = ypos - d1 + d2;
	x2 = xpos + d1 + d2;
	y3 = ypos + d2;
	x3 = xpos + d2;


	for (int i = 0; i <= d1; i++) {
		visit[ypos - i][xpos + i] = 5;
		if (i != 0)
			q.push({ ypos - i,xpos + i });
	}

	for (int i = 0; i <= d2; i++) {
		visit[y1 + i][x1 + i] = 5;
		if (i != d2)
			q.push({ y1 + i, x1 + i });
	}

	for (int i = 0; i <= d2; i++) {
		visit[ypos + i][xpos + i] = 5;
	}
	for (int i = 0; i <= d1; i++) {
		visit[y3 - i][x3 + i] = 5;
	}
	//show();
	int ny, nx;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		ny = now.first;
		nx = now.second;
		while (1) {
			ny = ny + 1;

			if (visit[ny][nx] == 5)
				break;
			else
				visit[ny][nx] = 5;
		}
	}

	for (int i = 1; i < ypos; i++) {
		for (int j = 1; j <= x1; j++) {
			if (visit[i][j] == 0)
				visit[i][j] = 1;
		}
	}
	for (int i = 1; i <= y2; i++) {
		for (int j = x1 + 1; j < N + 1; j++) {
			if(visit[i][j] ==0)
				visit[i][j] = 2;
		}
	}
	for (int i = ypos; i < N + 1; i++) {
		for (int j = 1; j < x3; j++) {
			if (visit[i][j] == 0)
				visit[i][j] = 3;
		}
	}
	for (int i = y2; i < N + 1; i++) {
		for (int j = x3; j < N + 1; j++) {
			if (visit[i][j] == 0)
				visit[i][j] = 4;
		}
	}
	get_ans();
}

void fun_A(int ypos, int xpos) {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (ypos - i<1 || ypos + j> N || xpos + i + j > N)
				continue;
			else {
				//printf("%d %d %d %d\n", ypos, xpos, i, j);
				memset(visit, 0, sizeof(visit));
				get_area(ypos, xpos, i, j);
			}
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			fun_A(i, j);
		}
	}
	/*get_area(2, 1, 1, 3);
	show();*/

	printf("%d\n", ans);
	return 0;
}