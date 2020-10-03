#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;
typedef pair<int, int>pii;
queue<pii> q;

int N, H, W, T;
int ori_arr[17][15];
int arr[17][15];
int ball[4];
bool visit[17][15];
int ans = 1e9;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void show() {
	printf("\nShow arr\n");
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}

void get_arr() {
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			arr[i][j] = ori_arr[i][j];
}
bool brick() {
	int ypos = 0;
	int xpos;
	for (int n = 0; n < N; n++) {
		xpos = ypos = 0;

		memset(visit, false, sizeof(visit));

		xpos = ball[n];

		for (int i = 0; i < H; i++) {
			if (arr[i][xpos] != 0) {
				ypos = i;
				q.push({ ypos,xpos });
				//visit[ypos][xpos] = true;
				break;
			}
		}

		while (!q.empty()) {
			pii now = q.front();
			q.pop();
			//printf("{%d %d} => ", now.first, now.second);
			int size = arr[now.first][now.second];
			visit[now.first][now.second] = true;
			arr[now.first][now.second] = 0;

			int ny, nx;
			for (int i = 0; i < 4; i++) {
				for (int s = 1; s < size; s++) {
					ny = now.first + dy[i] * s;
					nx = now.second + dx[i] * s;
					if (ny < 0 || ny >= H || nx < 0 || nx >= W)
						continue;
					if (arr[ny][nx] != 0 && visit[ny][nx] == false) {
						q.push({ ny,nx });
						visit[ny][nx] = true;
					}
				}
			}
		}
		//printf("\n");
		for (int k = 0; k < W; k++) {
			for (int i = H - 2; i >= 0; i--) {
				for (int j = H - 1; j > i; j--) {
					if (arr[j][k] == 0 && arr[i][k] != 0) {
						arr[j][k] = arr[i][k];
						arr[i][k] = 0;
						break;
					}
				}
			}
		}

		/*printf("\n%d==================\n", n);
		show();*/
	}
	return true;
}
void get_ans() {
	int tmp = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (arr[i][j] != 0)
				tmp++;
		}
	}
	ans = min(tmp, ans);
	//printf("ans =%d \n", tmp);

}
void dfs(int aa,int pos) {
	ball[pos] = aa;
	if (pos == N - 1) {
		if (ans == 0)
			return;
		/*for (int i = 0; i < N; i++) {
			printf("%2d", ball[i]);
		}
		printf("\n");*/

		get_arr();
		brick();
		get_ans();


		return;
	}
	for (int i = 0; i < W; i++) {
		dfs(i, pos + 1);
	}
}
int main() {

	freopen("sample_input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		ans = 1e9;
		memset(arr, 0, sizeof(arr));
		memset(ori_arr, 0, sizeof(ori_arr));

		scanf("%d %d %d", &N, &W, &H);

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &ori_arr[i][j]);
			}
		}

		/*ball[0] = 2;
		ball[1] = 2;
		ball[2] = 6;
		get_arr();
		brick();
		get_ans();*/

		for (int i = 0; i < W; i++) {
			dfs(i,0);
		}

		printf("#%d %d\n", t, ans);
	}

}