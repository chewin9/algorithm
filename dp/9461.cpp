#include<iostream>

using namespace std;

int main() {
	int n;
	long long dp[102];
	int cnt;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (int i = 6; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];
	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}

	return 0;
}