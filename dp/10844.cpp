#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define INF 1000000000
int main() {
	int n;
	int dp[102][10];
	long long ans = 0;
	scanf("%d", &n);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;
	dp[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j - 1 >= 0)
				dp[i][j] += dp[i - 1][j - 1];
			if (j + 1 <= 9)
				dp[i][j] += dp[i - 1][j + 1];

			dp[i][j] %= INF;
		}
	}
	for (int i = 0; i < 10; i++)
		ans += dp[n][i];

	printf("%lli\n", ans%INF);

	return 0;
}