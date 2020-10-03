#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string.h>

using namespace std;
typedef pair<int, int> pii;

vector<pii> test;
int T, N;
int arr[22][22];
bool eat[102];
int ans = 0;
int Sy, Sx;
const int dy[] = { 1,1,-1,-1 };
const int dx[] = { -1,1,1,-1 };

void dfs(int ypos, int xpos, int cnt, int dir) {
	
	
	eat[arr[ypos][xpos]] = true;

	if (ypos == Sy && xpos == Sx && cnt > 3) {
	/*	for (int i = 0; i < test.size(); i++)
			printf("{%d %d}: %d  ->", test.at(i).first, test.at(i).second, arr[test.at(i).first][test.at(i).second]);
		printf("\n");*/
		ans = max(cnt-1, ans);
		//eat[arr[ypos][xpos]] = false;

		return;
	}
	
	for (int i = dir; i < 4; i++) {
		int ny = ypos + dy[i];
		int nx = xpos + dx[i];

		if (ny <= Sy-1 || ny > N || nx <= 0 || nx > N)		//시작점보다 위에껀 체크 안해도댐
			continue;
		if (ny == Sy && nx == Sx && cnt == 2)
			continue;
		if (eat[arr[ny][nx]] == false) {
			test.push_back({ ny,nx });
			dfs(ny, nx, cnt + 1,i);
			test.pop_back();
			eat[arr[ny][nx]] = false;
		}
		if (ny == Sy && nx == Sx) {
			dfs(ny, nx, cnt + 1,i);
		}
	}

}
int main() {

	freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		memset(arr, 0, sizeof(arr));
		memset(eat, false, sizeof(eat));
		ans = 0;
		scanf("%d", &N);
		for (int i = 1; i < N + 1; i++)
			for (int j = 1; j < N + 1; j++)
				scanf("%d", &arr[i][j]);

		for (int i = 1; i < N; i++) {
			for (int j = 2; j < N + 1; j++) {
				memset(eat, false, sizeof(eat));
				Sy = i;
				Sx = j;
				test.push_back({ i,j });
				dfs(i, j, 1, 0);
				test.pop_back();
			}
		}
		if (ans == 0)
			printf("#%d -1\n", t);
		else
			printf("#%d %d\n", t, ans);

	}



	return 0;
}