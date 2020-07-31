#include<iostream>
#include<string.h>

using namespace std;


int N, M;
int arr[2002];
int S, E;
int ans;
int dp[2002][2002];

int dfs(int start, int end) {
	if (dp[start][end] != -1)
		return dp[start][end];

	if (start >= end)
		return 1;

	if (arr[start] != arr[end])
		return 0;

	if (arr[start] == arr[end])
		dp[start][end] = dfs(start + 1, end - 1);
	
	return dp[start][end];
}

int main() {
	int ans;
	scanf("%d", &N);

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i < N + 1; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &M);

	for (int m = 0; m < M; m++) {
		scanf("%d %d", &S, &E);
		ans = dfs(S, E);
		printf("%d\n", ans);
	}

	return 0;
}