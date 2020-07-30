#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int cnt;
	int n;
	int arr[3][100002];
	int dp[3][100002];
	int test;

	scanf("%d", &test);

	for (int t = 0; t < test; t++) {

		int ans = -1e9;

		scanf("%d", &n);

		for (int i = 1; i < 3; i++)
			for (int j = 1; j < n + 1; j++)
				scanf("%d", &arr[i][j]);

		dp[1][0] = 0;
		dp[2][0] = 0;
		dp[1][1] = arr[1][1];
		dp[2][1] = arr[2][1];

		for (int i = 2; i < n + 1; i++) {
			dp[1][i] = max(dp[2][i - 1], dp[2][i - 2]) + arr[1][i];
			dp[2][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[2][i];
		}

		ans = max(dp[1][n], dp[2][n]);

		printf("%d\n", ans);
	}

	return 0;
}