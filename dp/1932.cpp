#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int main() {
	int arr[501][501];
	int dp[501][501];
	int n;
	int ans = -1e9;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	memset(dp, 0, sizeof(dp));

	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[n][i]);

	printf("%d\n", ans);

	return 0;
}