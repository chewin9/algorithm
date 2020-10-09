#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

typedef pair<int, int> pii;
queue<pii> q;
vector<pii> v;

int N, T;
char arr[302][302];
int cnt[302][302];
int ans_arr[302][302];
int ans = 0;

const int dy[] = { -1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,-1,-1,-1,0,1,1,1 };

void show() {
	printf("Show Arr\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%3c", arr[i][j]);
		}
		printf("\n");
	}

	printf("\nShow visit\n");

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%3d", cnt[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void get_arr() {
	memset(cnt, -1, sizeof(cnt));
	memset(ans_arr, -1, sizeof(ans_arr));
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j] == '*') {
				cnt[i][j] = 10;
				ans_arr[i][j] = 10;
			}
		}
	}

	int ny, nx;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (cnt[i][j] == -1) {
				int tmp = 0;
				for (int k = 0; k < 8; k++) {
					ny = i + dy[k];
					nx = j + dx[k];
					if (ny > N || ny <= 0 || nx > N || nx <= 0)
						continue;
					if (arr[ny][nx] == '*')
						tmp++;
				}
				cnt[i][j] = tmp;
			}
		}
	}
}

void bfs(int ypos, int xpos) {

	if (ans_arr[ypos][xpos] == -1) {
		q.push({ ypos,xpos });
		ans_arr[ypos][xpos] = 0;
		ans++;
	}
	else {
		return;
	}

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int ny, nx;
		for (int i = 0; i < 8; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > N)
				continue;
			if (cnt[ny][nx] == 0 && ans_arr[ny][nx] == -1) {
				q.push({ ny,nx });
				ans_arr[ny][nx] = 0;
			}
			if (ans_arr[ny][nx] == -1) {
				ans_arr[ny][nx] = cnt[ny][nx];
			}
		}
	}
}

int main() {

	//freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		ans = 0;
		memset(arr, 0, sizeof(arr));
		memset(cnt, -1, sizeof(cnt));
		memset(ans_arr, -1, sizeof(ans_arr));
		v.clear();
		scanf("%d", &N);
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				scanf(" %1c", &arr[i][j]);
			}
		}
		get_arr();
		//show();

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (cnt[i][j] == 0)
					v.push_back({ i,j });
			}
		}
		for (int i = 0; i < v.size(); i++) {
			bfs(v.at(i).first, v.at(i).second);
		}

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (ans_arr[i][j] == -1)
					ans++;
			}
		}

		printf("#%d %d\n", t, ans);
	}


	return 0;
}