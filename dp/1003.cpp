#include<iostream>

using namespace std;

int main() {
	int cnt, n;
	int dp[2][42];

	dp[0][0] = 1;
	dp[1][0] = 0;
	dp[0][1] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		dp[0][i] = dp[0][i-2] + dp[0][i - 1];
		dp[1][i] = dp[1][i - 2] + dp[1][i - 1];
	}

	scanf_s("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		scanf_s("%d", &n);
		printf("%d %d\n", dp[0][n], dp[1][n]);
	}

	return 0;
}