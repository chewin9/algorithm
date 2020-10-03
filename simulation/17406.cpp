#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int N, M, K;
int ori_arr[52][52];
int arr[52][52];
int trans[8][3];
int order[7];
bool visit[7];
int ans = 1e9;

void show() {
	printf("======================\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}
void arr_trans(int pos) {
	int r, s, c;
	r = trans[pos][0];
	c = trans[pos][1];
	s = trans[pos][2];

	int ypos1, xpos1, ypos2, xpos2;

	ypos1 = r - s;
	xpos1 = c - s;
	ypos2 = r + s;
	xpos2 = c + s;

	while (1) {

		int tmp = arr[ypos1][xpos2];

		for (int i = xpos2; i > xpos1; i--)
			arr[ypos1][i] = arr[ypos1][i - 1];
		for (int i = ypos1; i < ypos2; i++)
			arr[i][xpos1] = arr[i + 1][xpos1];
		for (int i = xpos1; i < xpos2; i++)
			arr[ypos2][i] = arr[ypos2][i + 1];
		for (int i = ypos2; i > ypos1; i--)
			arr[i][xpos2] = arr[i - 1][xpos2];
		arr[ypos1 + 1][xpos2] = tmp;

		ypos1 += 1;
		xpos1 += 1;
		ypos2 -= 1;
		xpos2 -= 1;

		if (ypos1 >= ypos2 || xpos1 >= xpos2)
			break;
	}
	//show();
}
void get_ans() {
	int tmp = 0;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			tmp += arr[i][j];
		}
		ans = min(tmp, ans);
		tmp = 0;
	}
}
void go_game() {
	for (int i = 0; i < K; i++) {
		arr_trans(order[i]);
	}
	get_ans();
}
void get_arr() {
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			arr[i][j] = ori_arr[i][j];
}
void dfs(int pos, int cnt) {
	order[cnt] = pos;
	visit[pos] = true;

	if (cnt == K - 1) {
		/*for (int i = 0; i < K; i++)
			printf("%2d", order[i]);
		printf("\n");*/
		get_arr();
		//show();
		go_game();

		visit[pos] = false;
		return;
	}
	for (int i = 0; i < K; i++) {
		if (visit[i] == false) {
			dfs(i, cnt + 1);
			visit[i] = false;
		}
	}
	visit[pos] = false;
}

int main() {

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%d", &ori_arr[i][j]);
		}
	}
	
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d", &trans[i][0], &trans[i][1], &trans[i][2]);
	}

	for (int i = 0; i < K; i++) {
		dfs(i, 0);
	}

	printf("%d\n", ans);
	return 0;
}