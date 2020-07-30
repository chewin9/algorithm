#include<iostream>
#include<string.h>

using namespace std;

int N;
int arr[102][102];
long long dp[102][102];

const int dy[] = { 1,0 };
const int dx[] = { 0,1 };

long long dfs(int ypos, int xpos) {
	if (dp[ypos][xpos] != -1)
		return dp[ypos][xpos];

	if (xpos <= 0 || xpos > N || ypos <= 0 || ypos > N)
		return 0;
	if (xpos == N && ypos == N)
		return 1;

	dp[ypos][xpos] = 0;
	int val = arr[ypos][xpos];
	for (int i = 0; i < 2; i++) {
		dp[ypos][xpos] += dfs(ypos + val*dy[i], xpos + val*dx[i]);
	}

	return dp[ypos][xpos];
}


int main() {
	long long ans;

	scanf("%d", &N);
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			scanf("%d", &arr[i][j]);

	memset(dp, -1, sizeof(dp));

	ans = dfs(1, 1);

	printf("%lli \n", ans);
	/*
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
	*/
	return 0;
}