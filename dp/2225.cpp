#include<iostream>
#include<string.h>

using namespace std;

#define INF 1000000000;

int N, K;
long long dp[202][202];

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i < N + 1; i++) {
		dp[i][0] = 0;
		dp[0][i] = 1;
	}
	dp[0][0] = 0;

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < K + 1; j++) {
			for (int k = 0; k < j + 1; k++) {
				dp[i][j] += dp[i - 1][j - k];
			}
			dp[i][j] %= INF;
		}
	}
	printf("%d\n", dp[N][K]);

	return 0;
}