#include<iostream>
#include<string.h>

using namespace std;

const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0 };

int dp[502][502];
int arr[502][502];
int N, M;

int dfs(int xpos, int ypos) {
	if (dp[xpos][ypos] != -1)
		return dp[xpos][ypos];
	
	if (xpos <= 0 || xpos > N || ypos <= 0 || ypos > M)
		return 0;
	if (xpos == N && ypos == M)
		return 1;

	dp[xpos][ypos] = 0;
	for (int i = 0; i < 4; i++) {
		if (arr[xpos + dx[i]][ypos + dy[i]] < arr[xpos][ypos])
			dp[xpos][ypos] += dfs(xpos + dx[i], ypos + dy[i]);
	}

	return dp[xpos][ypos];

}


int main() {
	int ans;
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			scanf("%d", &arr[i][j]);

	memset(dp, -1, sizeof(dp));

	ans = dfs(1, 1);

	printf("%d\n", ans);

	return 0;
}