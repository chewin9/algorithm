#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
typedef pair<int, int > pii;
typedef pair<pii, int> ppi;
vector<ppi> v;
char arr[102][102];
int dp[102][102][82];
int N, M, K;
string str;
int ans = 0;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int dfs(int ypos, int xpos, int cnt) {
	if (dp[ypos][xpos][cnt] != -1) {
		return dp[ypos][xpos][cnt];
	}
	if (cnt == str.size())
		return 1;

	dp[ypos][xpos][cnt] = 0;
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < K + 1; j++) {
			ny = ypos + dy[i] * j;
			nx = xpos + dx[i] * j;

			if (ny <= 0 || ny > N || nx <= 0 || nx > M)
				continue;

			if (arr[ny][nx] == str.at(cnt)) {
				dp[ypos][xpos][cnt] += dfs(ny, nx, cnt + 1);
			}
		}
	}
	return dp[ypos][xpos][cnt];
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf(" %1c", &arr[i][j]);
		}
	}
	
	cin >> str;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (arr[i][j] == str.at(0)) {
				//v.push_back({ {i,j},0 });
				ans += dfs(i, j, 1);
				//v.pop_back();
			}
		}
	}
	//printf("%d\n", dp[3][2][1]);
	printf("%d\n", ans);
	return 0;

}