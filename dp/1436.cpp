#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int dp[1000002];
	memset(dp, 0, sizeof(dp));

	dp[1] = 0;
	scanf_s("%d", &n);
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	printf("%d \n", dp[n]);

	return 0;
}