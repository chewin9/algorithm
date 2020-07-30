#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int main() {
	int N, M, K, a, b, c, d;
	int arr[302][302];
	int dp[302][302];
	int ans;
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			scanf("%d", &arr[i][j]);

	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + arr[i][j];

	scanf("%d", &K);

	for (int k = 0; k < K; k++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		ans = dp[c][d] - (dp[a - 1][d] + dp[c][b - 1] - dp[a - 1][b - 1]);
		printf("%d\n", ans);

	}



	return 0;
}