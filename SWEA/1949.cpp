#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;


typedef pair<int, int> pii;
vector<pii> v;
int ans = -1e9;
int T, N, K;
int arr[10][10][2];
bool visit[10][10];
vector <pii> test;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void dfs(int ypos, int xpos, int cnt, int dig) {
	visit[ypos][xpos] = true;

	//ans = max(ans, cnt);
	if (ans < cnt)
		ans = cnt;
	/*if (ans == cnt) {
		printf("%d= ", cnt);
		for (int i = 0; i < test.size(); i++) {
			printf("{%d %d} ->", test.at(i).first, test.at(i).second);
		}
		printf("\n");
	}*/

	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = ypos + dy[i];
		nx = xpos + dx[i];

		if (ny <= 0 || ny > N || nx <= 0 || nx > N)				//¹üÀ§ ¹Û
			continue;
		if (arr[ypos][xpos][dig] > arr[ny][nx][dig] && visit[ny][nx] == false) {	//¾È±ï°í ³»·Á°¥¼ö ÀÕÀ½
			test.push_back({ ny,nx });
			dfs(ny, nx, cnt + 1, dig);
			test.pop_back();
			visit[ny][nx] = false;
		}
		if (arr[ypos][xpos][dig] <= arr[ny][nx][dig] && dig ==0 && visit[ny][nx] == false) {	//±ï¾Æ¾ßÇÔ
			int tmp = arr[ny][nx][dig] - arr[ypos][xpos][dig];
			if (tmp < K) {							// ±ïÀ»¼ö ÀÕÀ½
				
				for (int j = 1; j < K - tmp+1; j++) {
					arr[ny][nx][1] = arr[ny][nx][0] - tmp - j;
					test.push_back({ ny,nx });
					dfs(ny, nx, cnt + 1, 1);
					test.pop_back();
					arr[ny][nx][1] = arr[ny][nx][0];
					visit[ny][nx] = false;
				}
			}
		}
	}
}

int main() {

	freopen("sample_input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {

		memset(arr, 0, sizeof(arr));
		ans = -1e9;
		int tmp = -1e9;
		v.clear();
		scanf("%d %d", &N, &K);
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				scanf("%d", &arr[i][j][0]);
				arr[i][j][1] = arr[i][j][0];
				tmp = max(tmp, arr[i][j][0]);
			}
		}

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (tmp == arr[i][j][0]) {
					v.push_back({ i,j });
				}
			}
		}
	
		for (int i = 0; i < v.size(); i++) {
			memset(visit, false, sizeof(visit));
			test.push_back({ v.at(i).first, v.at(i).second });
			dfs(v.at(i).first, v.at(i).second, 1,0);
			test.pop_back();
		}

		printf("#%d %d\n", t, ans);
	}



	return 0;
}