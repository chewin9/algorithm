#include<iostream>

using namespace std;

int main() {
	int N;
	int dp[1000002];

	scanf("%d", &N);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < 1000001; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	printf("%d\n", dp[N]);

	return 0;
}