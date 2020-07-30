#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	long long dp[92];
	scanf("%d", &n);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	printf("%lli\n", dp[n]);
	


	return 0;
}