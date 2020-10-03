#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

typedef pair<int, int>pii;
int cost_min = 1e9;
int cost_max = -1e9;
int ans = 1e9;
int N;
int arr[22][22];
int visit[22][22];
queue<pii> q;

void show() {
	printf("\n\n Show visit\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%3d", visit[i][j]);
		}
		printf("\n");
	}
}
void find_ans(){
	int num[6];
	for (int i = 0; i < 6; i++)
		num[i] = 0;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			switch (visit[i][j]) {
			case 1:
				num[1] += arr[i][j];
				break;
			case 2:
				num[2] += arr[i][j];
				break;
			case 3:
				num[3] += arr[i][j];
				break;
			case 4:
				num[4] += arr[i][j];
				break;
			case 5:
				num[5] += arr[i][j];
				break;
			}
		}
	}

	for (int i = 1; i < 6; i++) {
		cost_min = min(cost_min, num[i]);
		cost_max = max(cost_max, num[i]);
	}
	ans = min(ans, (cost_max - cost_min));

	cost_max = -1e9;
	cost_min = 1e9;

}

void area(int ypos, int xpos, int d1, int d2) {

	int ny1, ny2, ny3;
	int nx1, nx2, nx3;
	ny1 = ypos - d1; nx1 = xpos + d1;
	ny2 = ypos - d1 + d2; nx2 = xpos + d1 + d2;
	ny3 = ypos + d2; nx3 = xpos + d2;
	
	int tmp_y, tmp_x;
	for (int i = 0; i < nx1 - xpos + 1; i++) {
		tmp_y = ypos - i;
		tmp_x = xpos + i;
		visit[tmp_y][tmp_x] = 5;
		if (tmp_y != ypos && tmp_x != xpos)
			q.push({ tmp_y,tmp_x });
	}

	for (int i = 0; i < nx2 - nx1 + 1; i++) {
		tmp_y = ny1 + i;
		tmp_x = nx1 + i;
		visit[tmp_y][tmp_x] = 5;
		if (tmp_y != ny2 && tmp_x != nx2)
			q.push({ tmp_y, tmp_x });
	}

	for (int i = 0; i < nx3 - xpos + 1; i++) {
		tmp_y = ypos + i;
		tmp_x = xpos + i;
		visit[tmp_y][tmp_x] = 5;
	}
	for (int i = 0; i < nx2 - nx3 + 1; i++) {
		tmp_y = ny3 - i;
		tmp_x = nx3 + i;
		visit[tmp_y][tmp_x] = 5;
	}

	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		if (visit[now.first + 1][now.second] != 5) {
			visit[now.first + 1][now.second] = 5;
			q.push({ now.first + 1, now.second });
		}
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (visit[i][j] == 0) {
				if (1 <= i && i < ypos && 1 <= j && j <= nx1)
					visit[i][j] = 1;
				else if (1 <= i && i <= ny2 && nx1 <= j)
					visit[i][j] = 2;
				else if (ypos <= i && 1 <= j && j < nx3)
					visit[i][j] = 3;
				else
					visit[i][j] = 4;

			}
		}
	}

	find_ans();
}

void fun_A(int ypos, int xpos) {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (ypos - i <1 || ypos + j >N || xpos + i + j > N)
				continue;
			else {
				memset(visit, 0, sizeof(visit));
				area(ypos, xpos, i, j);
			}
		}
	}
}

int main() {

	scanf("%d", &N);
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++)
			scanf("%d", &arr[i][j]);
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			fun_A(i, j);
		}
	}

	printf("%d\n", ans);

	return 0;
}